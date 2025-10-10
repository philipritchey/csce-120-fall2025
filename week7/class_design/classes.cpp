#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Player {
    // private by default
    std::string name;
    unsigned int jersey_number;
    std::string position;

    public: // everyting that follows is public
    void set_name(const std::string& new_name) {
        name = new_name;
    }

    void set_jersey_number(unsigned int new_jersey_number) {
        jersey_number = new_jersey_number;
    }

    void set_position(const std::string& new_position) {
        position = new_position;
    }

    std::string get_name() const { return name; }
    std::string get_position() const { return position; }
    unsigned int get_jersey_number() const { return jersey_number; }

    std::string print() const {
        std::ostringstream oss;
        oss << std::setw(16) << name << " #" << std::setw(2) << jersey_number << " " << position;
        return oss.str();
    }
};

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
