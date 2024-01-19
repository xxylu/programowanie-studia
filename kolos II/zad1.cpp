#include <iostream>

void fun_arr(int size,float tab[], float tab2[], float(*fun_aux)(float , float, float)){
    for (int i = 0; i < size; i++){
        tab2[i] = fun_aux(tab[3*i], tab[3*i+1], tab[3*i+2]);
        std::cout<<tab2[i] << ", ";
    }
}

float fun_aux(float a, float b, float c){
    return std::max(a, std::max(b,c));
}

int main(){
    srand(time(NULL));
    int n = 10;
    float* arr = new float[3*n];
    float* arr2 = new float[n];
    std::cout<<"Input: ";
    for(int i = 0; i < 3*n; i++){
        arr[i] = rand() % 200 * 0.97;
        std::cout<<arr[i] << ", ";
    }

    std::cout<< std::endl;
    std::cout<<"Output: ";
    fun_arr(n, arr, arr2, fun_aux);

    delete[] arr;
    delete[] arr2;
    return 0;
}