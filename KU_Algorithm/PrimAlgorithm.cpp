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
int M[1000]; // 마킹용

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
    c = 1; M[c] = 1; // 지금 노드
    // 현재 노드의 모든 엣지를 넣는 것
    for (i = 0; i < Edges[c].size(); i++) {
        // 모든 엣지를 큐에 다 집어넣음
        x.a = c;
        x.b = Edges[c][i].first;
        x.w = Edges[c][i].second;
        Q.Insert(x);
    }
    while (Q.isEmpty() == 0) {
        // 엣지를 꺼냄
        y = Q.Delete();
        // 사이클을 만드는지 봄
        if (M[y.a] == 1 && M[y.b] == 1) {
            continue; // 둘 다 마킹되어 있으면 버림 
        }
        else {
            printf("Edge from Node %d to Node %d of Weight %d selected.\n", y.a, y.b, y.w);
            c = y.b;
            M[c] = 1;
            // c에 있는 주변 노드를 큐에 추가
            // 현재 노드의 모든 엣지를 넣는 것
            for (i = 0; i < Edges[c].size(); i++)
            {
                // 모든 엣지를 큐에 다 집어넣음
                x.a = c;
                x.b = Edges[c][i].first;
                x.w = Edges[c][i].second;
                Q.Insert(x);
            }
        }
    }

    return 0;
}
/*
3 3    (3, 3 짜리 입력 - 노드 3개, 엣지 3개) 
1 2 1  (1, 2 노드를 잇는 weight 1의 엣지)
2 3 4
1 3 2
*/

/*
3 3    
1 2 1  
2 3 4
1 3 2
*/

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
3 5 6
Edge from Node 1 to Node 4 of Weight 5 selected.
Edge from Node 4 to Node 5 of Weight 2 selected.
Edge from Node 4 to Node 2 of Weight 3 selected.
Edge from Node 2 to Node 3 of Weight 1 selected.
*/

/* 1,2,3 붙어있고 4,5가 따로 떨어진 그래프
3 7
1 2 1
2 3 4
1 3 2
1 2 7
4 5 2
4 5 1
4 5 2
Edge from Node 1 to Node 2 of Weight 1 selected.
Edge from Node 1 to Node 3 of Weight 2 selected.
// 노드 개수를 안보고 큐가 비어있으면 끝나게 됨 
*/