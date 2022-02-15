// 약수의 개수와 덧셈 https://programmers.co.kr/learn/courses/30/lessons/77884
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    // left 부터 right까지 약수를 구해야 함 
    // - 1부터 해당 수까지 순회하면서 약수의 개수를 셈
    // - 그 개수가 짝수이면 answer에 더하고, 홀수이면 answer에서 뺌
    for(int i=left; i<=right; i++) {
        int tmp = 1;
        for(int j=2; j<=i; j++) {            
            if(i % j==0) {
                tmp++;
            }           
        }
        if(tmp % 2 == 0) answer += i;
        else answer -= i;
    }
    return answer;
}