//Roughly write out the project structure. Algorithms will be imported later.
// I got a good reference from https://web.njit.edu/~rlopes/Mod5.3.pdf

// 00 strongly not taken
// 01 weakly taken
// 10 weakly taken
// 11 strongly taken

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Smith counter.
class SmithCounter{
  private:
    int prediction;
  public:
    int getPrediction(){
      prediction >> 1;
    }
};

// Used to keep track of branches.
class BranchTracker{
  private:
    int numOfBranch = 0;
    int numOfBranchTaken = 0;
    int numOfCorrectPredictTakenBranch = 0;
    int numOfBranchNotTaken = 0;
    int numOfCorrectPredictNotTakenBranch = 0;
    int correctPredictionRate = 0;
  public:
    //A bunch setter and getter functions
    void setnumOfBranch(){
      numOfBranch++;
    }
    int getnumOfBranch(){
      return numOfBranch;
    }
    void setnumOfBranchTaken(){
      numOfBranchTaken++;
    }
    int getnumOfBranchTaken(){
      return numOfBranchTaken;
    }
    void setnumOfCorrectPredictTakenBranch(){
      numOfCorrectPredictTakenBranch++;
    }
    int getnumOfCorrectPredictTakenBranch(){
      return numOfCorrectPredictTakenBranch;
    }
    void setnumOfBranchNotTaken(){
      numOfBranchNotTaken++;
    }
    int getnumOfBranchNotTaken(){
      return numOfBranchNotTaken;
    }
    void setnumOfCorrectPredictNotTakenBranch(){
      numOfCorrectPredictNotTakenBranch++;
    }
    int getnumOfCorrectPredictNotTakenBranch(){
      return numOfCorrectPredictNotTakenBranch;
    }
    int calcOverAllRate(){
      correctPredictionRate = ((numOfCorrectPredictTakenBranch + numOfCorrectPredictNotTakenBranch) / numOfBranch) * 100;
      return correctPredictionRate;
    }
};


int main(int argc, char* argv[]) {

  SmithCounter S1[128];
  BranchTracker B1;
  string branch;
  string state;
  int b_ins;
  bool prediction;
  bool predictionTaken;

  ifstream file("branch_trace.dat");


  while(getline(file, branch, ' ')) {

       getline(file, state, '\n');
       b_ins = atoi(branch.c_str());
       prediction = smith_array[(b_ins/4) % 128].getPrediction();
   }

  file.close();

  cout << "Number of branches: " << B1.getnumOfBranch() << endl;
  cout << "Number of branches taken: " << B1.getnumOfBranchTaken() << endl;
  cout << "Number taken branches correctly predicted: " << B1.getnumOfCorrectPredictTakenBranch() << endl;
  cout << "Number of branches not taken: " << B1.getnumOfBranchNotTaken() << endl;
  cout << "Number not taken branches correctly predicted: " << B1.getnumOfCorrectPredictNotTakenBranch() <<endl << endl;
  cout << "Overall rate of correct predictions: " << B1.calcOverAllRate() << "%" << endl;
  return 0;
}
