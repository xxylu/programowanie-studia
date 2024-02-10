#include <iostream>
#include <cmath>
#include <ctime>
#include <stdio.h>

int N = 5;

void *func(void **ptr,int N,int size, int x, int y ){
    void *ptr1;
    ptr1 = nullptr;
    if(x<N && y<N-x){
        ptr1 = (char*)ptr[y]+x*size;
        return ptr1;
    } else {
        return nullptr;
    }
}

int main(){
    int x = 2;
    int y = 1;
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
    std::cout<<*(int*)func((void**)arr,N,size,x,y) << " (dla x=" << x <<", y=" << y << ")";

    for(int i = 0; i<N; ++i){
        delete[] arr[i];
    }

    delete[] arr;
    return 0;
}