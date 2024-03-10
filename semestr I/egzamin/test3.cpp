#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


struct as {
    string name;
    int a,b,c;
};


int main() {
    fstream data("data.txt");
    long n = 0;
    string ag;
    string line;
    if (!data.is_open()){
        printf("Blad otwarcia pliku\n");
        return 1;
    }   
        int size = 5;
        as S[size];
        for (int i = 0; i < size; i++){
            getline(data, S[i].name, ';');
            cout << "name: " <<S[i].name << "\n";
            getline(data, ag, ';'); S[i].a = stoi(ag); 
            cout << "\tdata 1: " << S[i].a << "\n";
            getline(data, ag, ';'); S[i].b = stoi(ag);
            cout << "\tdata 2: " << S[i].b << "\n";
            getline(data, ag, ';'); S[i].c = stoi(ag);
            cout << "\tdata 3: " << S[i].c << "\n";
        }

        //data << "\nsasas" << "\n";
        //data << "assassasas" << "\n";
        data.close();
    return 0;
}
