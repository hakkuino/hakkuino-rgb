#include <RStop.h>

RStop::RStop() : RgbLedAnimationStep(0)
{
  
}
boolean RStop::isActive(RgbLed* animation)
{
  return (animation->_currentTime >= this->_start);
}
void RStop::run(RgbLed* animation)
{
  animation->ensureLastAnimationStepState();
  animation->stopAnimation();
}