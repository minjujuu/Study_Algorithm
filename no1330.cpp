#include <iostream>
using namespace std;

int main(void)
{
    int a = 0, b = 0;
    cin>>a>>b;
    if(a > b)
        cout<<">";
    else if(a<b)
        cout<<"<";
    else
        cout<<"==";

    cout<<endl;

    return 0;
}