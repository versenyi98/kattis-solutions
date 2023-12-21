#include <iostream>

#include <map>
#include <vector>
#include <string>

int main() {
    std::string password = "";
    std::string response;
    std::string valid_characters = "";

    for (int i = 0; i < 26; i++) {
        valid_characters += ('a' + i);
        valid_characters += ('A' + i);
    }

    for (int i = 0; i < 10; i++) {
        valid_characters += ('0' + i);
    }

    for (int i = 0; i < 20; i++) {
        password += "a";
        std::cout << password << "\n";
        std::cout.flush();

        std::cin >> response >> response;
        if (response.compare("GRANTED") == 0) {
            exit(0);
        }

        std::cin >> response;

        if (std::stoi(response.substr(1)) != 5) {
            std::cin >> response;
            break;
        }

        std::cin >> response;
    }

    for (int i = 0; i < password.length(); i++) {
        std::map<std::string, std::vector<int>> response_character_mapping;

        for (const char ch : valid_characters) {
            password[i] = ch;

            std::cout << password << "\n";
            std::cout.flush();

            std::cin >> response >> response;
            if (response.compare("GRANTED") == 0) {
                exit(0);
            }
            std::cin >> response;
            response_character_mapping[response].push_back(ch);

            std::cin >> response;
        }

        for (const auto element : response_character_mapping) {
            if (element.second.size() == 1) {
                password[i] = element.second.back();
            }
        }
    }

    return 0;
}