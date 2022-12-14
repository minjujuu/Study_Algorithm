// N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
// N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

#include <iostream>
int n, cnt = 0;
int temp[16] = {0,}; 

int nqueen(int col)
{
    // n개를 다 놓으면 경우의 수 +1
    if(col == n)
    {
        cnt+=1;
        return;
    }

    for(int i=0; i<col; i++)
    {
        bool check = true;
        for(int j=0; j<)
    }

}
int main(void)
{
    // 첫 줄에 퀸의 개수 N이 주어진다.
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        temp[0] = i; // 0번째 줄에는 놓는 퀸의 위치를 바꿔가면서 함
        nqueen(1);
    }
}