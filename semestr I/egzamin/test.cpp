#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Player {
    std::string name;
    int score1;
    int score2;
    int score3;
};

// Function to parse a line and populate a Player object
Player parseLine(const std::string& line) {
    std::stringstream ss(line);
    std::string token;

    // Tokenize the line based on ';'
    std::vector<std::string> tokens;
    while (std::getline(ss, token, ';')) {
        tokens.push_back(token);
    }

    // Create and populate a Player object
    Player player;
    player.name = tokens[0];
    player.score1 = std::stoi(tokens[1]);
    player.score2 = std::stoi(tokens[2]);
    player.score3 = std::stoi(tokens[3]);

    return player;
}

int main() {
    // Open the file
    std::ifstream file("data.txt");
    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Vector to store Player objects
    std::vector<Player> players;

    // Read each line from the file and parse it
    std::string line;
    while (std::getline(file, line)) {
        // Parse the line and add the Player object to the vector
        players.push_back(parseLine(line));
    }

    // Close the file
    file.close();

    // Output the data
    for (const auto& player : players) {
        std::cout << "Name: " << player.name << ", Scores: " << player.score1 << " " << player.score2 << " " << player.score3 << std::endl;
    }

    return 0;
}

