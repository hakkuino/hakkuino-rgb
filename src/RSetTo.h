#include <RgbLed.h>

#ifndef HAKKUINO_RSETTO_H
#define HAKKUINO_RSETTO_H

class RSetTo : public RgbLedAnimationStep
{
  private:
  Color _newColor;
  public:
  RSetTo(unsigned int start, Color newColor);
  void run(RgbLed* animation);
};

#endif