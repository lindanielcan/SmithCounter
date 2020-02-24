

// Used to keep track of branches and states.
class BranchTracker{
  private:
    int numOfBranch = 0;
    int numOfBranchTaken = 0;
    int numOfCorrectPredictTakenBranch = 0;
    int numOfBranchNotTaken = 0;
    int numOfCorrectPredictNotTakenBranch = 0;
    double correctPredictionRate = 0;

  public:
    //A bunch setter and getter functions
    void updateNumOfBranch();
    int getnumOfBranch();
    void updateNumOfBranchTaken();
    int getnumOfBranchTaken();
    void updateNumOfCorrectlyPredictTakenBranch();
    int getnumOfCorrectlyPredictTakenBranch();
    void updateNumOfBranchNotTaken();
    int getnumOfBranchNotTaken();
    void updateNumOfCorrectlyPredictNotTakenBranch();
    int getnumOfCorrectlyPredictNotTakenBranch();
    double calcOverAllRate();
};
