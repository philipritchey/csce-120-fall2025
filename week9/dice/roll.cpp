#include <iostream>
#include "dice.h"

int main() {
    Dice dice_5d20(5, 20);
    for (int i = 0; i < 5; i++) {
        dice_5d20.roll();
        std::cout << dice_5d20 << std::endl;
    }
    return 0;
}
