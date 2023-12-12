#include "chemlib.h"

int main() {
    const char* antacid = "Mg(OH)2";
    const char* ethanol = "C2H6O";
    const char* antacid = "CO2";

    Particle pr;
    parse_particle(&pr, antacid);

    free_particle(&pr);

    return 0;
}