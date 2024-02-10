/*
Zad 3
Zdefiniuj prostą strukturę ImageMeta, która będzie posiadała składowe: width, height,
bitsPerPixel (liczby całkowite) oraz name (napis).

Zaprojektuj i zdefiniuj funkcję addImageMetaToFile(), która przyjmuje w parametrze obiekt typu
ImageMeta, nazwę pliku i dopisuje na koniec tego pliku zawartość przekazanego obiektu.
Format pliku do samodzielnego określenia.

Zaprojektuj i zdefiniuj funkcję readImageMetaFromFile(), która przyjmuje w parametrze nazwę
pliku (o budowie identycznej jak ta zdefiniowana na potrzeby funkcji addImageMetaToFile()) i
na podstawie jego zawartości tworzy tablicę z obiektami typu ImageMeta, którą następnie
zwraca.

W programie głównym zdefiniuj kilka obiektów typu ImageMeta i zapisz je do pliku korzystając z
funkcji addImageMetaToFile().

Następnie, korzystając z funkcji readImageMetaFromFile() wczytaj te obiekty z pliku i wyświetl
je na ekranie. Wyjście dla każdego obrazu sformatuj w taki sposób:

“nazwa_obrazu, w: {WWWWW}, h: {HHHHH}, bpp: {BPP}”

gdzie {WWWWW} i {HHHHH} to odpowiednio wysokość i szerokość obrazu w postaci
pięciocyfrowej, uzupełnionej zerami wiodącymi w razie potrzeby, a {BPP} to wartość pola
bitsPerPixel. Np:
“wallpaper, w: 01024, h: 00512, bpp: 24”

Dla ułatwienia możemy założyć, że liczba wpisów w pliku nie przekracza 100.
*/

