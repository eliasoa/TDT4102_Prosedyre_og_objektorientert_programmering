#include "Dummy.hpp"

void dummyTest() {
    Dummy a;                                    // intpeker a som har verid 0
    *a.num = 4;                                 // intpeker a på en adresse, verdien på adressen er nå 4
    Dummy b{a};                                 // inpeker b peker nå på samme adresse som a, og har også derfor verdi 4
    Dummy c;                                    // intpeker c opprettes
    c = a;                                      // inpeker peker også nå på samme minneadresse som b og a, verdi er da 4
    std::cout << "a: " << *a.num << '\n';       // vil skrive 4
    std::cout << "b: " << *b.num << '\n';       // --||--
    std::cout << "c: " << *c.num << '\n';       // --||--
                                                //
    *b.num = 3;                                 // Her endres verdien på adressen til 3
    *c.num = 5;                                 // og her til 5. Både a,b og c har nå verdien 5.
                                                //
    std::cout << "a: " << *a.num << '\n';       // Skrives ut 5
    std::cout << "b: " << *b.num << '\n';       // --||--
    std::cout << "c: " << *c.num << '\n';       // --||--
}


Dummy::Dummy(const Dummy &old_dummy) : Dummy{}{
    *num = *old_dummy.num;
}