#include <stdint.h>
#include "Arduino.h"
#include "Color.h"
#include <Logger.h>

#ifndef HAKKUINO_RGBLED_H
#define HAKKUINO_RGBLED_H

class RgbLed;

class RgbLedAnimationStep{
protected:
public:
  unsigned int _duration;
  unsigned int _start;
  RgbLedAnimationStep(unsigned int start);
  virtual boolean isActive(RgbLed* animation);
  virtual void run(RgbLed* animation) = 0;
  void setDuration(unsigned int duration);
  unsigned int getStart();
};

class RgbLed
{
private:
  RgbLedAnimationStep** _steps;
  byte _stepsNb;
  boolean _isActive;
  byte _pinR;
  byte _pinG;
  byte _pinB;
  unsigned long _previousMillis;
  float _brightness;
  Color _calibration;
public:
  Color _currentColor;
  unsigned long _currentTime;
  void setColor(Color color);
  friend class RgbLedAnimationStep;

  RgbLed();
  ~RgbLed();
  void init(byte pinR, byte pinG, byte pinB);
  void runAnimation();
  void startAnimation();
  void stopAnimation();
  void resumeAnimation();
  void setAnimation(int arraySize, RgbLedAnimationStep** steps);
  void resetAnimation();
  void setBrightness(float b);
  float getBrightness();
  boolean isActive();
  void setCalibration(Color c);
};

#endif