#include <RSetTo.h>


RSetTo::RSetTo(unsigned int start, Color newColor) : RgbLedAnimationStep(start)
{
  this->_newColor=newColor;
}
void RSetTo::run(RgbLed* animation)
{
  animation->setColor(this->_newColor);
}
