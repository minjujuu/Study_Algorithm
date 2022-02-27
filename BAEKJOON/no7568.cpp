// 덩치 https://www.acmicpc.net/problem/7568
#include <iostream>
using namespace std;

struct Man{
    int kg;
    int cm;
    int rank;
};

int main(void) {
    int inputCount = 0;
    cin>>inputCount;

    Man mans[inputCount];

    // 1. 하나씩 순회
    // 2. 다른 사람들의 키, 몸무게 중 자기보다 큰 몸무게가 있으면 rank++
    // 3. 순회가 끝나면 해당 rank로 설정
    for(int i=0; i<inputCount; i++) {
        cin>>mans[i].kg>>mans[i].cm;
    }

    for(int i=0; i<inputCount; i++) {
        int rank = 1;
        for(int j=0; j<inputCount; j++) {
            if(i != j) {
                if(mans[j].kg > mans[i].kg && mans[j].cm > mans[i].cm) {
                    rank++;
                }
            }
        }
        mans[i].rank = rank;
    }

    for(int i=0; i<inputCount; i++) {
        cout<<mans[i].rank<<" ";
    }

    return 0;
}