#include <iostream>

struct Player {
    char username[20];
    int wins;
    int totalGames;
    int eliminations;
};

void separate_players(const char** input, int inputSize, char** output) {
    Player* players = new Player[inputSize];

    for (int i = 0; i < inputSize; ++i) {
        sscanf(input[i], "%19[^;];%d;%d;%d", players[i].username, &players[i].wins, &players[i].totalGames, &players[i].eliminations);
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
        "Evel00na;10;10;900",
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

//inne (nieudane wersje) kodu

/*#include <iostream>
#include <cstdio>
#include <cstring>
#include <typeinfo>
#include <cstdlib>

using namespace std;

struct Player{
    char* nick;
    int score;
};
void split_players(char** array, int array_size){
    Player new_player;
    for (int var = 0; var < array_size; ++var) {
        char * pch;
        pch = strtok (array[var],";");
        int index = 0;
        while (pch != NULL) {
            if(index == 0) {
                new_player.nick = pch;
            }
            else {
                new_player.score += atoi(pch);
            }
            pch = strtok (NULL, ";");
            index++;
        }
        printf("%s %d",new_player.nick,new_player.score);
    }
}
int main(){
    char** array = new char*[0];

    array[0] = strdup("MystiqueHero;1365;6890;15210");
    split_players(array,1);
    delete[] array;
    return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <typeinfo>
#include <cstdlib>


void separate_players(const char** input, int inputSize, char** output) {
    for ( int i = 0; i < inputSize; i++){
        char nick;
        std::string temp = input[i];
        int j = 0;
        while (temp[j] != ';') {
            nick += temp[j];
        }
        std::cout << nick;
    }
}

int main(){
    
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

    return 0;
}

*/