#pragma once
#include "std_lib_facilities.h"

// Function that returns accelearation upwards (y-axis)
double acclY( void );

// Function that returns the speed upward (y-axis) 
// and takes the initial velocity and time
double velY ( double initVelocityY, double time );

// Function that returns position in x direction 
// and takes initial position, initial velocity and time
double posX ( double initPosition, double initVelocity, double time );

// Function that returns position in y direction 
// and takes initial position, initial velocity and time
double posY ( double initPosition, double initVelocity, double time );

// Function that prints time and takes time in seconds
void printTime ( double sec );

// Function that returns time of flight in seconds
// and takes initial velocity i y-direction
double flightTime ( double initVelocityY );

// Ber brukeren om en vinkel
double getUserInputTheta();

//Ber brukeren om en absoluttfart
double getUserInputAbsVelocity();

// Konverterer fra grader til radianer
double degToRad(double deg);

// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);

// Dekomponerer farten gitt av absVelocity, i x- og y-komponentene
// gitt vinkelen theta. Det første elementet i vectoren skal være
//x-komponenten, og det andre elementet skal være y-komponenten.
// "Vector" i funksjonsnavnet er vektor-begrepet i geometri
vector<double> getVelocityVector(double theta, double absVelocity);

//Returns the horizontal distance the canonball flew before it hit the ground (position in the x-direction when y = 0)
double getDistanceTraveled(double velocityX, double velocityY);

//Returns the difference between distanceToTarget and where the ball landed (x position) in meters
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

bool checkIfDistanceToTargetIsCorrect( void );