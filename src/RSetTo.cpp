#include <RSetTo.h>


RSetTo::RSetTo(unsigned int duration, Color newColor) : RgbLedAnimationStep(duration)
{
  this->_newColor=newColor;
}
void RSetTo::run(RgbLed* animation)
{
  animation->setColor(this->_newColor);
}
