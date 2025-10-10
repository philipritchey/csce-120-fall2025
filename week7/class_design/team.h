#ifndef _TEAM_H_
#define _TEAM_H_

#include <sstream>
#include <string>
#include <vector>
#include "player.h"

const char WIN = 'W';
const char LOSS = 'L';
const char TIE = 'T';

class Team {
    struct WinLossTieRecord {
        unsigned num_wins = 0;
        unsigned num_losses = 0;
        unsigned num_ties = 0;

        std::string print() const {
            std::ostringstream oss;
            oss << num_wins << "-" << num_losses << "-" << num_ties;
            return oss.str();
        }
    };

    std::string name;
    WinLossTieRecord record;
    std::vector<Player> players;

 public:
    std::string get_name() const { return name; }
    void set_name(const std::string& new_name) { name = new_name; }
    void add_player(const Player& player) { players.push_back(player); }
    std::string print_roster() const {
        std::ostringstream oss;
        for (const Player& player : players) {
            oss << player.print() << "\n";
        }
        return oss.str();
    }
    void update_record(char result) {
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
    std::string print_record() const { return record.print(); }
};

#endif  // _TEAM_H_
