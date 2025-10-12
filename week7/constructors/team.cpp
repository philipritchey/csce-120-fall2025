#include <sstream>
#include <string>
#include "team.h"

Team::Team(const std::string& name) : name{name} {}

std::string Team::WinLossTieRecord::print() const {
    std::ostringstream oss;
    oss << num_wins << "-" << num_losses << "-" << num_ties;
    return oss.str();
}

std::string Team::get_name() const {
    return name;
}

void Team::set_name(const std::string& new_name) {
    name = new_name;
}

void Team::add_player(const Player& player) {
    players.push_back(player);
}

std::string Team::print_roster() const {
    std::ostringstream oss;
    for (const Player& player : players) {
        oss << player.print() << "\n";
    }
    return oss.str();
}

void Team::update_record(char result) {
    switch (result) {
        case WIN:
            record.num_wins += 1;
            break;
        case LOSS:
            record.num_losses += 1;
            break;
        case TIE:
            record.num_ties += 1;
            break;
    }
}

std::string Team::print_record() const {
    return record.print();
}
