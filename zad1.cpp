#include <iostream>
#include <cstdlib>

void fun_arr(float arr[], float arr2[], float(*fun_aux)(float , float, float)){
    for (int i = 0; i < 4; i++){
        arr2[i] = fun_aux(arr[3*i], arr[3*i+1], arr[3*i+2]);
        std::cout<<arr2[i] << " ";
    }
}

float fun_aux(float a, float b, float c){
    return std::max(a, std::max(b,c));
}

int main(){
    int n = 4;
    float* arr = new float[3*n];
    float* arr2 = new float[n];

    for(int i = 0; i < 3*n; i++){arr[i] = rand() % 100;}
    fun_arr(arr, arr2, fun_aux);

    delete[] arr;
    delete[] arr2;
    return 0;
}