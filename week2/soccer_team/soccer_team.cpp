#include <iostream>
#include <vector>

// this is only one of the many ways to do this.

// represents a soccer player
struct SoccerPlayer {
    std::string name;
    std::string position;
    int number;
};

// represents a soccer team
struct SoccerTeam {
    std::string name;
    std::vector<SoccerPlayer> players;
};

int main() {
    // create a soccer team
    SoccerTeam aggies{"Aggies"};

    // create some players
    SoccerPlayer sydney = {"Sydney Fuller", "GK", 0};
    SoccerPlayer emma = {"Emma Hoang", "F", 2};

    // add players to the team
    aggies.players.push_back(sydney);
    aggies.players.push_back(emma);

    // extra: print the roster
    for (SoccerPlayer player : aggies.players) {
        std::cout << player.number << " " << player.position << " " << player.name << std::endl;
    }

    return 0;
}