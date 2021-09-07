#include <iostream>
using namespace std;

int main(void)
{
    int m = 0, n = 0;
    int min = 0;
    int total = 0;
    int size = 100;
    int startIdx = 0; // 탐색 시작 인덱스 구하기
    int endIdx = 0;
    
    bool isGetStartIdx = false;
    bool isGetEndIdx = false;
    bool isFindMin = false;
    bool isFindPerfect = false;

    int perfect_square_numbers[100];

    cin>>m;
    cin>>n;

    for(int i=1; i<= size; i++)
    {
        perfect_square_numbers[i-1] = (i*i);
        // 만약 완전제곱수의 값이 m보다 크면 그 전 수가 startIdx가 됨 
        if(!isGetStartIdx)
        {
            if (perfect_square_numbers[i - 1] > m)
            {
                startIdx = i-2;
                isGetStartIdx = true;
            }
        }
        else if(!isGetEndIdx)
        {
            if(perfect_square_numbers[i-1] >= n)
            {
                endIdx = i-1;            
                isGetEndIdx = true;
                break;
            }
        }
    }
    
    // 완전제곱수 찾기
    for(int i=m; i<=n; i++)
    {
        for(int j=startIdx; j<=endIdx; j++)
        {
            if(i == perfect_square_numbers[j])
            {
                isFindPerfect = true;
                if(!isFindMin)
                {
                    min = i;
                    isFindMin = true;
                }
                total += i;
            }
        }
    }

    if(!isFindPerfect)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<total<<endl;
        cout<<min<<endl;
    }
    
    return 0;
}