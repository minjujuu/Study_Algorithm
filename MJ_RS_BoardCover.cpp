#include <iostream>
#include <vector>
using namespace std;
#define MAX 20
#define WHITE 0
#define BLACK 1

void PrintBoard(vector<vector<int>> &inputArr);

// 1. 3차원 배열 
// - 2개짜리 원소가 3개 있고,
// - 3개짜리 원소가 4개 있다
const int coverType[4][3][2] = // 행 열
    {{{0, 0}, {0, 1}, {1, 1}},
     {{0, 0}, {0, 1}, {1, 0}},
     {{0, 0}, {1, -1}, {1, 0}},
     {{0, 0}, {1, 0}, {1, 1}}};

// 2. 2차원 배열을 vector로 나타내는 법
// - vector<vector<int>> : vector<int>를 담는 또 다른 배열 
// - 참조형 &으로 쓰면 퍼포먼스가 조금 더 낫다!

bool Search(int type, int y, int x, vector<vector<int>> &inputArr, int addVal)
{
    
    for (int j = 0; j < 3; j++)
    {
        // 3. x, y를 좌표값으로 생각하면 헷갈리기 쉬운데
        // 행,열 은 y, x로 거꾸로 생각해야 한다
        int ny = y + coverType[type][j][0];
        int nx = x + coverType[type][j][1];

        // C에서는 배열의 크기를 매개변수로 받는 게 흔했는데 C++에서는 vector의 size() 함수를 이용하면 된다 

        // 기저 사례 : 탐색할 새로운 좌표값이 0보다 작거나 size를 벗어나는 경우
        if(nx < 0 || nx >= inputArr[0].size() || ny < 0 || ny >= inputArr.size()) 
        {
            return false;
        }
        // 기저 사례 2. 더했더니 1을 넘는 경우 (이미 덮여있다는 뜻이 됨)
        else if((inputArr[ny][nx] += addVal) > 1) 
        {
            return false;
        }
    }

    return true;
}

int CoverBoard(vector<vector<int>> &inputArr)
{
    // 2차원 배열을 순회하면서 흰색(.)을 만나면
    // coverType을 통해 주변 타일을 확인해서 덮을 수 있는 상황이면 검정색(#)으로 바꾼다
    // 그리고 그렇게 변경된 inputArr을 다시 재귀함수로 넘겨 호출한다
    // 재귀함수 종료 조건
    // - 흰색 타일을 발견할 수 없을 때
    // - 흰색 타일을 발견했는데 아무런 Type의 블록도 적용할 수 없을 때     
    int y = -1, x = -1;

    for(int i=0; i<inputArr.size(); i++)
    {
        for(int j=0; j<inputArr[i].size(); j++)
        {
            if(inputArr[i][j] == WHITE) 
            {
                // 4. 배열을 덮는 작업을 위한 재귀를 여기에서 호출하지 않고 
                // 여기에서는 먼저 덮을 수 있는 인덱스를 찾는다
                y = i;
                x = j;
                break;
            }
            // y가 -1이 아니라는 것만으로도 x, y가 할당이 되었고 흰색 칸을 찾았다는 의미가 된다
            if(y != -1) break; // 흰색 칸을 찾았으므로 더 이상 찾을 필요가 없음
        }
    }

    // 재귀 종료 조건 
    // - y가 -1이라는 건 흰색칸이 할당되지 않았다는 것이므로 재귀를 종료한다
    if(y == -1) return 1;

    int ret = 0;

    // 네 가지 경우의 블록을 검색한다
    for (int type = 0; type < 4; type++) // 네가지 경우의 블록을 검색
    {
        // 흰색칸을 덮을 수 있는 상황이면 덮고나서
        if (Search(type, y, x, inputArr, 1))
        {
            // 재귀 호출을 진행 
            // 네 가지 중 한 개를 덮은 게임판으로 또 다음 흰색 칸을 덮기를 시도한다
            ret += CoverBoard(inputArr); /* 재귀호출 */
        }
        // 덮었던 블록을 지워야 다음 블록의 경우의 수를 확인할 수 있다 
        Search(type, y, x, inputArr, -1); // 덮었던 블록을 치워야 다음 호출 때 확인할 수 있음 ******
    }
    return ret;

}

int main(void)
{


    int tmp_h = 3;
    int tmp_w = 7;
    vector<vector<int>> tmp_input_0 = { {1, 0, 0, 0, 0, 0, 1}, 
                                     {1, 0, 0, 0, 0, 0, 1},
                                     {1, 1, 0, 0, 0, 1, 1}};
    vector<vector<int>> tmp_input_1 = { {1, 0, 0, 0, 0, 0, 1}, 
                                     {1, 0, 0, 0, 0, 0, 1},
                                     {1, 1, 0, 0, 1, 1, 1}};

    PrintBoard(tmp_input_1);
    

    cout<<CoverBoard(tmp_input_1)<<endl;

}

void PrintBoard(vector<vector<int>> &inputArr)
{
    for(int i=0; i<inputArr.size(); i++)
    {
        for(int j=0; j<inputArr[i].size(); j++)
        {
            cout<<inputArr[i][j];
        }
        cout<<endl;
    }
    cout<<"----------------------------------" <<endl;
}