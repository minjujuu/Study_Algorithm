#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    
    sort(d.begin(), d.end());
    vector<int>::iterator iter;
    for(iter = d.begin(); iter != d.end(); iter++) {
        if(budget - *iter >= 0) {
            budget -= *iter;
            answer++;
        } else {
            break;
        }
    }
    return answer;
}