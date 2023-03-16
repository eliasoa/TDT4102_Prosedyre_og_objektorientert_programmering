#include "cannonball.hpp"
#include "utilities.hpp"
#include "std_lib_facilities.h"

/* 
Function that checks if two doubles are equal, within a error threshold
 using the formula |compareOperand-toOperand| ≤ maxError 
*/
void testDeviation(double compareOperand, double toOperand, double maxError, string name);


int main() {
    playTargetPractice();
    return 0;
}


void testDeviation ( double compareOperand, double toOperand, double maxError, string name ){
    if ( abs(compareOperand-toOperand) <= maxError)
    {
        cout << name << "is valid\n" << endl;
    }
    else
    {
        cout << name << "is not valid, expected " << toOperand << " got " << compareOperand << endl;
    }
}
/* Teori
4e) Feilmedling: error: non-void function does not return a value in all control paths [-Werror,-Wreturn-type]
checkIfDistanceToTargetIsCorrect er definert til å returnere en bool, men den vil kun returnere noe hvis (error == 0). 
Dermed vil ikke kodne kjøre.
Bytter ut til targetPractice(100,0,0) -> samme feilmedding
Skjønner ikke helt poenge med denne oppgaven, fordi jeg fikk ingen warning, kun en error.
Fikk kompliert koden ved å legge til en else return false;
*/
