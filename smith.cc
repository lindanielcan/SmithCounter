//Roughly write out the project structure. Algorithms will be imported later.
// I got a good reference from https://web.njit.edu/~rlopes/Mod5.3.pdf
// Find project from this site http://kaschueller.people.ysu.edu/classes/s2020/5814/Branch_Prediction/branchProg.html



#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Smith counter.
class SmithCounter{
  private:
    int prediction;
    // four states.
    // 00 strongly not taken
    // 01 weakly taken
    // 10 weakly taken
    // 11 strongly taken
    // one bit for prediction bit, second bit for conviction bit.
    int state = 3;
  public:

    //state can not exceed 3;
    void incrementState(){
      state++;
      if(state > 3 ) state = 3;
    }
    //state can not get below 0;
    void decrementState(){
      state--;
      if(state < 0) state = 0;
    }
    //if state is in 10 and 11, prediction is taken, if not, prediction is not taken.
    bool getPrediction(){
      if (state > 1) {prediction = true;}
      else{prediction = false;}
      return prediction;
    }

    void updateState(bool taken){
      if(taken){
        incrementState();
      }else{
        decrementState();
      }
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
    void updateNumOfBranch(){
      numOfBranch++;
    }
    int getnumOfBranch(){
      return numOfBranch;
    }
    void updateNumOfBranchTaken(){
      numOfBranchTaken++;
    }
    int getnumOfBranchTaken(){
      return numOfBranchTaken;
    }
    void updateNumOfCorrectlyPredictTakenBranch(){
      numOfCorrectPredictTakenBranch++;
    }
    int getnumOfCorrectlyPredictTakenBranch(){
      return numOfCorrectPredictTakenBranch;
    }
    void updateNumOfBranchNotTaken(){
      numOfBranchNotTaken++;
    }
    int getnumOfBranchNotTaken(){
      return numOfBranchNotTaken;
    }
    void updateNumOfCorrectlyPredictNotTakenBranch(){
      numOfCorrectPredictNotTakenBranch++;
    }
    int getnumOfCorrectlyPredictNotTakenBranch(){
      return numOfCorrectPredictNotTakenBranch;
    }
    int calcOverAllRate(){
      correctPredictionRate = ((double)(numOfCorrectPredictTakenBranch + numOfCorrectPredictNotTakenBranch) / (double)numOfBranch) * 100;
      return correctPredictionRate;
    }
};


int main(int argc, char* argv[]) {

  SmithCounter S1;
  BranchTracker B1;
  string someNumber;
  string branch;
  int b_ins;
  bool state;
  bool Taken;

   ifstream file("branch_trace.dat");
  //
  //
   while(getline(file, someNumber, ' ')) {
        getline(file, branch, '\n');

        if(branch == "T"){Taken = true;}
        else{Taken = false;}

        S1.updateState(Taken);

        // updates the number of Taken branch counter.
        if(branch.find('T') != std::string::npos){
          B1.updateNumOfBranchTaken();
        }
        // updates the number of not taken branch counter.
        if(branch.find('N') != std::string::npos){
          B1.updateNumOfBranchNotTaken();
        }

        if(S1.getPrediction() && Taken){
          B1.updateNumOfCorrectlyPredictTakenBranch();
        }
        if(!S1.getPrediction() && !Taken){
          B1.updateNumOfCorrectlyPredictNotTakenBranch();
        }
        // updates the number of not taken branch counter.
      B1.updateNumOfBranch();
      }

   file.close();



  cout << "Number of branches: " << B1.getnumOfBranch() << endl;
  cout << "Number of branches taken: " << B1.getnumOfBranchTaken() << endl;
  cout << "Number taken branches correctly predicted: " << B1.getnumOfCorrectlyPredictTakenBranch() << endl;
  cout << "Number of branches not taken: " << B1.getnumOfBranchNotTaken() << endl;
  cout << "Number not taken branches correctly predicted: " << B1.getnumOfCorrectlyPredictNotTakenBranch() <<endl << endl;
  cout << "Overall rate of correct predictions: " << B1.calcOverAllRate() << "%" << endl;
  return 0;
}
