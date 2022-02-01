#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> GetPrefixSuffix(string & s);
vector<int> GetPiArray(string & s);

int main(void)
{

    string mother;
    string father;

    cin>>father;
    cin>>mother;

    father.append(mother);

    vector <int> result;

    result = GetPrefixSuffix(father);
    sort(result.begin(), result.end());
    vector<int>:: iterator iter = result.begin();
    for(iter = result.begin(); iter != result.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    
    cout<<endl;
    return 0;
}

// S의 접두사도 되고 접미사도 되는 모든 문자열의 길이 계산
// 1. pi[k]의 가장 큰 수를 찾는다.
// 2. 결과 배열에 넣는다
// 3. pi[k]의 값보다 -1한 값을 인덱스로 하는 pi[k]의 위치를 확인한다
// 4. 결과 배열에 넣는다
// - k가 0보다 크면 위 3,4과정을 반복한다

vector<int> GetPrefixSuffix(string & s)
{
    int k = s.size();
    vector<int> pi(k);
    vector<int> resultArr;
    pi = GetPiArray(s);
    
    while(k > 0)
    { 
        resultArr.push_back(k);
        k = pi[k-1];
    }
    return resultArr;
}

vector<int> GetPiArray(string & s)
{
    int j=0; 
    bool replay = false;
    vector<int> piArr(s.size());
    piArr.push_back(0);
    for(int i=1; i<s.size(); i++)
    {
        if(replay)
        {
            i--;
            replay = false;
        }

        if(s[i] != s[j])
        {
            piArr[i] = 0;
            if(j > 0)
            {
                j = 0;
                replay = true;
            }   
        }
        else
        {
            piArr[i] = j+1;
            j++;
        }
    }
    return piArr;
}
