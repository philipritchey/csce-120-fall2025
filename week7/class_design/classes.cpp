#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "team.h"

int main() {
    Team aggies;
    aggies.set_name("Aggies");

    std::vector<std::vector<std::string>> roster = {
        {"0",  "Erica Defferding", "Goalkeeper"},
        {"0",  "Sydney Fuller",    "Goalkeeper"},
        {"2",  "Emma Hoang",       "Forward"},
        {"3",  "Bella James",      "Defender"},
        {"4",  "Bella Yakel",      "Defender"},
        {"5",  "Tessa Lavender",   "Defender"},
        {"6",  "Bailey Cate",      "Forward"},
        {"7",  "Kaylee Noble",     "Forward"},
        {"8",  "Kat Campbell",     "Midfielder"},
        {"10", "Kennedy Clark",    "Forward"},
        {"11", "Riley Crooks",     "Defender"},
        {"12", "Reese Rupe",       "Midfielder"},
        {"14", "Hattie Patterson", "Defender"},
        {"15", "Maysen Veronda",   "Goalkeeper"},
        {"16", "Trinity Buchanan", "Midfielder"},
        {"17", "Mia Scranton",     "Defender"}};

    for (const std::vector<std::string>& p : roster) {
        Player player;
        player.set_name(p.at(1));
        player.set_jersey_number(std::stoi(p.at(0)));
        player.set_position(p.at(2));
        aggies.add_player(player);
    }

    // play 27 games and "randomly" win or tie
    srand(98);
    for (int i = 0; i < 27; i++) {
        if (rand() % 2) {
            aggies.update_record(WIN);
        } else {
            aggies.update_record(TIE);
        }
    }

    std::cout << aggies.get_name() << " Roster\n"
              << std::string(aggies.get_name().length(), '-') << "-------\n"
              << aggies.print_roster() << std::endl;

    std::cout << aggies.print_record() << std::endl;
    return 0;
}
