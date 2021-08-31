#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 100

int main()
{
    int n = 0;
    int m = 0;

    cin>>n>>m;

    // int valOnCard[MAX]; 
    int * valOnCard = new int[n];

    for(int i=0; i<n; i++)
    {
        cin>>valOnCard[i];
    }

    int n1, n2, n3;
    int ans = valOnCard[0] + valOnCard[1] + valOnCard[2];
    int tmp;
    
    for(int i=0; i<n-2; i++)
    {
        n1 = valOnCard[i];
        for(int j=i+1; j<n-1; j++)
        {
            n2 = valOnCard[j];

            for(int k=j+1; k<n; k++)
            {
                n3 = valOnCard[k];
                tmp = n1 + n2 + n3;
                if (abs(m - tmp) < abs(m - ans) && tmp <= m)
                {
                    ans = tmp;
                }
            }
        }
    }

    cout<<ans<<endl;
    delete[] valOnCard;
    return 0;
}