#include <iostream>

int main()
{
    std::string password;
    bool hasNum = false;
    bool hasSpe = false;

    std::cout << "===================\n";
    std::cout << "Password Checker 🔐\n";
    std::cout << "===================\n\n";

    std::cout << "Enter a password: ";
    std::cin >> password;
    for (int i=0;i < password.length(); i++){
        if (password[i] >= '0' && password[i] <= '9'){
        hasNum = true;
        }
        else if(password[i] == '!' ||
                password[i] == '@' ||
                password[i] == '#' ||
                password[i] == '%' ||
                password[i] == '^') {
                    hasSpe = true;
                }

    }

    if (password.length() < 8) {
        std::cout << "❌ Password must be at least 8 characters.";
    }
    else if (hasNum != true){
        std::cout << "❌ Password must include a number.";
        }
    else if (hasSpe != true){
        std::cout << "❌ Password must include a special character.";
    }
    else {
        std::cout << "✅ Valid password!";
    }
}


