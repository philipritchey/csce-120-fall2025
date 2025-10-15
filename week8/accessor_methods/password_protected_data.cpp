#include <iostream>
#include <string>

using std::string, std::cout, std::endl;

class PasswordProtectedData {
    string secret_data;
    string secret_password;

    bool invalid_password(const string& password) {
        return password != secret_password;
    }

    bool too_short(const string& password) {
        if (password.length() >= 8) {
            return false;
        }
        cout << "password should have an uppercase letter" << endl;
        return true;
    }

    bool no_uppercase(const string& password) {
        for (char c : password) {
            if (isupper(c)) {
                return false;
            }
        }
        cout << "password should have an uppercase letter" << endl;
        return true;
    }

    bool no_lowercase(const string& password) {
        for (char c : password) {
            if (islower(c)) {
                return false;
            }
        }
        cout << "password should have a lowercase letter" << endl;
        return true;
    }

    bool no_digit(const string& password) {
        for (char c : password) {
            if (isdigit(c)) {
                return false;
            }
        }
        cout << "password should have a digit" << endl;
        return true;
    }

    bool no_special(const string& password) {
        if (password.find_first_of("~`!@#$%^&*()_-+={[}]|\\:;\"'<,>.?/}") < password.length()) {
            return false;
        }
        cout << "password should have a special character" << endl;
        return true;
    }

    bool too_simple(const string& password) {
        return too_short(password)
            || no_uppercase(password)
            || no_lowercase(password)
            || no_digit(password)
            || no_special(password);
    }

 public:
    PasswordProtectedData(string data, string password) : secret_data{data}, secret_password{password} {
        if (too_simple(password)) {
            throw std::invalid_argument("password is too simple");
        }
    }

    string get_data(const string& password) {
        if (invalid_password(password)) {
            cout << "get_data: ACCESS DENIED" << endl;
            return "";
        }
        cout << "get_data: ACCESS GRANTED" << endl;
        return secret_data;
    }

    void set_data(string data, const string& password) {
        if (invalid_password(password)) {
            cout << "set_data: ACCESS DENIED" << endl;
            return;
        }
        cout << "set_data: ACCESS GRANTED" << endl;
        secret_data = data;
    }

    void change_password(string new_password, const string& old_password) {
        if (invalid_password(old_password) || too_simple(new_password)) {
            cout << "PASSWORD NOT CHANGED" << endl;
            return;
        }
        cout << "PASSWORD CHANGED" << endl;
        secret_password = new_password;
    }
};

int main() {
    string password = "Too m@ny s3crets";
    PasswordProtectedData ppd("the answer is 42", password);

    cout << ppd.get_data(password) << endl;
    ppd.set_data("howdy world", "");
    cout << ppd.get_data(password) << endl;
    ppd.set_data("howdy world", password);
    cout << ppd.get_data(password) << endl;

    ppd.change_password("password", password);
    ppd.change_password("P@ssw0rd", password);
    cout << ppd.get_data(password) << endl;
    cout << ppd.get_data("P@ssw0rd") << endl;

}
