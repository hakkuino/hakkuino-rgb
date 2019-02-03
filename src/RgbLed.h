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
  friend class RgbLed;
  unsigned int _duration;
  unsigned int _start;
  RgbLedAnimationStep(unsigned int duration);
  virtual boolean isActive(RgbLed* animation);
  virtual void run(RgbLed* animation) = 0;
  void setDuration(unsigned int duration);
  void setStart(unsigned int start);
  unsigned int getStart();
  unsigned int getDuration();
  void ensureFinalState(RgbLed* animation);
};

class RgbLed
{
private:
  RgbLedAnimationStep** _steps;
  byte _stepsNb;
  byte _currentStepIndex;
  boolean _isActive;
  byte _pinR;
  byte _pinG;
  byte _pinB;
  unsigned long _previousMillis;
  float _brightness;
  Color _calibration;
public:
  friend class RgbLedAnimationStep;
  Color _currentColor;
  unsigned long _currentTime;
  void setColor(Color color);
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
  void ensureLastAnimationStepState();
};

#endif