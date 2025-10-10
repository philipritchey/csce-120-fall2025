#include <iomanip>
#include <sstream>
#include <string>
#include "player.h"

void Player::set_name(const std::string& new_name) {
    name = new_name;
}

void Player::set_jersey_number(unsigned int new_jersey_number) {
    jersey_number = new_jersey_number;
}

void Player::set_position(const std::string& new_position) {
    position = new_position;
}

std::string Player::get_name() const {
    return name;
}

std::string Player::get_position() const {
    return position;
}

unsigned int Player::get_jersey_number() const {
    return jersey_number;
}

std::string Player::print() const {
    std::ostringstream oss;
    oss << std::setw(16) << name <<
        " #" << std::setw(2) << jersey_number <<
        " " << position;
    return oss.str();
}
