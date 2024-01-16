#include <iostream>

void* getElement(void* arr, int N, size_t size, int x, int y) {
    if (x >= 0 && x < N && y >= 0 && y < N && y <= x) {
        int index = (x * (x + 1) / 2) + y;
        size_t offset = index * size;

        return static_cast<char*>(arr) + offset;
    } else {
        return nullptr;
    }
}

int main() {

    class human {
        int age = 56;
        int height = 180;
    };

    int N = 5;
    size_t size = sizeof(int);
    void* arr = new char[N * (N + 1) / 2 * size];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            int* element = static_cast<int*>(getElement(arr, N, size, i, j));
            *element = i * N + j;
        }
    }
    int* result = static_cast<int*>(getElement(arr, N, size, 2, 1));
    if (result != nullptr) {
        std::cout << *result << " (dla x=2, y=1)" << std::endl;
    } else {
        std::cout << "nullptr (brak elementu o współrzędnych x=2, y=1)" << std::endl;
    }
    delete[] static_cast<char*>(arr);

    return 0;
}