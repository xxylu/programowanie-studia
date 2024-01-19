#include <iostream>
#include <cmath>

double calculateLength(double x, double y) {
    return std::sqrt(x * x + y * y);
}

void arr_fun(double* begin, double* end, double* result, double (*lengthFunction)(double, double)) {
    int vectorSize = 2;

    while (begin < end) {
        double x = *begin;
        double y = *(begin + 1);

        *result = lengthFunction(x, y);

        begin += vectorSize;
        result++;
    }
}

int main() {
    double inputArray[] = {1.0, 1.0, 2.0, 1.0, 1.0, 3.0, 3.0, 1.0};
    int numberOfVectors = sizeof(inputArray) / sizeof(double) / 2;

    double* resultArray = new double[numberOfVectors];

    arr_fun(inputArray, inputArray + sizeof(inputArray) / sizeof(double), resultArray, calculateLength);

    std::cout << "IN: ";
    for (int i = 0; i < numberOfVectors * 2; i++) {
        std::cout << inputArray[i] << " ";
    }

    std::cout << "\nOUT: ";
    for (int i = 0; i < numberOfVectors; i++) {
        std::cout << resultArray[i] << " ";
    }

    delete[] resultArray;

    return 0;
} 