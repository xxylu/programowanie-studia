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