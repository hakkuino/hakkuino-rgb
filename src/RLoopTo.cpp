#include <RLoopTo.h>

RLoopTo::RLoopTo(unsigned int start, unsigned int restartAt, int occurences) : RgbLedAnimationStep(start)
{
  this->_restartAt = restartAt;
  this->_occurences = occurences;
}
boolean RLoopTo::isActive(RgbLed* animation)
{
  return (animation->_currentTime >= this->_start) && this->_occurences != 0;
}
void RLoopTo::run(RgbLed* animation)
{
  if (this->_occurences > 0)
  {
    animation->_currentTime = this->_restartAt;
    this->_occurences--;
  }
  else if (this->_occurences == -1)
  {
    animation->_currentTime = this->_restartAt;
  }
}
