#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iomanip>
#include <sstream>
#include <string>

class Player {
    // private by default
    std::string name;
    unsigned int jersey_number;
    std::string position;

 public:  // everyting that follows is public
    void set_name(const std::string& new_name);
    void set_jersey_number(unsigned int new_jersey_number);
    void set_position(const std::string& new_position);
    std::string get_name() const;
    std::string get_position() const;
    unsigned int get_jersey_number() const;
    std::string print() const;
};

#endif  // _PLAYER_H_
