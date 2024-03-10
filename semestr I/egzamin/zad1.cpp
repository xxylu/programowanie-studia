/* 
Zad 1
Zaprojektuj i zdefiniuj funkcję find_subset() przyjmującą jako argumenty:
    1) tablicę liczb całkowitych, bez znaku, 16 bitowych,
    2) rozmiar tablicy,
    3) wskaźnik na funkcję pomocniczą, która przyjmuje w parametrach tablicę o typie identycznym jak w pkt. 1i rozmiar tej tablicy a zwraca wartość boolowską,
    4) referencję na liczbę całkowitą.

Funkcja find_subset() powinna zwrócić wskaźnik na element w przekazanej tablicy, w
której rozpoczyna się najdłuższy fragment tej tablicy, dla którego funkcja pomocnicza zwróci
prawdę. W referencji (4) należy zapisać długość tego fragmentu. Jeżeli istnieje więcej
fragmentów o tej samej długości, należy zwrócić dowolny z nich.

Napisz funkcję pomocniczą is_strictly_increasing(), która przyjmie jako argumenty
tablicę liczb całkowitych i rozmiar tej tablicy. Funkcja powinna zwrócić prawdę, gdy wszystkie
elementy tablicy tworzą monotonicznie rosnący ciąg liczb, a fałsz w przeciwnym przypadku.

Napisz funkcję pomocniczą are_zero_even_bits(), która przyjmie jako argumenty tablicę
liczb całkowitych i rozmiar tej tablicy. Funkcja powinna zwrócić prawdę, gdy wszystkie liczby w
tej tablicy mają wyzerowane bity na parzystych pozycjach, a fałsz w przeciwnym przypadku (np.
162d = 010100010b).

W programie głównym stwórz utwórz przykładową tablicę liczb całkowitych. Następnie wywołaj
funkcję find_subset() dwukrotnie, za pierwszym razem z funkcją pomocniczą
is_strictly_increasing() a za drugim z are_zero_even_bits(). Wyświetl liczby ze
zwróconego fragmentu tablicy.
*/

#include <iostream>
#include <cmath>


short int find_subset(unsigned short int tab[], int size, bool(*)(unsigned short, int)){
    return true;
}

bool is_strictly_increasing(unsigned short int tab[], int size){
    return true;
}

bool are_zero_even_bits(unsigned short int tab[], int size){
    return true;
}

int main(){
    int size = 10;
    unsigned short int* dynamicArray = new unsigned short int[size] {1, 2, 5, 2, 2, 10, 11, 12, 8, 3};
    find_subset(dynamicArray, size, is_strictly_increasing(dynamicArray, size));
    find_subset(dynamicArray, size, are_zero_even_bits(dynamicArray, size));
    return 0;
}