#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    string s = "abcabcabcabcdededededede";

    int unit = 6;

    string curT;
    string nextT;
    string result;
    
    int count = 1;

    curT = s.substr(0, unit);

    int i = unit;
    while(true)
    {
        if(i+unit <= s.length())
        {
            nextT = s.substr(i, unit);
        }
        else
        {
            cout<<"last----------"<<endl;
            if(count > 1)
            {
                result.append(to_string(count));
                
            }
            result.append(curT);

            for(int j=i; j<s.length(); j++)
            {
                result.push_back(s[j]);
            }
            break;
        }
        
        cout << "curT = " << curT << endl;
        cout << "nextT = " << nextT << endl;
        if (!curT.compare(nextT))
        {
            count++;
        }
        else
        {
            cout << ">> count = " << count << endl;
            if (count > 1)
            {
                result.append(to_string(count));
                result.append(curT);
                count = 1;
            }
            else
            {
                result.append(curT);
            }
            curT = nextT;
        }
        i += unit;


        cout<<"result = "<<result<<endl;
    }
    cout<<result<<endl;

    return 0;
}