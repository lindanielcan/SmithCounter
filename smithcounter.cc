#include "smithcounter.h"

//state can not exceed 3;
void SmithCounter::incrementState(){
  state++;
  if(state > 3 ) state = 0;
}

//state can not get below 0;
void SmithCounter::decrementState(){
  state--;
  if(state < 0) state = 0;
}

//if state is in 10 and 11, prediction is taken, if not, prediction is not taken.
bool SmithCounter::getPrediction(){
  if (state > 1) {prediction = true;}
  else{prediction = false;}
  return prediction;
}

void SmithCounter::updateState(bool taken){
  if(taken){
    incrementState();
  }
  else{
    decrementState();
  }
}
