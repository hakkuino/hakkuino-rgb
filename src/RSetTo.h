#include <RgbLed.h>

#ifndef HAKKUINO_RSETTO_H
#define HAKKUINO_RSETTO_H

class RSetTo : public RgbLedAnimationStep
{
  private:
  Color _newColor;
  public:
  RSetTo(unsigned int duration, Color newColor);
  void run(RgbLed* animation);
};

#endif