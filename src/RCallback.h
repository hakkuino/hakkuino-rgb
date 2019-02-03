#include <RgbLed.h>

#ifndef HAKKUINO_RCALLBACK_H
#define HAKKUINO_RCALLBACK_H

class RCallback: public RgbLedAnimationStep
{
  private:
  void (*_callback)();
  boolean _called;
  public:
  RCallback(void (*callback)());
  void run(RgbLed* animation);
  boolean isActive(RgbLed* animation);
};

#endif