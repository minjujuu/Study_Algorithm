#include<iostream>
#include <cmath>
using namespace std;
 
int main(void) 
{
    int n = 0;
    cin>>n;

    int answer = 0;

    for(int i=2; i<=n; i++)
    {
        bool isPrimeNum = true;
        int num = (int)sqrt(i);
        for(int j=2; j<=num; j++)
        {
            if(i % j == 0)
            {
                isPrimeNum = false;
                break;
            }
        }           
        if(isPrimeNum) answer++; 
    }

    cout<<answer<<endl;
    return 0;
}
