#include <RgbLed.h>

#ifndef HAKKUINO_RSTOP_H
#define HAKKUINO_RSTOP_H

class RStop: public RgbLedAnimationStep
{
  public:
  RStop();
  boolean isActive(RgbLed* animation);
  void run(RgbLed* animation);
};

#endif