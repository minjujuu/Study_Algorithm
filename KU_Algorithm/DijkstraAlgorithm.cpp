#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

// a에다가 b를 연결하는 거고, w는 weight임
class TRI {
public:
    int a, b, w;
};

// Priority Queue
class PQ {
public:
    int n;
    TRI Arr[1000];
    PQ();
    TRI Delete();
    void Insert(TRI x);
    int isEmpty();
};

PQ::PQ()
{
    n = 0;
}

int PQ::isEmpty()
{
    return n == 0;
}

void PQ::Insert(TRI x)
{
    // n개가 들어있음 (1부터 n까지)
    // 넘치지 않도록 n에다가 넣어야 함
    int i;
    Arr[n + 1] = x; // 1부터이고 0은 안씀
    i = n + 1;
    n = n + 1;
    // w가 Parent보다 작으면 바꿔야 함 
    while(i > 1 && Arr[i].w < Arr[i/2].w) {
        swap(Arr[i], Arr[i/2]);
        i = i/2; // 부모로 간 것 
    }
}

TRI PQ::Delete()
{
    TRI ret = Arr[1]; // save return value 
    int i, j;
    if(n == 1) { n = 0; return ret; } // special case 
    Arr[1] = Arr[n]; // 1부터 n까지 쓰고 있으니까 n번을 1로 보냄

    i = 1; n = n-1;
    while(1) {
        // 왼쪽 child가 n보다 크면 끝난 것
        if (i*2 > n) {
            break;
        }
        else if(i*2+1 > n) { // Left Child Only
            //왼쪽 차일드랑 비교해서 내가 더 크면 바꾸는 것
            if (Arr[i*2].w < Arr[i].w)
            {
                swap(Arr[i*2], Arr[i]);
                i = i*2;
            }
            else {
                break;
            }
        }
        else { // Left and Right Child exists
            // 둘 중 작은 거랑 교환해야 함. 케이스가 많음
            // 내가 둘 다 보다 큰 경우
            if(Arr[i].w > Arr[i*2].w && Arr[i].w > Arr[i*2+1].w) {
                if(Arr[i*2].w < Arr[i*2+1].w) {
                    j = i*2;
                }
                else {
                    j = i*2+1;
                }
                // 둘 중 작은 거랑 바꿈 
                swap(Arr[i], Arr[j]);
                i = j; // 그리고 그 아래쪽을 보러 감
            }
            // 오른쪽 꺼보다는 작거나 같음 
            else if(Arr[i].w > Arr[i*2].w && Arr[i].w <= Arr[i*2+1].w) {
                // 무조건 왼쪽 꺼랑 바꾸어야 함
                j = i *2;
                swap(Arr[i], Arr[j]);
                i = j; // 그리고 그 아래쪽을 보러 감
            }
            // 왼쪽 꺼보다는 작거나 같음 
            else if(Arr[i].w <= Arr[i*2].w && Arr[i].w > Arr[i*2+1].w) {
                j = i *2+1;
                swap(Arr[i], Arr[j]);
                i = j; // 그리고 그 아래쪽을 보러 감
            }
            // 내가 그냥 제일 작은 경우 
            else {
                break; // 할 일 없음 
            }
        }
    }
    return ret;
}

PQ Q;

int n, m; 
vector<pair<int, int>> Edges[1000];
int M[1000]; // shortest path length
vector<int> P[1000]; // previous node
int main()
{
    // a, b는 노드이고, w는 weight
    int c, i, a, b, w;
    TRI x, y;
    // 몇 n x m 의 입력인지
    scanf("%d %d", &n, &m);
    for (i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        // '노드 번호'와 '연결된 엣지의 weight'를 pair로 저장
        // 각 노드에 해당하는 인덱스에 저장해서 
        // 배열의 인덱스 확인 시 해당 노드에 연결된 노드와 그 노드로 향하는 엣지의 weight를 알 수 있도록 함 
        Edges[a].push_back(make_pair(b, w));
        Edges[b].push_back(make_pair(a, w));
    }
    for (i=1; i<=n; i++)
    {
        M[i] = 1000000;
    }
    
    c = 1; M[c] = 0; // 소스 노드
    // 현재 노드의 모든 엣지를 넣는 것
    for (i = 0; i < Edges[c].size(); i++) {
        // 모든 엣지를 큐에 다 집어넣음
        x.a = c;
        x.b = Edges[c][i].first;
        x.w = M[c] + Edges[c][i].second; // 기존 거리를 더해줌
        Q.Insert(x);
    }

    while (Q.isEmpty() == 0) {
        // 엣지를 꺼냄
        y = Q.Delete();

        // 백만보다 작으면 이미 가장 짧은 패스가 발견되었다는 의미이므로 아무것도 안함
        if (M[y.b] < 1000000) {
            // 모든 경로를 기억하기 위해 같으면 기억
            if(M[y.b] == y.w) {
                printf("Edge from Node %d to Node %d of Total Path Length %d added. Previous node %d.\n", y.a, y.b, y.w, y.a);
                P[y.b].push_back(y.a);
            }
            else {
                printf("IGNORED Edge from Node %d to Node %d of Total Path Length %d selected.\n", y.a, y.b, y.w);
            }
        }
        else {
            printf("Edge from Node %d to Node %d of Total Path Length %d selected. Previous node %d.\n", y.a, y.b, y.w, y.a);
            c = y.b;
            M[c] = y.w;
            P[y.b].push_back(y.a); // 이전 노드 기억 
            // c에 있는 주변 노드를 큐에 추가
            // 현재 노드의 모든 엣지를 넣는 것
            for (i = 0; i < Edges[c].size(); i++)
            {
                // 모든 엣지를 큐에 다 집어넣음
                x.a = c;
                x.b = Edges[c][i].first;
                x.w = M[c] + Edges[c][i].second;
                Q.Insert(x);
            }
        }
    }

    return 0;
}

/* MST 예제 그래프
5 10
1 2 10
2 3 1
1 5 6
1 4 5
2 4 4
2 4 3
4 5 2
3 4 9
3 5 4
5 3 6
Edge from Node 1 to Node 4 of Total Path Length 5 selected.
Edge from Node 1 to Node 5 of Total Path Length 6 selected.
Edge from Node 4 to Node 2 of Total Path Length 8 selected.
Edge from Node 2 to Node 3 of Total Path Length 9 selected.

or

Edge from Node 1 to Node 4 of Total Path Length 5 selected. Previous node 1.
Edge from Node 1 to Node 5 of Total Path Length 6 selected. Previous node 1.
IGNORED Edge from Node 4 to Node 5 of Total Path Length 7 selected.
Edge from Node 4 to Node 2 of Total Path Length 8 selected. Previous node 4.
IGNORED Edge from Node 5 to Node 4 of Total Path Length 8 selected.
IGNORED Edge from Node 4 to Node 2 of Total Path Length 9 selected.
Edge from Node 2 to Node 3 of Total Path Length 9 selected. Previous node 2.
IGNORED Edge from Node 4 to Node 1 of Total Path Length 10 selected.
IGNORED Edge from Node 5 to Node 3 of Total Path Length 10 selected.
IGNORED Edge from Node 3 to Node 2 of Total Path Length 10 selected.
IGNORED Edge from Node 1 to Node 2 of Total Path Length 10 selected.
IGNORED Edge from Node 2 to Node 4 of Total Path Length 11 selected.
IGNORED Edge from Node 5 to Node 1 of Total Path Length 12 selected.
IGNORED Edge from Node 5 to Node 3 of Total Path Length 12 selected.
IGNORED Edge from Node 2 to Node 4 of Total Path Length 12 selected.
IGNORED Edge from Node 3 to Node 5 of Total Path Length 13 selected.
IGNORED Edge from Node 4 to Node 3 of Total Path Length 14 selected.
IGNORED Edge from Node 3 to Node 5 of Total Path Length 15 selected.
IGNORED Edge from Node 2 to Node 1 of Total Path Length 18 selected.
IGNORED Edge from Node 3 to Node 4 of Total Path Length 18 selected.
*/

/* 같은 경로가 존재하는 예제 그래프
5 10
1 2 10
2 3 1
1 5 7
1 4 5
2 4 4
2 4 3
4 5 2
3 4 9
3 5 2
5 3 6
Edge from Node 1 to Node 4 of Total Path Length 5 selected. Previous node 1.
Edge from Node 1 to Node 5 of Total Path Length 7 selected. Previous node 1.
Edge from Node 4 to Node 2 of Total Path Length 8 selected. Previous node 4.
Edge from Node 5 to Node 3 of Total Path Length 9 selected. Previous node 5.

or

Edge from Node 1 to Node 4 of Total Path Length 5 selected. Previous node 1.
Edge from Node 1 to Node 5 of Total Path Length 7 selected. Previous node 1.
Edge from Node 4 to Node 5 of Total Path Length 7 added. Previous node 4.
Edge from Node 4 to Node 2 of Total Path Length 8 selected. Previous node 4.
Edge from Node 5 to Node 3 of Total Path Length 9 selected. Previous node 5.
IGNORED Edge from Node 4 to Node 2 of Total Path Length 9 selected.
Edge from Node 2 to Node 3 of Total Path Length 9 added. Previous node 2.
IGNORED Edge from Node 5 to Node 4 of Total Path Length 9 selected.
IGNORED Edge from Node 4 to Node 1 of Total Path Length 10 selected.
IGNORED Edge from Node 3 to Node 2 of Total Path Length 10 selected.
IGNORED Edge from Node 1 to Node 2 of Total Path Length 10 selected.
IGNORED Edge from Node 3 to Node 5 of Total Path Length 11 selected.
IGNORED Edge from Node 2 to Node 4 of Total Path Length 11 selected.
IGNORED Edge from Node 2 to Node 4 of Total Path Length 12 selected.
IGNORED Edge from Node 5 to Node 3 of Total Path Length 13 selected.
IGNORED Edge from Node 4 to Node 3 of Total Path Length 14 selected.
IGNORED Edge from Node 5 to Node 1 of Total Path Length 14 selected.
IGNORED Edge from Node 3 to Node 5 of Total Path Length 15 selected.
IGNORED Edge from Node 2 to Node 1 of Total Path Length 18 selected.
IGNORED Edge from Node 3 to Node 4 of Total Path Length 18 selected.
*/
