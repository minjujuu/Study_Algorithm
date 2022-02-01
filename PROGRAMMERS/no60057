// 문자열 압축 https://programmers.co.kr/learn/courses/30/lessons/60057
#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    string s = "abcabcdede";

    string curT, nextT, result;
    
    int count = 1;
    int len = s.length();
    int answer = len;
    
    for(int unit=1; unit<=(len/2); unit++)
    {
        curT = s.substr(0, unit);

        int i = unit;
        while (true)
        {
            /* 예외: 남은 글자 수가 단위보다 적은 경우 */
            if(i+unit > s.length())
            {
                if (count > 1)
                    result.append(to_string(count));
                result.append(curT);

                for (int j = i; j < s.length(); j++)
                    result.push_back(s[j]);
                break;
            }

            nextT = s.substr(i, unit);

            if (!curT.compare(nextT))
            {
                count++;
            }
            else
            {
                if (count > 1)
                {
                    result.append(to_string(count));
                    count = 1;
                }
                
                result.append(curT);
                curT = nextT;
            }
            i += unit;
        }

        if(answer > result.length())
            answer = result.length();   

        result.clear();
        count = 1;
    }
    
    return answer;

}
