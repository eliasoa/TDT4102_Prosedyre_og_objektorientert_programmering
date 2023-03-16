#include "std_lib_facilities.h"
#include "cannonball.h"

double acclY ( void ){
    // g = -9.81 m/s^2
    return -9.81;   
}

double velY ( double initVelocityY, double time ){
    // FartY = StartFartY + AkselerasjonY * Tid
    return initVelocityY + acclY()*time;
}

double posX( double initPosition, double initVelocity, double time ){
    // Posisjon = StartPosisjon + StartFart · Tid + (Akselerasjon * Tid ^2)2
    // Alselerasjon i x-retning = 0 m/s^2
    return initPosition + initVelocity*time;
}

double posY( double initPosition, double initVelocity, double time ){
    // Posisjon = StartPosisjon + StartFart · Tid + (Akselerasjon * Tid ^2)2
    // Alselerasjon i x-retning = 0 m/s^2
    return initPosition + initVelocity*time + acclY()*time*time/2;
}

void printTime( double sec ){
    double seconds = fmod(sec,60);
    double total_minutes = sec/60;
    double hours = total_minutes/60;
    double minutes = fmod(total_minutes,60);
    cout << hours << " timer " << minutes << ", minutter og " << seconds << " sekunder" << endl;
}

double flightTime ( double initVelocityY ){
    //Tid = − 2 * StartFartY/AkselerasjonY
    return -2*initVelocityY/acclY();
}


double getUserInputTheta( void ){
    double theta = 0.0;
    cout << "Skriv inn vinkel Theta: " << endl;
    cin >> theta;
    return theta;
}


double getUserInputAbsVelocity( void ) {
    double AbsVelocity = 0.0;
    cout << "Skriv inn en absoulutt hastighet: " << endl;
    cin >> AbsVelocity;
    return AbsVelocity;
}

double degToRad( double deg ) {
    return (deg * 3.14) / 180;
}

double getVelocityX(double theta, double absVelocity) {
    double thetaInRad = degToRad(theta);
    return absVelocity * cos(thetaInRad);
}

double getVelocityY(double theta, double absVelocity){
    double thetaInRad = degToRad(theta);
    return absVelocity * sin(thetaInRad);
}

vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velocityVector(2);
    velocityVector.at(0) = getVelocityX(theta, absVelocity);
    velocityVector.at(1) = getVelocityY(theta, absVelocity);
    return velocityVector;
}

double getDistanceTraveled(double velocityX, double velocityY){
    double timeInAir = flightTime(velocityY);
    double positionX = posX(0,velocityX,timeInAir);
    return positionX;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY){
    double distanceTraveled = getDistanceTraveled(velocityX, velocityY);
    return distanceTraveled-distanceToTarget;
}

bool checkIfDistanceToTargetIsCorrect() {
double error = targetPractice(100,0,0);
if(error == 0) return true;
else return false;
}
