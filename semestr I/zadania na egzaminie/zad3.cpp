#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>
using namespace std;

void process_files(string input, string output){
    fstream data(input, ios::binary);
    if (!data.is_open()){
        cout << "Błąd otwarcia pliku";
    }
    string token;
    string ag;
    float tab[16];
    int i=0;
    int u=0;

    while(getline(input,ag)){
        getline(input,token, " ");
        tab[i] = stod(token); i++;
    }
    data.close();
    fstream data2(output, ios::app);
    if (!data2.is_open()){
        cout << "Błąd otwarcia pliku";
    }
    for (int n = 0; n < 3; ++n) {
        for (int j = 0; j < 5; ++j) {
            data2 << tab[u] << " ";
            u++;
        }
        data2 << endl;
    }
    data2.close();
}

int main(){
    string fileName = {"input.data"};
    string fileName2 = {"input.txt"};
    process_files(fileName, fileName2);
    return 0;
}
