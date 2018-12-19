#include <RFadeTo.h>

RFadeTo::RFadeTo(unsigned int start, Color newColor) : RgbLedAnimationStep(start)
{
  this->_newColor = newColor;
  this->_initialized=false;
}
void RFadeTo::run(RgbLed* animation)
{
  if (!this->_initialized)
  {
    this->_sourceColor = animation->_currentColor;
    this->_initialized=true;
  }
  float f=(float)(animation->_currentTime-this->_start)/(float)this->_duration;
  byte r = this->_sourceColor.getR() + (int)((this->_newColor.getR()-this->_sourceColor.getR())*f);
  byte g = this->_sourceColor.getG() + (int)((this->_newColor.getG()-this->_sourceColor.getG())*f);
  byte b = this->_sourceColor.getB() + (int)((this->_newColor.getB()-this->_sourceColor.getB())*f);
    
  Color c = Color(r,g,b);
  animation->setColor(c);
}
