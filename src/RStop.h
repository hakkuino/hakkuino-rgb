#include <RgbLed.h>

#ifndef HAKKUINO_RSTOP_H
#define HAKKUINO_RSTOP_H

class RStop: public RgbLedAnimationStep
{
  public:
  RStop(unsigned int start);
  boolean isActive(RgbLed* animation);
  void run(RgbLed* animation);
};

#endif