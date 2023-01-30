#include "Randomizer.h"

#include <cstdlib>

SYSTEMTIME Randomizer::st;
bool Randomizer::active;

void Randomizer::activate()
{
    if (!active) {
        ::GetSystemTime(&st);
        srand(st.wMilliseconds);
        active = true;
    }
}

int Randomizer::randomize(int range)
{
    activate();
    return rand() % range;
}

int Randomizer::randomize( int range, int begin)
{
    activate();
    return rand() % range + begin;
}

