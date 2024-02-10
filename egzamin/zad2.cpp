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