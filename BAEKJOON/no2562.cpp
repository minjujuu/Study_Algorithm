#include <iostream>
using namespace std;

int main(void)
{
    int size = 9;
    int arr[9];
    int max = 0;
    int idx = 0;

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
        if(i==0)
            max = arr[0];
        if(arr[i] > max)
        {
            max = arr[i];
            idx = i;
        }
    }

    cout<<max<<endl;
    cout<<idx+1<<endl;
    

}
