// 가장 긴 증가하는 부분 수열 https://www.acmicpc.net/problem/11053
// 먼저 O(n^2)의 Dp로 풀어보자

// 10, 20, 10, 30, 20, 50

// (틀린 로직) dp 배열을 만든다
// 입력배열을 앞에서부터 순회
// 1. 자기보다 앞 쪽에 자신보다 더 작은 숫자가 있는지 탐색
// 2. 그 작은 숫자 중 가장 큰 값을 찾음
// 3. 그 숫자의 dp에 1을 더해서 자신의 dp 숫자로 만듦

// 위 로직으로 했을 때 잘 안됐음,, 코드가 잘못됐었나?
// 1. 0부터 자기보다 앞 쪽에 있는 숫자들을 탐색
// 2. 해당 숫자가 자신의 숫자보다 작다면 maxLength의 후보가 됨
// - 기존의 값과 해당 숫자까지의 dp[j]+1 값을 비교해서 더 큰 값을 취함
// - maxLength = max(maxLength, dp[j]+1)

#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(0);

    int n = 0;
    cin>>n;

    int input[n];
    int dp[n];
    for(int i=0; i<n; i++)
    {
        cin>>input[i];
    }

    dp[0] = 1;

    for(int i=1; i<n; i++) {
        int maxLength = 1;
        for(int j=0; j<i; j++) {
            if(input[j] < input[i]) {
                maxLength = max(maxLength, dp[j] + 1);
            }
        } 
        dp[i] = maxLength;
    }
    
    cout<<*max_element(dp, dp+n)<<endl;
    return 0;
}