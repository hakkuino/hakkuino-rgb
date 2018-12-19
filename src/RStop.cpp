#include <RStop.h>

RStop::RStop(unsigned int start) : RgbLedAnimationStep(start)
{
  
}
boolean RStop::isActive(RgbLed* animation)
{
  return (animation->_currentTime >= this->_start);
}
void RStop::run(RgbLed* animation)
{
  animation->stopAnimation();
}