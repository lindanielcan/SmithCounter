#include"branchtracker.h"
    //A bunch setter and getter functions
void BranchTracker::updateNumOfBranch(){
  numOfBranch++;
}

int BranchTracker::getnumOfBranch(){
  return numOfBranch;
}

void BranchTracker::updateNumOfBranchTaken(){
  numOfBranchTaken++;
}

int BranchTracker::getnumOfBranchTaken(){
  return numOfBranchTaken;
}

void BranchTracker::updateNumOfCorrectlyPredictTakenBranch(){
  numOfCorrectPredictTakenBranch++;
}

int BranchTracker::getnumOfCorrectlyPredictTakenBranch(){
  return numOfCorrectPredictTakenBranch;
}

void BranchTracker::updateNumOfBranchNotTaken(){
  numOfBranchNotTaken++;
}

int BranchTracker::getnumOfBranchNotTaken(){
  return numOfBranchNotTaken;
}

void BranchTracker::updateNumOfCorrectlyPredictNotTakenBranch(){
  numOfCorrectPredictNotTakenBranch++;
}

int BranchTracker::getnumOfCorrectlyPredictNotTakenBranch(){
  return numOfCorrectPredictNotTakenBranch;
}

double BranchTracker::calcOverAllRate(){
  correctPredictionRate = ((double)(numOfCorrectPredictTakenBranch + numOfCorrectPredictNotTakenBranch) / (double)numOfBranch) * 100;
  return correctPredictionRate;
}
