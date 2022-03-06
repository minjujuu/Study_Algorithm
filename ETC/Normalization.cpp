#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double array[] = {3.167, 11.476, 27.0, 9.2, 5.733, 9.5};


    int n = sizeof(array) / sizeof(array[0]);
    double normalization[n];
    cout<<"Array : ";
    for (int i = 0; i < n; i++)
        cout << (double)array[i] << " ";
    cout<<endl;
    double min = *min_element(array, array+n);
    double max = *max_element(array, array+n);
    cout<<"min: "<<(double)min<<" , max: "<<(double)max<<endl;

    double range = 1.0/(max-min);
    cout<<"Normalization : ";
    for(int i=0; i<n; i++) {
        normalization[i] = (array[i]-min)*range;
        cout << (double)normalization[i] << " ,";
    }
    cout<<endl;
    return 0;
}