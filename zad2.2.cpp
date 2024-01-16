#include <iostream>
#include <cstdlib>
#include <cstring>

struct Player {
    char *username;
    int wins;
    int totalGames;
    int eliminations;
};

void separate_players(const char** input, int inputSize, char** output) {
    Player* players = new Player[inputSize];

  
    for (int i = 0; i < inputSize; ++i) {
        sscanf(input[i], "%[^;];%d;%d;%d", players[i].username, &players[i].wins, &players[i].totalGames, &players[i].eliminations);
    }

  
    for (int i = 0; i < inputSize; ++i) {
        int rankingScore = players[i].wins + players[i].totalGames + players[i].eliminations;
        snprintf(output[i], 30, "%s %d", players[i].username, rankingScore);
    }

    delete[] players;
}

int main() {
    const char* input[] = {
        "MystiqueHero;1365;6890;15210",
        "Frizz;5400;6200;11000",
        "Ziemniak;9965;11000;73000",
        "Evel00na;10;10;90"
    };

    const int inputSize = sizeof(input) / sizeof(input[0]);

    char** output = new char*[inputSize];
    for (int i = 0; i < inputSize; ++i) {
        output[i] = new char[30];
    }

    separate_players(input, inputSize, output);

  
    for (int i = 0; i < inputSize; ++i) {
        std::cout << output[i] << std::endl;
        delete[] output[i];
    }

    delete[] output;

    return 0;
}