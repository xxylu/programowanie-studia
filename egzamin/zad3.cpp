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

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct ImageMeta{
    int width, height, bitsPerPixel;
    string name;
};

void addImageMetaToFile(const ImageMeta& meta, const string& filename){
    fstream outfile(filename, ios::app);
    if (!outfile.is_open()){
        cerr<<"ERROR: Unable to open file "<< filename <<endl;
        return;
    }

    outfile << meta.name << "," << setw(5) << setfill('0') << meta.width << ","
            << setw(5) << setfill('0') << meta.height << "," << meta.bitsPerPixel << endl;

    outfile.close();
}
vector<ImageMeta> readImageMetaFromFile(const string& filename){
    vector<ImageMeta> imageMetadata;

    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return imageMetadata; // Return an empty vector in case of error
    }
    string line;
    while(getline(infile, line)){
        stringstream ss(line);
        string token;

        ImageMeta meta;
        getline(ss, meta.name, ',');
        getline(ss, token, ',');
        meta.width = stoi(token);
        getline(ss, token, ',');
        meta.height = stoi(token);
        getline(ss, token);
        meta.bitsPerPixel = stoi(token);

        imageMetadata.push_back(meta);
    }
    infile.close();
    return imageMetadata;
}
int main(){

    string filename = "example.txt";
    addImageMetaToFile({1024, 512, 24, "wallpaper"}, filename);
    addImageMetaToFile({800, 600, 32, "sunset"}, filename);
    addImageMetaToFile({640, 480, 16, "mountain"}, filename);
    vector<ImageMeta> metadata = readImageMetaFromFile(filename);

    for (const auto& meta : metadata) {
        cout << meta.name 
                << ", w: " << setw(5) << setfill('0') << meta.width
                << ", h: " << setw(5) << setfill('0') << meta.height
                << ", bpp: " << meta.bitsPerPixel << endl;
    }

    return 0;
}