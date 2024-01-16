#include <iostream>
#include <cmath>


void convert(float tab[]){
    float x,y;
    for (int i = 0; i < 6; i+=2){
        x = tab[i] * cos(tab[i+1]);
        y = tab[i] * sin(tab[i+1]);
        std::cout << std::endl;
        printf("%.3f, %.3f", x,y);
    }

}


int main(){
    float tab[] = {1.2, 6.1, 1.2, 1.1, 5.4, 3.1};
    convert(tab);
    return 0;
}