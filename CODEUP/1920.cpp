#include <iostream>
#include <stack>
using namespace std;
 
int ConvertToBinary(int n, stack<int>& stc)
{
    if(n == 0)
    {
        return 0;
    }
    else
    {
        stc.push(n % 2);
        return ConvertToBinary(n/2, stc);
    }
}

void PrintStack(stack<int>& stc)
{
    if(stc.empty())
        return;
    else
    {
        cout<<stc.top();
        stc.pop();
        PrintStack(stc);
    }
}

int main(void)
{    
    int n = 0;
    cin>>n;

    if(n == 0)
    {
        cout<<0<<endl;
        return 0;
    }
    stack<int> binaryStack;

    ConvertToBinary(n, binaryStack);
    PrintStack(binaryStack);

    cout<<endl;
    return 0;
}
