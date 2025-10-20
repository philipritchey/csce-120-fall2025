#ifndef WEEK9_DICE_DICE_H_
#define WEEK9_DICE_DICE_H_

#include <iostream>
#include <stdexcept>

class Dice {
    unsigned number_of_dice;
    unsigned number_of_sides;
    unsigned current_value;

 public:
    // default to 1d6
    Dice() : Dice(1, 6) {}
    Dice(unsigned num_dice, unsigned num_sides) : number_of_dice{num_dice}, number_of_sides{num_sides}, current_value{num_dice} {}
    unsigned count() const { return number_of_dice; }
    unsigned sides() const { return number_of_sides; }
    unsigned value() const { return current_value; }
    void roll();

    bool operator==(const Dice& rhs) const;
};

std::ostream& operator<<(std::ostream& os, const Dice& dice);

#endif  // WEEK9_DICE_DICE_H_
