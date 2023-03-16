#include "utilities.hpp"
#include "tests.hpp"
#include "mastermind.hpp"
#include "masterVisual.hpp"

int main() {
    playMastermind();
    // playMastermindVisual();
    return 0;
}

/* Teorispørsmål
Oppgave 1:
a) Kodeforståelse
After 10 iterations: v0 = 25
e) Pass by reference is the preferable way to do it, as pass-by-value would need to
return a vector, making the funciton cumbersome, pass-by-const-ref wont let the function
change the arguments, making the function useless.
Oppgave 2:
e) Oppgave om feilmelding
The order of the includes is wrong???
*/