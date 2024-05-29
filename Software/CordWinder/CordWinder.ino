/* 
 *  Control program for the Cord Winder
 *  Arduino Uno
 *  
 *  Adrian Bowyer
 *  RepRap Ltd
 *  
 *  9 July 2017
 */

const int ledPin =  13;

// Motor pins

const int motorPlus = 3;
const int motorMinus = 4;
const int sensorSwitch = 2;
const int lightSensor = 5;
const int upSwitch = 6;
const int downSwitch = 7;

// For the motor

const int pwm = 100;

// Status of the device

bool doorClosed = true;
bool openAtDawn = false;


// Turn the motors off

void Stop()
{
  digitalWrite(motorPlus, 1);
  digitalWrite(motorMinus, 1);
  if(ledPin >= 0) digitalWrite(ledPin, 0);
}


// Run the motor to drop the door

void Close()
{
  digitalWrite(motorMinus, 0);
  analogWrite(motorPlus, pwm);
  if(ledPin >= 0) digitalWrite(ledPin, 1);
}


// Run the motor to raise the door

void Open()
{
  if(digitalRead(sensorSwitch))
  {
    Stop();
    return;
  }
  analogWrite(motorPlus, pwm);
  digitalWrite(motorMinus, 1);
  if(ledPin >= 0) digitalWrite(ledPin, 1);
}


// Initialisation

void setup() 
{
  // If we have a LED, allow it to be used

  if(ledPin >= 0) pinMode(ledPin, OUTPUT);

  // Motor pins are output.

  pinMode(motorPlus, OUTPUT);
  pinMode(motorMinus, OUTPUT);
  Stop();

  pinMode(sensorSwitch, INPUT);
  digitalWrite(sensorSwitch,1);
  pinMode(upSwitch, INPUT);
  digitalWrite(upSwitch,1);
  pinMode(downSwitch, INPUT);
  digitalWrite(downSwitch,1);
  pinMode(lightSensor, INPUT);
  doorClosed = true;
  openAtDawn = false;
}


void loop() 
{
  if(!digitalRead(upSwitch))
  {
    while(!digitalRead(sensorSwitch)) Open();
    doorClosed = false;
  }
  
  if(!digitalRead(downSwitch))
  {
    Close();
  } else
  {
    Stop();
    doorClosed = true;
  }
    
  if(!digitalRead(lightSensor) && doorClosed && openAtDawn)
  {
    while(!digitalRead(sensorSwitch))Open();
    doorClosed = false;
    openAtDawn = false;
  }
  
  if(digitalRead(lightSensor))
    openAtDawn = true;
}

