#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;



int main(){
    int n = 160;
    int m = 140;
    int it;
    float temp = 0, temp2 = 0;
    float temp3 = 0;
    cout<<"Enter n and m"<<endl;
    cout << n << " " << m;
    unsigned int** arr2d= new unsigned int*[n];
    for (int i=0; i<n;i++){
        arr2d[i]=new unsigned int[m*2];
    }
    for (int i=0; i<n;i++){
        for (int j=0; j<(2*m); j++){
            arr2d[i][j]=rand()%10;
        }
    }
    for (int i=0; i<n;i++){
        for (int j=0; j<m*2; j++){
            cout<<arr2d[i][j]<<" ";
        }
        cout<<endl;
    }

    float** arr2d2 = new float*[n];
    for (int i=0; i<n;i++){
        arr2d2[i]=new float[m];
    }


    for (int j=0;j<n;j++) {
        it = 0;
        for (int i = 0; i < m*2; i+=2) {
            temp = arr2d[j][i];
            temp2 = arr2d[j][i + 1];
            if (temp > temp2) {
                temp3 = (float) (temp + (temp2 * 0.1));
                arr2d2[j][it] = temp3;
            } else {
                temp3 = (float) (temp2 + (temp * 0.1));
                arr2d2[j][it] = temp3;
            }
            it++;
        }
    }
    for (int i=0; i<n;i++){
        for (int j=0; j<m; j++){
            cout<<arr2d2[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0; i<n;i++){
        delete[] arr2d[i];
    }
    for (int i=0; i<n;i++){
        delete[] arr2d2[i];
    }
    delete[] arr2d;
    delete[] arr2d2;
    return 0;
}