#include <RgbLed.h>

#ifndef HAKKUINO_RWAIT_H
#define HAKKUINO_RWAIT_H

class RWait: public RgbLedAnimationStep
{
  public:
  RWait(unsigned int duration);
  void run(RgbLed* animation);
};

#endif