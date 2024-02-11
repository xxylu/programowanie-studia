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
    Hotel(string name, int rooms, double rate){
        this -> name = name;
        this -> rooms = rooms;
        this -> rate = rate;
    }
    void reserveRoom(){ if(reservedRooms < rooms){reservedRooms + 1;}}
    void cancelReservation(){if(reservedRooms > 0){reservedRooms - 1;}}
    double getRating(){return rate;}
    int getFreeRooms(){return rooms - reservedRooms;}
};

void sort(const Hotel* ht, int num, bool(*compareH)(Hotel*, Hotel*)){
    for (int i = 0; i < num; i++){
        
    }
};

bool compareH(Hotel* a, Hotel* b){return a->getRating() > b->getRating();}

int main(){
    int nH = 3;
    Hotel* ht[] = {new Hotel("H1", 40, 5.6), new Hotel("H2", 10, 3.6), new Hotel("H3", 90, 7.6)};

    
    sort(*ht, nH*2, compareH);

    for (int i = 0; i < nH; i++) delete ht[i];
    return 0;
}
