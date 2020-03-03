#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "branchtracker.h"
#include "SmithCounter.h"

using namespace std;

void execute(BranchTracker B1, SmithCounter *S1);

int main() {
  SmithCounter S2[128];
  BranchTracker B2;

  execute(B2, S2);

  return 0;
}

void execute(BranchTracker B1, SmithCounter *S1){
  string behavior, line;
  unsigned long long addr;
  bool taken;
  ifstream infile("branch_trace.dat");
  for(int i = 0; i < 128; i++) S1[i].setPrediction();
  while(getline(infile, line)) {
    stringstream s(line);
    s >> addr >> behavior;
    int index = addr % 128;
    int tval = S1[index].getPrediction();  // get prediction

    if(behavior == "N") {taken = false;}
    else {taken = true;}

    if(taken && tval == 1){
      S1[index].updatePrediction(taken);
      B1.updateNumOfBranchTaken();
      B1.updateNumOfCorrectlyPredictTakenBranch();
    }else if (taken && tval == 0){
      B1.updateNumOfBranchTaken();
      S1[index].updatePrediction(taken);
    }else if (!taken && tval == 0){
      S1[index].updatePrediction(taken);
      B1.updateNumOfBranchNotTaken();
      B1.updateNumOfCorrectlyPredictNotTakenBranch();
    }else if (!taken && tval == 1){
      B1.updateNumOfBranchNotTaken();
      S1[index].updatePrediction(taken);
    }

    B1.updateNumOfBranch();
  }

  infile.close();

  cout << "Number of branches: " << B1.getnumOfBranch() << endl;
  cout << "Number of branches taken: " << B1.getnumOfBranchTaken() << endl;
  cout << "Number taken branches correctly predicted: " << B1.getnumOfCorrectlyPredictTakenBranch() << endl;
  cout << "Number of branches not taken: " << B1.getnumOfBranchNotTaken() << endl;
  cout << "Number not taken branches correctly predicted: " << B1.getnumOfCorrectlyPredictNotTakenBranch()  <<endl << endl;
  cout << "Overall rate of correct predictions: " << B1.calcOverAllRate() << endl;
}
