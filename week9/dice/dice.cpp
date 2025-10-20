#include <iostream>
#include <random>
#include "dice.h"

void Dice::roll() {
    unsigned value = 0;
    for (unsigned i = 0; i < count(); i += 1) {
        value += (rand() % sides()) + 1;
    }
    current_value = value;
}

bool Dice::operator==(const Dice& rhs) const {
    return this->number_of_dice == rhs.number_of_dice
        && this->number_of_sides == rhs.number_of_sides
        && this->current_value == rhs.current_value;
}

std::ostream& operator<<(std::ostream& os, const Dice& dice) {
    return os << dice.count() << "d" << dice.sides() << ": " << dice.value();
}
