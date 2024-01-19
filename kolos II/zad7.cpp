#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>

int N = 5;

void *func(void **ptr,int N,int size, int x, int y ){
    void *ptr1;
    ptr1 = nullptr;
    if(y<N && x<N-y){

        ptr1 = (char*)ptr[y]+x*size;
        return ptr1;
    } else {
        return nullptr;
    }
   
}

int main(){
    int x = 1;
    int y = 2;
    int **arr = new int*[N];
    for(int i = 0; i<N; ++i){
        arr[i] = new int;
    }
    
    int size = sizeof(int);
    int it = 0;
    for(int i = 0; i<N; ++i){
        for(int j = 0; j<N-i; ++j){
            arr[i][j] = it++;
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<*(int*)func((void**)arr,N,size,y,x) << " (dla x=" << x <<", y=" << y << ")";

    for(int i = 0; i<N; ++i){
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}