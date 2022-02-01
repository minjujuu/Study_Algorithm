// 두 개 뽑아서 더하기 https://programmers.co.kr/learn/courses/30/lessons/68644
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(void)
{
    vector<int> vec = {2, 1, 3, 4, 1};
    vector<int> answer;
    set<int> s;
    for(int i=0; i<vec.size()-1; i++)
    {
        for(int j=i+1; j<vec.size(); j++)
        {
            s.insert(vec[i] + vec[j]);
        }
    }

    for(int i:s)
    {
        answer.push_back(i);
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;

}
