// 월간 코드 챌린지 시즌1 > 내적
// https://programmers.co.kr/learn/courses/30/lessons/70128?language=cpp

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dotProduct(vector<int> a, vector<int> b);

int main(void) {
    int answer = 0;
    vector<int> a = {1,2,3,4};
    vector<int> b = {-3,-1,0,2};

    answer = dotProduct(a, b);
    cout<<answer<<endl;
    return answer;
}

int dotProduct(vector<int> a, vector<int> b) {
    vector<int> ::iterator iter_a = a.begin();
    vector<int> ::iterator iter_b = b.begin();

    int answer = 0;
    for(; iter_a != a.end(); iter_a++, iter_b++) {
        answer += (*iter_a) * (*iter_b);
    }
    return answer;
}