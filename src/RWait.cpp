#include <RWait.h>

RWait::RWait(unsigned int duration) : RgbLedAnimationStep(duration)
{
  
}
void RWait::run(RgbLed* animation)
{
  //Do nothing
  animation->ensureLastAnimationStepState();
}
