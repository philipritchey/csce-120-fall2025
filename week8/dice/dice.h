#ifndef DICE_H_
#define DICE_H_

#include <iostream>
#include <stdexcept>

class PositiveInteger {
    unsigned value;

 public:
    PositiveInteger(unsigned n) : value{n} {}
    PositiveInteger(signed n) : value{1} {
        if (n <= 0) {
            throw std::invalid_argument("PositiveInteger: not positive");
        }
        value = static_cast<unsigned>(n);
    }
    PositiveInteger(double f) {
        throw std::invalid_argument("PositiveInteger: not an integer");
    }

    unsigned get_value() const { return value; }

    bool operator==(const PositiveInteger& rhs) const { return this->value == rhs.value; }
};

std::ostream& operator<<(std::ostream&, const PositiveInteger&);

class Dice {
    PositiveInteger number_of_dice;
    PositiveInteger number_of_sides;
    PositiveInteger current_value;

 public:
    // default to 1d6
    Dice() : Dice(1, 6) {}
    Dice(PositiveInteger num_dice, PositiveInteger num_sides) : number_of_dice{num_dice}, number_of_sides{num_sides}, current_value{num_dice} {}
    unsigned count() const { return number_of_dice.get_value(); }
    unsigned sides() const { return number_of_sides.get_value(); }
    unsigned value() const { return current_value.get_value(); }
    void roll();

    bool operator==(const Dice& rhs) const;
};

#endif  // DICE_H_
