#include "std_lib_facilities.h"
#include "AnimationWindow.h"

void inputIntegersAndPrintProduct() {
    int x = 0;
    int y = 0;
    cout << "Skriv inn to heltall: ";
    cin >> x;
    cin >> y;
    int product = x * y;
    cout << x << " * " << y << " = " << product << endl;
}

int add(int a, int b) {
return a + b;
}

void inputAndPrintInteger(){
    int a;
    cout << "Skriv inn et tall: " << endl;
    cin >> a;
    cout << "Du skrev: " << a << endl;
}

int inputInteger(){
    int a;
    cout << "Skriv inn et tall: " << endl;
    cin >> a;
    return a;
}

void inputIntegersAndPrintSum(){
    int number1 = inputInteger();
    int number2 = inputInteger();
    int sum = add(number1, number2);
    cout << "Summen av tallene: " << sum << "\n";
}

bool isOdd(int a){
    int modulo = a%2;
    if (modulo != 0)
    {
        return false;
    }
    else{
        return true;
    }
    
}

void printHumanReadableTime(int sec){
    
    int seconds = sec%60;
    int total_minutes = sec/60;
    int hours = total_minutes/60;
    int minutes = total_minutes%60;
    cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder \n";
}

void sumOfInputIntegers(void){
    int numberOfInts = 0;
    vector <int> vecOfInts = {};
    cout << "Skriv inn antall heltall som skal summeres: " << "\n";
    cin >> numberOfInts;
    int newInt = 0;
    for (int i = 0; i < numberOfInts; i++)
    {
        cout << "Skriv inn et heltall: " << "\n";
        cin >> newInt;
        vecOfInts.push_back(newInt);
    }
    cout<<"Summen av tallene er : \n";
    cout<<accumulate(vecOfInts.begin(),vecOfInts.end(),0);
}

void sumOfInputIntegersEndAtZero(void){
    vector <int> vecOfInts = {};
    int newInt = 1;
    while (newInt != 0)
    {
        cout << "Skriv inn et heltall: " << "\n";
        cin >> newInt;
        vecOfInts.push_back(newInt);
    }
    cout<<"Summen av tallene er : \n";
    cout<<accumulate(vecOfInts.begin(),vecOfInts.end(),0);
}

double inputDouble(void){
    double a;
    cin >> a;
    return a;
}

double konverterFraNOKtilEUR(void){
// La brukeren gi beløpet som skal konverteres som et positivt desimaltall. Vekslingskurs kan
// du bestemme selv, f.eks. 9.75. Hvis brukeren gir et negativt tall skal programmet spørre
// etter et nytt tall. Skriv ut det vekslede beløpet med to desimaler.
cout << "Skriv inn verdi i NOK for å få det i EUR: \n";
double NOK = inputDouble();
double kurs = 9.75;
while (NOK < 0)
{
    cout << "Tall kan ikke være mindre enn 0. Skriv inn nytt tall: \n";
    NOK = inputDouble();
}
    return NOK/kurs;
}

void printGangetabell(){
    int rader = 0;
    int kolonner = 0;
    cout << "Enter rows: \n";
    cin >> rader;
    cout << "Enter columns: \n";
    cin >> kolonner;
    for (int rad = 1; rad < kolonner+1; rad++)
    {
        for (int kolonne = 1; kolonne < kolonner + 1; kolonne++)
        {
            cout << rad*kolonne << "\t";
        }

        cout << endl;
    } 
}

double calculateDiscriminant(double a, double b, double c){
    return pow(b,2) - 4*a*c;
}

void printRealRoots(double a, double b, double c){
    double discriminant = calculateDiscriminant(a,b,c);
    if (discriminant < 0)
    {
        cout << "No real solutions :(\n";
    }
    else if (discriminant > 0)
    {
        double positiveX = (-b + sqrt(discriminant))/(2*a);
        double negativeX = (-b - sqrt(discriminant))/(2*a);
        cout << "The roots are: " << "x_1 = " << positiveX << " and x_2 = " << negativeX << "\n";
    }
    else if (discriminant == 0)
    {
        double x = -b/(2*a);
        cout << "The root are x = " << x << "\n";
    }
}

void solveQuadraticEquation(void){
    double a = 0;
    double b = 0;
    double c = 0;
    cout << "Skriv inn a: " << endl;
    cin >> a;
    cout << "Skriv inn b: " << endl;
    cin >> b;
    cout << "Skriv inn c: " << endl;
    cin >> c;
    printRealRoots(a,b,c);
}

void pythagoras(void){
    int w = 1000;
    int h = 1000;
    AnimationWindow win{100,100, w, h, "Pythagoras"};
    Point point1{350,350};
    Point point2{550,650};
    Point point3{350,650};
    win.draw_triangle(point1, point2, point3, Color::black);
    win.draw_quad(Point{50, 350}, Point{350, 350}, Point{350, 650}, Point{50, 650}, Color::green);
    win.draw_quad(Point{350, 650}, Point{550, 650}, Point{550, 850}, Point{350, 850}, Color::red);
    win.draw_quad(Point{350, 350}, Point{650, 150}, Point{850, 450}, Point{550, 650}, Color::blue);

    
    win.wait_for_close();
}

vector<int> calculateBalance(int innskudd, int rente, int antallAar){
    vector<int> saldo(antallAar);
    for (int i = 0; i < antallAar; i++)
    {
        int ye = innskudd * pow((1 + static_cast<double>(rente)/100),i);
        saldo.at(i) = ye;
    }
    return saldo;
}

void printBalance(vector<int> saldo){
    cout << "Aar\tSaldo\n";
    for (int i = 0; i < saldo.size(); i++)
    {
        cout << i << "\t" << saldo.at(i) << endl;
    }
}

int main() {
    bool terminate = false;     // boolean used to terminate the program
    int number;
    while (terminate == false)
    {
        int user_input;         // int storing what function the user want to use
        cout << "Velg funksjon:\n0) Avslutt\n1) inputAndPrintInteger\n2) inputInteger\n3) inputIntegersAndPrintSum\n4) isOdd\n5) printHumanReadableTime\n6) sumOfInputIntegers\n7) sumOfInputIntegersEndAtZero\n8) konverterFraNOKtilEUR\n9) printGangetabell\n10) solveQuadraticEquation\n11) pythagoras\n12) calculateBalance\nAngi valg (0-12):" << endl;
        cin >> user_input;
        switch (user_input)
        {
        case 0: //Terminate program
            terminate = true;
            cout << "Avslutter xDDDDDD" << endl;
            break;
        case 1: 
            inputAndPrintInteger();
            break;
        case 2:
            number = inputInteger();
            cout << "Du skrev: " << number << endl;
            break;
        case 3:
            inputIntegersAndPrintSum();
            break;
        case 4:
            //cout << isOdd(15) << "\n";
            isOdd(1);
            break;
        case 5:
            printHumanReadableTime(10000);
            break;
        case 6:
            sumOfInputIntegers();
            break;
        case 7:
            sumOfInputIntegersEndAtZero();
            break;
        case 8:
            cout.precision(2);
            cout << fixed << konverterFraNOKtilEUR() << "\n";
            break;
        case 9:
            printGangetabell();
            break;
        case 10:
            solveQuadraticEquation();
            break;
        case 11:
            pythagoras();
            break;
        case 12:
            vector<int> n = calculateBalance(5000,10,20);
            printBalance(n);
            break;
        }
    }
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }
    return 0;
}
/* TEORI
1e) Jeg valgte inputInteger fordi den returnerer variabelen brukeren sender inn, og den skriver 
    heller ikke ut det brukeren skrev inn, som gjør ting clean
2c) I 2a brukte jeg for loop, siden brukeren kan si hvor mange ganger loopen skal ta inn tall
    og da er en for loop best egnet, mens i 2b brukte jeg en while loop, for den kan kjøre
    helt til brukeren skriver inn 0
2f) Ser egt ikke noe problem med å bruke inputInteger, ettersom det er en deleoperasjon som blir utført, og da vil 
    C++ fikse om det er double eller int av seg selv. Siden man skal printe ut svaret med to desimalers nøyaktighet
    er det naturlig å returnere en double. 
5c) Uvisst
5d) endre fra <= til < for å fikse, men finner ikke noe feilmedling, bare en "throw"
*/
