#include <iostream>
#include <cstdio>
using namespace std;

struct Time{
    int h,m,s;
};
class Flight{
private:
    int flightNum, iD;
    string destination;
    Time startFlight;
    string FlightStatus;
public:
    Flight(int flightNum, string destination,int h, int m, string FlightStatus){
        Time t;
        this -> flightNum = flightNum;
        this -> destination = destination;
        this -> t.h = h;
        this -> t.m = m;
        this -> FlightStatus = "Ontime";
    }
    void delayFlight(int minutes){ }
    string cancelFlight(){FlightStatus = "Canceled"; return FlightStatus;}
    void printInfo(){
        Time t;
        cout <<"ID: " << iD << endl;
        cout <<"flightNum: "<< flightNum << endl;
        cout <<"destination: "<< destination << endl;
        cout << "startflight " <<t.h <<":" <<t.m;
        cout << "FlightStatus: " << FlightStatus << endl << endl;
    }

};

int main(){
    int num = 3;
    Flight* fl[3] = {new Flight(234,"Budapest",5,6,"Ontime"), new Flight(834, "Budapest",5,6, "Ontime"), new Flight(834, "Budapest",5,6,"Ontime")};

    fl[1]->cancelFlight();
    fl[1]->printInfo();


    for (int j = 0; j < num; ++j) {
        fl[j]->printInfo();
    }

    for (int s = 0; s < num; ++s) {
        delete[] fl[s];
    }
}