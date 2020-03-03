#ifndef H_SMITHCOUNTER_H
#define	H_SMITHCOUNTER_H

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
  public:
    //if state is in 10 and 11, prediction is taken, if not, prediction is not taken.
    int getPrediction();
    void setPrediction();
    void updatePrediction(bool taken);
};

#endif
