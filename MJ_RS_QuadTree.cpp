#include <iostream>
#include <vector>
#include <string>
using namespace std;

string QuadTree(string &input, int start);
void SwitchString(string &input, int start);
void Swap(char *ch1, char *ch2);
int main(void)
{
    string input = "xbwxwbbwb";
    input = QuadTree(input, 0);
    
    cout<<input<<endl;

    return 0;
}

// string의 배열 4칸을 만든다
// x뒤에 나오는 애들을 순서대로 저장한다
// 중간에 x가 나오면 그것도 따로 저장한다 
// 배열 인덱스를 바꿔치기 한다

int start = 0;
string QuadTree(string &input, int start)
{
    string result;
    
    // string 배열을 만든다
    // 하나의 분면은 배열의 원소가 된다
    // 배열의 원소끼리 바꿔치기 한다
    int idx = 0;
    for(int i=start; i<input.size(); i++)
    {
        if(input[i] == 'x')
        {
            string tmp;
            tmp.append(1, input[i]);
            for(int j=1; j<5; j++)
            {
                if(input[i+j] == 'x')
                {
                    // string swap이 이루어져야 함 
                    tmp.append(QuadTree(input, i+j));
                    i+=4;
                }
                else
                {
                    tmp.append(1, input[i+j]);
                    cout<<tmp<<endl;
                }
                start = i+j;
            }
    

            SwitchString(tmp, 1);
            result.append(tmp);
        }
    }

    return result;

}

void SwitchString(string &input, int start)
{
    // cout<<"before switch : "<<input<<endl;
    Swap(&input[start], &input[start+2]); // xbwwb
    //  cout<<"after switch : "<<input<<endl; // wwbb
    Swap(&input[start+1], &input[start+3]); // xwbbw
    // cout<<"after switch : "<<input<<endl;
}

void Swap(char *ch1, char *ch2)
{
    char temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}