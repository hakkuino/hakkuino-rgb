#include <RgbLed.h>

#ifndef HAKKUINO_RLOOPTO_H
#define HAKKUINO_RLOOPTO_H

class RLoopTo: public RgbLedAnimationStep
{
private:
  unsigned int _restartAt;
  int _occurences;  
public:
  RLoopTo(unsigned int restartAt, int occurences);
  boolean isActive(RgbLed* animation);
  void run(RgbLed* animation);
};

#endif