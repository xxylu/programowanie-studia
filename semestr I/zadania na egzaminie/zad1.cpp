#include <iostream>
#include <cstdio>
using namespace std; 


void sort(const char *input[], int size){
    char nazwa_pokemona[20];
    char id_pokemona[20];
    int combatPower = 0;
    string Nazwa[size];
    string ID[size];
    int moc[size];

    for (int i = 0; i < size; ++i) {
        sscanf(input[i], "%19[^ ] %s", nazwa_pokemona, id_pokemona);
        Nazwa[i] = nazwa_pokemona;
        ID[i] = id_pokemona;
        for (int j = 0; j < size; ++j) {
            if(id_pokemona[j] << j == true){
                combatPower++;
            }
        }
        moc[i] = combatPower;
    }
    //pętla sortująca według mocy (malejąco)
    for (int n = 0; n < size -1; ++n) {
        for (int s = 0; s < size - n -1; ++s) {
            if(moc[s] < moc[s+1]){
                swap(moc[s], moc[s+1]);
                swap(Nazwa[s], Nazwa[s+1]);
                swap(ID[s], ID[s+1]);
            }
        }
    }
    for (int m = 0; m < size; ++m) {
        cout
            <<Nazwa[m]
            << " id: " <<ID[m]
            << " Moc pokemona: "<< moc[m]
            <<endl;

    }

}
int main(){
    int size = 5;
    const char* input[] = {
    "Charizard SoBEf3YteS",
    "Wartortle 3SwYEtHAJ",
    "Bulbasaur wAMdnJqN",
    "Magicarp ftNnpArl",
    "Alakazam WuZ5XMldS2"};

    sort(input, size);
    delete[] *input;
    return 0;
}