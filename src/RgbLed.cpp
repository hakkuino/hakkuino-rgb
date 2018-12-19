#include <RgbLed.h>

RgbLed::RgbLed()
{
  this->_isActive = false;
  this->_stepsNb = 0;
  this->_brightness = 1;
  this->_calibration = Color(255,255,255);
}
RgbLed::~RgbLed()
{
  for(unsigned short i=0; i<this->_stepsNb; i++)
  {
    TRACE("Delete "+String(i));
    delete this->_steps[i];
  }
  delete this->_steps;
}
void RgbLed::setCalibration(Color c)
{
  DEBUG("Calibrate to " + c.toString());
  this->_calibration = c;
}

void RgbLed::setBrightness(float b)
{
  DEBUG("Set brightness to " + String(b));
  this->_brightness = b;
  if (!this->_isActive)
  {
    this->setColor(this->_currentColor);
  }
}
float RgbLed::getBrightness()
{
  return this->_brightness;
}
void RgbLed::init(byte pinR, byte pinG, byte pinB)
{
  this->_pinR = pinR;
  this->_pinG = pinG;
  this->_pinB = pinB;
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
  DEBUG("Initialize RgbLed on pins : " + String(pinR) + ", " + String(pinG) + ", " + String(pinB));
}
void RgbLed::setColor(Color color)
{
  DEBUG("Wanted color : " + color.toString());
  this->_currentColor = color;
//  byte r = (byte)(this->_brightness*(color.getR()*this->_calibration.getR()/255.0));
//  byte g = (byte)(this->_brightness*(color.getG()*this->_calibration.getG()/255.0));
//  byte b = (byte)(this->_brightness*(color.getB()*this->_calibration.getB()/255.0));
  byte r = (byte)(this->_brightness*color.getR());
  byte g = (byte)(this->_brightness*color.getG());
  byte b = (byte)(this->_brightness*color.getB());
  DEBUG("Set color : " + String(r) + ", " + String(g) + ", " + String(b));
  analogWrite(this->_pinR, r);
  analogWrite(this->_pinG, g);
  analogWrite(this->_pinB, b);
}
void RgbLed::runAnimation()
{
  if (!this->_isActive)
  {
    return;
  }
  this->_currentTime += millis() - this->_previousMillis;
  this->_previousMillis = millis();
  for(unsigned short i=0; i<this->_stepsNb; i++)
  {
    TRACE("Test for step " + String(i) + " - Millis : " + String(this->_currentTime));
    if (this->_steps[i]->isActive(this))
    {
      TRACE("Launch step " + String(i));
      this->_steps[i]->run(this);
      break;
    }
  }
}
void RgbLed::startAnimation()
{
  if (!this->_isActive)
  {
    this->_currentTime=0;
    this->_previousMillis=millis();
    this->_isActive=true;
    DEBUG("Start Animation");
  }
}
void RgbLed::stopAnimation()
{
  this->_isActive=false;
  DEBUG("Stop Animation");
}

boolean RgbLed::isActive()
{
  return this->_isActive;
}
void RgbLed::resumeAnimation()
{
  if (!this->_isActive)
  {
    this->_previousMillis=millis();
    this->_isActive=true;
    DEBUG("Resume Animation");
  }
}
void RgbLed::setAnimation(int arraySize, RgbLedAnimationStep* steps[])
{
  TRACE("Begins.");
  this->resetAnimation();
  TRACE("malloc : " + String(sizeof(steps)));
  this->_steps=(RgbLedAnimationStep**)malloc(arraySize*sizeof(RgbLedAnimationStep*));
  this->_stepsNb=arraySize;
  for(unsigned short i=0; i<arraySize;i++)
  {
    this->_steps[i] = (steps[i]);
    if(i<(arraySize-1))
    {
       this->_steps[i]->setDuration(steps[i+1]->getStart() - steps[i]->getStart());
    }
  }
 
}

void RgbLed::resetAnimation()
{
  for(unsigned short i=0; i<this->_stepsNb; i++)
  {
    TRACE("Delete "+String(i));
    delete this->_steps[i];
  }
  delete this->_steps;
}


RgbLedAnimationStep::RgbLedAnimationStep(unsigned int start)
{
  this->_start = start;
}
boolean RgbLedAnimationStep::isActive(RgbLed* animation)
{
  TRACE(String(this->_start) + " - " + String(this->_duration));
  return (animation->_currentTime >= this->_start) && (animation->_currentTime < (this->_start + this->_duration));
}
void RgbLedAnimationStep::setDuration(unsigned int duration)
{
  this->_duration = duration;
}
unsigned int RgbLedAnimationStep::getStart()
{
  return this->_start;
}