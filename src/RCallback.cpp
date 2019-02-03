#include <RCallback.h>

RCallback::RCallback(void (*callback)()) : RgbLedAnimationStep(0)
{
  this->_callback = callback;
  this->_called = false;
}
boolean RCallback::isActive(RgbLed* animation)
{
  return (!this->_called) && (animation->_currentTime >= this->_start);
}
void RCallback::run(RgbLed* animation)
{
  this->_callback();
  this->_called = true;
}