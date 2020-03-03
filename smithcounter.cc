#include "SmithCounter.h"

//if state is in 10 and 11, prediction is taken, if not, prediction is not taken.
int SmithCounter::getPrediction(){
  //11 >> 1 = 1
  //10 >> 1 = 1
  //01 >> 1 = 0
  //00 >> 1 = 0
  return prediction >> 1;
}

void SmithCounter::setPrediction(){
  prediction = 0;
}

void SmithCounter::updatePrediction(bool taken){
  if(taken){
    prediction++;
    if(prediction > 3) prediction = 3;
  }
  if (!taken && prediction > 0){
    prediction--;
    if(prediction < 0){
      prediction = 0;
    }
  }
}
