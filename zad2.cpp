#include <iostream>
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