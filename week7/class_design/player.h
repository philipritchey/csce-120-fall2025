#include <iomanip>
#include <sstream>
#include <string>

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
