#include <RgbLed.h>

#ifndef HAKKUINO_RWAIT_H
#define HAKKUINO_RWAIT_H

class RWait: public RgbLedAnimationStep
{
  public:
  RWait(unsigned int start);
  void run(RgbLed* animation);
};

#endif