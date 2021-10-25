#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// 입력받은 배열에 대한 너비우선 탐색 
int bfs(const vector<int> & perm)
{
    int n = perm.size(); // 입력받은 배열의 크기
    vector<int> sorted = perm; // sorted 배열에 입력받은 배열을 그대로 넣음
    sort(sorted.begin(), sorted.end()); // sorted 배열을 정렬 (입력받은 배열의 정렬된 상태의 배열이 됨)

    queue<vector<int>> q; // 방문해야 할 노드를 기록하는 queue
    map<vector<int>, int> distance; // start부터 해당 노드까지의 최단거리 (이번에는 노드가 정수배열이라 map을 사용)

    distance[perm] = 0;
    q.push(perm); // 시작점을 방문해야 할 노드 목록에 넣음
    while(!q.empty()) // 큐가 비어있지 않으면 반복
    {
        // 노드가 정수배열이라서 here의 자료형도 정수배열이 됨
        vector<int> here = q.front(); // 현재 노드를 큐에 가장 앞에 있는 노드로 설정 (bfs - 먼저 발견된 곳이 먼저 방문되어야 함)
        q.pop(); // 방문한 노드는 큐에서 제거

        if(here == sorted) // 현재 노드가 정렬된 배열 노드이면
            return distance[here]; // 탐색을 종료하고 반환 (거리가 perm 정렬하는데 필요한 뒤집기 연산 수가 됨)

        int cost = distance[here]; // 현재노드까지의 거리를 cost에 저장
        for(int i=0; i<n; i++) // i는 뒤집을 구간의 시작 인덱스를 가리킴
        {
            for(int j=i+2; j<=n; j++) // j는 뒤집을 구간의 마지막 인덱스를 가리킴 ?
            {
                reverse(here.begin() + i, here.begin() + j); // 뒤집기 연산

                // 뒤집기 연산을 한 노드에 대한 처리
                if(distance.count(here) == 0) // 처음보는 노드이면 
                {
                    distance[here] = cost + 1; // 해당 노드에 대한 비용을 추가
                    q.push(here); // 방문해야 할 노드에 추가시킴 
                }
                reverse(here.begin() + i, here.begin() + j); // 뒤집은 배열을 다시 되돌림 
            }
        }
    }
    return -1;
}

int main(void)
{
    int testcase = 0;
    cin>>testcase;
    int size = 0;
    vector<int> result; // 결과를 저장할 배열
    for(int i=0; i<testcase; i++) // 테스트케이스 만큼 반복
    {
        cin>>size;
        
        vector<int> perm;
        int tmp = 0;
        for(int j=0; j<size; j++) // 배열을 입력받음
        {
            cin>>tmp;
            perm.push_back(tmp);            
        }

        int anss = bfs(perm); // bfs를 통해 답을 계산
        result.push_back(anss); // 결과 배열에 넣음
    }

    // 결과 출력
    vector<int> ::iterator iter;
    for(iter=result.begin(); iter != result.end(); iter++)
    {
        cout<<*iter<<endl;
    }

    return 0;
}