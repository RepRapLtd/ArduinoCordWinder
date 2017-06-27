An Arduino-controlled cord winder for moving things.

(Original application - release chickens from their coop at dawn.)

This consists of a laser-cut box held together with 3D pronted parts.  Inside is a cylindrical winder driven by a geared motor.  These are controlled by an Arduino Uno with a shield that drives the motor.

As distributed it is powered by 12 volts, and takes an opto-isolated input from a solar cell (assumed also to be charging the 12 volt battery).  When the solar voltage rises above a threshold the winder runs until a marker on the wound cord triggers a microswitch, causing it to stop.

There are also push buttons to wind and unwind the cord manually.

