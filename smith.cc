//Roughly write out the project structure. Algorithms will be imported later.
// I got a good reference from https://web.njit.edu/~rlopes/Mod5.3.pdf
// Find project from this site http://kaschueller.people.ysu.edu/classes/s2020/5814/Branch_Prediction/branchProg.html

#include <iostream>
#include <string>
#include <fstream>
#include "smithcounter.h"
#include "branchtracker.h"

void executionMyBranchCounter(BranchTracker B1, SmithCounter S1);

using namespace std;

int main(int argc, char* argv[]) {

  SmithCounter S2;
  BranchTracker B2;

  executionMyBranchCounter(B2,S2);


  return 0;
}

void executionMyBranchCounter(BranchTracker B1, SmithCounter S1){
  int someNumber;
  string line;
  string branch;
  bool Taken;
  bool prediction;

   ifstream file("branch_trace.dat");
  //
    //getline reads the file
   while(getline(file, line, ' ')) {
        getline(file, branch, '\n');

        if(branch == "T"){Taken = true;}
        else{Taken = false;}
        someNumber = atoi(line.c_str());
        //S1[someNumber%128].updateState(Taken);

        prediction = S1.getPrediction();

        // updates the number of Taken branch counter.
        if(branch.find('T') != std::string::npos){
          B1.updateNumOfBranchTaken();
        }
        // updates the number of not taken branch counter.
        if(branch.find('N') != std::string::npos){
          B1.updateNumOfBranchNotTaken();
        }

        if(prediction && Taken){
          S1.updateState(Taken);
          B1.updateNumOfCorrectlyPredictTakenBranch();
        }
        else if(!prediction && !Taken){
          S1.updateState(Taken);
          B1.updateNumOfCorrectlyPredictNotTakenBranch();
        }
        else if(prediction && !Taken){
          S1.updateState(Taken);
        }
        else if(!prediction && Taken){
          S1.updateState(Taken);
        }
        //updates the number of not taken branch counter.
      B1.updateNumOfBranch();
      }

   file.close();

  cout << "Number of branches: " << B1.getnumOfBranch() << endl;
  cout << "Number of branches taken: " << B1.getnumOfBranchTaken() << endl;
  cout << "Number taken branches correctly predicted: " << B1.getnumOfCorrectlyPredictTakenBranch() << endl;
  cout << "Number of branches not taken: " << B1.getnumOfBranchNotTaken() << endl;
  cout << "Number not taken branches correctly predicted: " << B1.getnumOfCorrectlyPredictNotTakenBranch() <<endl << endl;
  cout << "Overall rate of correct predictions: " << B1.calcOverAllRate() << "%" << endl;
}
