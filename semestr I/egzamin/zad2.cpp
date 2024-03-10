/*
Zad 2
Zaprojektuj klasę Hotel, która posiada prywatne pola: nazwa hotelu (napis), liczba pokoi (liczba
całkowita), liczba zarezerwowanych pokoi (liczba całkowita), ocena hotelu (liczba
zmiennoprzecinkowa).

Klasa powinna posiadać przynajmniej następujące publiczne metody:
    1. Konstruktor, który definiuje nazwę hotelu, liczbę pokoi i ocenę hotelu za pomocąargumentów.
    2. reserveRoom(), która zarezerwuje pokój w hotelu, zwiększając liczbę zarezerwowanychpokoi.
    3. cancelReservation(), która anuluje rezerwację pokoju.
    4. getRating(), która zwraca ocenę hotelu.
    5. getFreeRooms(), która zwraca liczbę wolnych pokoi.

W programie głównym stwórz tablicę kilku dynamicznych obiektów typu Hotel.
Użyj dowolnej funkcji sortującej aby posortować hotele w tablicy według ich oceny, w kolejności
od najlepszego.

Wypisz nazwę hotelu, jego ocenę i liczbę wolnych pokoi dla każdego z posortowanych hoteli.
Zarezerwuj kilka pokoi w różnych hotelach i wypisz ponownie nazwy hoteli i liczbę wolnych
pokoi dla każdego z posortowanych hoteli, aby upewnić się, że liczba wolnych pokoi się
zmieniła.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Hotel {
private:
    string name;
    int rooms;
    int reservedRooms;
    double rate;
public:
    Hotel(string name, int rooms, int reservedRooms, double rate){
        this -> name = name;
        this -> rooms = rooms;
        this -> reservedRooms = reservedRooms;
        this -> rate = rate;
    }
    string getName(){return name;}
    int reserveRoom(){if(reservedRooms < rooms){reservedRooms += 1; return reservedRooms;} else return 0;}
    int cancelReservation(){if(reservedRooms > 0){reservedRooms -= 1; return reservedRooms;} else return 0;}
    int getReservedRooms(){return reservedRooms;}
    int getRooms(){return rooms;}
    double getRating(){return rate;}
};

void printInfo(Hotel* ht[], int size){
    for (int i = 0; i < size; i++){
        cout 
        << "Hotel: "<< ht[i]->getName() 
        << "\n\tilość pokoi: " << ht[i]->getRooms() 
        << "\n\tilość zarezerwowanych pokoi: "  << ht[i]->getReservedRooms()
        << "\n\tOcena " << ht[i]->getRating() <<"\n\n";
    }
    
}

bool compareH(Hotel* a, Hotel* b){return a->getRating() > b->getRating();}

void sort(Hotel* ht[], int num, bool(*compareH)(Hotel*, Hotel*)){
    for (int i = 0; i < num - 1; i++){
        for (int j = 0; j < num - i - 1; j++){
            
        }
        
    }
};

int main(){
    int nH = 3;
    Hotel* ht[] = {new Hotel("H0", 40, 10, 5.6), new Hotel("H1", 120, 40, 3.6), new Hotel("H2", 90 , 24, 7.6)};
    printInfo(ht, nH);
    cout << "\n\n\n\n\n";
    ht[2]->reserveRoom();
    ht[2]->reserveRoom();
    ht[0]->cancelReservation();
    printInfo(ht, nH);
    for (int i = 0; i < nH; i++){
        sort(ht, nH, compareH);
    }

    for (int i = 0; i < nH; i++) delete ht[i];
    return 0;
}
