#ifndef H_SMITHCOUTER_H
#define	H_SMITHCOUTER_H

#include<iostream>
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
    void incrementState();
    //state can not get below 0;
    void decrementState();
    //if state is in 10 and 11, prediction is taken, if not, prediction is not taken.
    bool getPrediction();

    void updateState(bool taken);
};

#endif
