#include <iostream>
#include <random>
#include "dice.h"

std::ostream& operator<<(std::ostream& os, const PositiveInteger& p) {
    return os << p.get_value();
}

void Dice::roll() {
    unsigned value = 0;
    for (unsigned i = 0; i < count(); i += 1) {
        value += (rand() % sides()) + 1;
    }
    current_value = value;
}
