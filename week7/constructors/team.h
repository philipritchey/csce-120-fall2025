#ifndef _TEAM_H_
#define _TEAM_H_

#include <string>
#include <vector>
#include "player.h"

const char WIN = 'W';
const char LOSS = 'L';
const char TIE = 'T';

class Team {
  private:
    struct WinLossTieRecord {
        // default public
        unsigned num_wins = 0;
        unsigned num_losses = 0;
        unsigned num_ties = 0;

        std::string print() const;
    };

    std::string name;
    WinLossTieRecord record;
    std::vector<Player> players;

    // no default teams
    Team();

 public:
    Team(const std::string& name);
    void set_name(const std::string& new_name);
    void add_player(const Player& player);
    void update_record(char result);
    std::string get_name() const;
    std::string print_roster() const;
    std::string print_record() const;
};

#endif  // _TEAM_H_
