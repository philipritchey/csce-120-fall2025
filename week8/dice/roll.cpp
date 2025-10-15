#include <iostream>
#include "dice.h"
#include "dice.h"  // on purpose to check header guards
#include "test_helpers.h"

void test_1d6();
void test_2d10();
void test_20d2();
void test_invalid_dice();
void demo_5d20();

int main() {
    test_1d6();
    test_2d10();
    test_20d2();
    test_invalid_dice();

    demo_5d20();

    return 0;
}

void test_1d6() {
    // one 6-sided dice
    Dice dice_1d6(1, 6);

    // default should be snake eyes (all 1s)
    expect_equal(dice_1d6.count(), 1);
    expect_equal(dice_1d6.sides(), 6);
    expect_equal(dice_1d6.value(), 1);

    dice_1d6.roll();

    // roll should result in a value between 1 and 6
    expect_between(dice_1d6.value(), 1, 6);
}

void test_2d10() {
    // two 10-sided dice
    Dice dice_2d10(2, 10);

    // default should be snake eyes (all 1s)
    expect_equal(dice_2d10.count(), 2);
    expect_equal(dice_2d10.sides(), 10);
    expect_equal(dice_2d10.value(), 2);

    dice_2d10.roll();

    // roll should result in a value between 2 and 20
    expect_between(dice_2d10.value(), 2, 20);
}

void test_20d2() {
    // twenty 2-sided dice
    Dice dice_20d2(20, 2);

    // default should be snake eyes (all 1s)
    expect_equal(dice_20d2.count(), 20);
    expect_equal(dice_20d2.sides(), 2);
    expect_equal(dice_20d2.value(), 20);

    dice_20d2.roll();

    // roll should result in a value between 20 and 40
    expect_between(dice_20d2.value(), 20, 40);
}

void test_invalid_dice() {
    expect_throw(Dice(0, 2));
    expect_throw(Dice(2, 0));
    expect_throw(Dice(-1, 2));
    expect_throw(Dice(2, -1));
    expect_throw(Dice(0, 0));
    expect_throw(Dice(-1, -1));
    expect_throw(Dice(3.14, 2.73));
}

void demo_5d20() {
    Dice dice_5d20(5, 20);
    std::cout << "Rolling 5d20 until value at least 50..." << std::endl;
    unsigned i = 0;
    do {
        i += 1;
        dice_5d20.roll();
        std::cout << i << ") rolled 5d20: " << dice_5d20.value() << "\n";
    } while (dice_5d20.value() < 50);
}
