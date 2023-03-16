#include "includes.hpp"

int main(){
    char userInput;
    while (true)
    {   
        BlackJack b;
        b.playGame();
        cout << "Play another round?\ny/n" << endl;
        cin >> userInput;
        if (userInput == 'n')
        {
            break;
        }
    }
    return 0;
}
/* Teori
Oppgave 1e)
To fordeler ved å bruke symboler fremfor f.eks. heltall og strenger
-   Universalt
-   Enklere å se symboler istendefor farge gitt som tall etc
*/
