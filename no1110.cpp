#include <iostream>
using namespace std;

int GetFirstDigit(int num)
{
    return num / 10;
}

int GetSecondDigit(int num)
{
    return num % 10;
}

int MakeNewNumber(int n1, int n2)
{
    return (n1 * 10) + n2;
}

int main(void)
{
    int input = 0;
    int newNumber = -1;
    int sum = 0;
    int n1=0, n2=0;
    cin>>input;

    int target = input;
    // 숫자를 이어붙이는 걸 뭐로할 것인가
    // 첫째자리수 * 10 + 둘째자리수!
    // 세 개의 함수 필요
    // 1. 첫째 자리수를 가져오는 함수
    // 2. 둘째 자리수를 가져오는 함수
    // 3. 자리 수를 합쳐서 새로운 수를 만드는 함수 
    int cycle = 0;
    while(newNumber != target)
    {
        sum = GetFirstDigit(input) + GetSecondDigit(input);
        newNumber = MakeNewNumber(GetSecondDigit(input), GetSecondDigit(sum));
        input = newNumber;
        cycle++;
    }    
    cout<<cycle<<endl;

}