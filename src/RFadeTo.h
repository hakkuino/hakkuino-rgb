#include <RgbLed.h>

#ifndef HAKKUINO_FADETO_H
#define HAKKUINO_FADETO_H

class RFadeTo : public RgbLedAnimationStep
{
  private:
  boolean _initialized;
  Color _sourceColor;
  Color _newColor;
  public:
  RFadeTo(unsigned int start, Color newColor);
  void run(RgbLed* animation);
};

#endif