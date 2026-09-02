#include <iostream>
#include <string>

int main() {
    std::string password;
    bool hasNumber = false;
    bool hasSpecialCharacter = false;

    std::cout << "===================\n";
    std::cout << "Password Checker 🔐\n";
    std::cout << "===================\n\n";

    std::cout << "Enter a password: ";
    std::cin >> password;

    for (int i = 0; i < password.length(); i++) {

        if (password[i] >= '0' && password[i] <= '9') {
            hasNumber = true;
        }
        else if (password[i] == '!' ||
                 password[i] == '@' ||
                 password[i] == '#' ||
                 password[i] == '%' ||
                 password[i] == '^') {
            hasSpecialCharacter = true;
        }
    }

    std::cout << "\n";

    if (password.length() < 8) {
        std::cout << "❌ Password must be at least 8 characters.\n";
    }
    else if (!hasNumber) {
        std::cout << "❌ Password must include a number.\n";
    }
    else if (!hasSpecialCharacter) {
        std::cout << "❌ Password must include a special character.\n";
    }
    else {
        std::cout << "✅ Valid password!\n";
    }

    return 0;
}
