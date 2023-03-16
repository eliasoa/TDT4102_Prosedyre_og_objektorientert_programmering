#include "includes.hpp"


// int main() {
//     testAnimal();
//     return 0;
// }

/* Teorioppgaver
Oppgave 1a)
Når man oppretter en klasse, og man ikke videre spesifiserer noe, vil alle variablene og funksjonene være PRIVATE, og kun funksjoner som er medlem av klassen kan endre på de. 
Dersom man setter de til PUBLIC, kan man endre på klasse-variablene i andre funksjoner samt kjøre medlemsfunksjonene, i feks main(). Dersom man seter opp et child av klassen
vil det ikke ha tilgang på medlemsfunksjonene og -variablene. Dersom disse hadde vært satt til PUBLIC, ville alt hatt tilgang.
Dersom man bruker PROTECTED, vil child ha tilgang til medlemsfunksjonene og -variablene, mens for andre funksjoner utenfor klassen, vil de være PRIVATE 

Oppgave 1d)
Hvis jeg definerer animals vektoren i Animals.h, feiler kompilatoren med feilmelding 

FAILED: program.exe 
"C:\mingw64\bin\clang++"  -o program.exe program.exe.p/Animals.cpp.obj program.exe.p/main.cpp.obj "-Wl,--allow-shlib-undefined" "-Wl,--start-group" "subprojects\animationwindow\libanimationwindow.a" "-lmingw32" "C:/Users/Elias/OneDrive/Documents/TDT4102-POOP-1/Assignment 7/subprojects/sdl2_windows/lib/libSDL2main.a" "C:/Users/Elias/OneDrive/Documents/TDT4102-POOP-1/Assignment 7/subprojects/sdl2_windows/lib/libSDL2.dll.a" "-lmingw32" "C:/Users/Elias/OneDrive/Documents/TDT4102-POOP-1/Assignment 7/subprojects/sdl2_image_windows/lib/libSDL2_image.dll.a" "-Wl,--subsystem,console" "-lkernel32" "-luser32" "-lgdi32" "-lwinspool" "-lshell32" "-lole32" "-loleaut32" "-luuid" "-lcomdlg32" "-ladvapi32" "-Wl,--end-group"
C:/mingw64/bin/ld: program.exe.p/main.cpp.obj:C:/Users/Elias/OneDrive/Documents/TDT4102-POOP-1/Assignment 7/builddir/../Animals.h:60: multiple definition of `animals'; program.exe.p/Animals.cpp.obj:C:/Users/Elias/OneDrive/Documents/TDT4102-POOP-1/Assignment 7/builddir/../Animals.h:60: first defined here
clang++: error: linker command failed with exit code 1 (use -v to see invocation)
ninja: build stopped: subcommand failed.

men hvis jeg definerer den i testAnimal(), så går alt fint. Så jeg skjønner ikke hvorfor dette ikke skal funke?

Hvis jeg fjerner virual forran toString i Animal-klassen:
Animal: Jippi 10
Animal: Pusen 5
Da skrives kun navn og alder, ikke hvilket dyr. Dette er fordi funskjonen ikke blir overskrevet toatlt


*/