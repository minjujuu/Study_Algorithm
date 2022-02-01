// 백준 1152번
#include <iostream>
#include <string>

using namespace std;

int main(void) 
{
    string input;

    getline(cin, input);
    // cout<<input<<endl;
    int count = 0;
    if(input.size() == 1 && input[0] == 32)
    {
        cout<<0<<endl;
        return 0;
    }

    for(int i=0; i<input.size(); i++)
    {
        if(i != 0 && i != input.size()-1)
        {
            if (input[i] == 32)
            {
                count++;
            }
        }
    }
    
    cout<<++count<<endl;

    return 0;
}
