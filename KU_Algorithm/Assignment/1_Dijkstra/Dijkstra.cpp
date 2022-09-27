#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

class TREE {
public:
    int a, b, w;
};

// Priority Queue
class PriorityQueue
{
public:
    int n;
    TREE Arr[1000];
    PriorityQueue();
    TREE Delete();
    void Insert(TREE x);
    int IsEmpty();
    inline bool IsNotFirstEdge(int idx) { return idx > 1; }
    inline bool IsSmallerThanParentWeight(int idx) { return Arr[idx].w < Arr[idx/2].w; }
};

PriorityQueue::PriorityQueue()
{
    n = 0;
}

int PriorityQueue::IsEmpty()
{
    return n == 0;
}

void PriorityQueue::Insert(TREE x)
{
    int i;
    Arr[n+1] = x; // 현재 노드가 n개이므로 다음 칸에 할당
    i = n+1; // i는 현재 노드를 가리키도록 설정
    n = n+1; // 개수 업데이트
    // 현재 넣은 엣지의 weight가 첫 번째 노드가 아니고, 
    // weight가 부모 노드보다 작으면 교환

    // 가장 작은 weight를 가장 상위 노드로 올리기 위해 정렬
    while(IsNotFirstEdge(i) && IsSmallerThanParentWeight(i)) {
        swap(Arr[i], Arr[i/2]);
        i = i/2; // i를 부모 노드의 인덱스로 업데이트해서 다시 그의 부모 노드와 비교하도록 함
    }
}

TREE PriorityQueue::Delete()
{
    // 우선순위 큐는 가장 상위 노드를 삭제하므로, 인덱스 1에 있는 노드를 삭제하기 전 값 캐싱
    TREE cachedTree = Arr[1]; 
    int curNodeIdx, exchangeNodeIdx;
    // 노드가 한 개 뿐인 경우
    if (n == 1) {
        n = 0;
        return cachedTree;
    }
    // 가장 하위 노드를 최상위 노드로 보냄 
    Arr[1] = Arr[n];

    curNodeIdx = 1; // 마지막 원소의 자리를 찾아주기 위해 인덱스를 처음으로 이동
    n = n - 1; // 개수 업데이트 

    while(1) {

        bool isLastNode = curNodeIdx * 2 > n;
        bool hasOnlyLeftNode = curNodeIdx * 2 + 1 > n;

        int leftNodeIdx = curNodeIdx * 2;
        int rightNodeIdx = curNodeIdx * 2 + 1;

        // 왼쪽 자식 노드의 인덱스가 n보다 큰 경우는 없으므로 끝
        if(isLastNode) {
            break;
        }
        // 왼쪽 자식만 있는 경우
        else if(hasOnlyLeftNode) {
            // 왼쪽 자식보다 현재 노드가 더 크면 교환
            bool isLargerThanLeftNode = Arr[leftNodeIdx].w < Arr[curNodeIdx].w;
            if(isLargerThanLeftNode) {
                swap(Arr[leftNodeIdx], Arr[curNodeIdx]);
                curNodeIdx = leftNodeIdx;
            }
            else {
                break;
            }
        }
        // 왼쪽 자식과 오른쪽 자식 노드 둘 다 존재하는 경우
        else {
            // 현재 노드가 왼쪽 자식, 오른쪽 자식보다 큰 경우
            bool isLargerThanBothNode = Arr[curNodeIdx].w > Arr[leftNodeIdx].w && Arr[curNodeIdx].w > Arr[rightNodeIdx].w;
            bool isLargerThanOnlyLeftNode = Arr[curNodeIdx].w > Arr[leftNodeIdx].w && Arr[curNodeIdx].w <= Arr[rightNodeIdx].w;
            bool isLargerThanOnlyRightNode = Arr[curNodeIdx].w > Arr[rightNodeIdx].w && Arr[curNodeIdx].w <= Arr[leftNodeIdx].w;
            
            if(isLargerThanBothNode) {
                bool isLeftNodeSmallerThanRightNode = Arr[leftNodeIdx].w < Arr[rightNodeIdx].w;
                if(isLeftNodeSmallerThanRightNode) {
                    exchangeNodeIdx = leftNodeIdx;
                }
                else {
                    exchangeNodeIdx = rightNodeIdx;
                }
                // 둘 중 작은 것과 교환
                swap(Arr[curNodeIdx], Arr[exchangeNodeIdx]);
                curNodeIdx = exchangeNodeIdx; // 이후 노드 확인
            }
            // 왼쪽 노드보다는 크지만 오른쪽 노드보다는 작거나 같음 
            else if(isLargerThanOnlyLeftNode) {
                exchangeNodeIdx = leftNodeIdx;
                swap(Arr[curNodeIdx], Arr[exchangeNodeIdx]);
                curNodeIdx = exchangeNodeIdx;
            }
            // 오른쪽 노드보다는 크지만 왼쪽 노드보다는 작거나 같음 
            else if(isLargerThanOnlyRightNode) {
                exchangeNodeIdx = rightNodeIdx;
                swap(Arr[curNodeIdx], Arr[exchangeNodeIdx]);
                curNodeIdx = exchangeNodeIdx;
            }
            else { // 현재노드가 가장 작은 노드라면 아무것도 하지 않음
                break; 
            }
        }
    }
    return cachedTree;
}

PriorityQueue priorityQueue;

int n, m;
vector<pair<int, int>> Edges[1000];
int M[1000];
vector<int> P[1000];

int main()
{
    // a, b는 노드이고, w는 weight
    int c, i, a, b, w;
    TREE x, y;
    // 몇 n x m 의 입력인지
    scanf("%d %d", &n, &m);
    for (i=0; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &w);

        Edges[a].push_back(make_pair(b, w));
        Edges[b].push_back(make_pair(a, w));
    }

    // 1. Source 노드를 V_후보 집합에 추가 및 D[S] = 0 설정 , else D[I] = INF
    // 2. V_후보 집합의 원소 v 에 대하여 D[v] 가 최소인 v를 V_후보 집합에서 제거하고 V_명확 집합에 추가
    // 3. v와 direct edge가 존재하는 v_another에 대해 v_another가 V_명확 집합에 존재하지 않을 경우 V_후보 집합에 추가
    // 4. D[v_another]를 갱신 min(D[v_another], D[v] + w(v, v_another)
    // 5.  V_후보 집합의 원소가 존재하지 않을 때까지 2-4 반복

    for(i=0; i<=n; i++)
    {
        M[i] = 1000000;
    }
    c = 1; M[c] = 0; // 지금 노드

    // 현재 노드의 모든 엣지를 넣는 것
    for (i = 0; i < Edges[c].size(); i++) {
        // 모든 엣지를 큐에 다 집어넣음
        x.a = c;
        x.b = Edges[c][i].first;
        x.w = M[c] + Edges[c][i].second;
        priorityQueue.Insert(x);
    }

    while(priorityQueue.IsEmpty() == 0)
    {
        // 현재 노드 기준으로 가장 가까운 노드를 찾음
        x = priorityQueue.Delete();
        // 가장 가까운 노드의 값을 M에 넣어놓으므로 1000000 보다 작으면 그게 최소라서 더 볼 것이 없음 
        if(M[x.b] < 1000000)
        {
            if(M[x.b] == x.w)
            {
                printf("Edge from Node %d to Node %d of Total Path Length %d added. Previous node %d.\n", x.a, x.b, x.w, x.a);
                // 이전 노드를 넣어서 경로를 기억
                P[x.b].push_back(x.a);
            }
            else
            {
                printf("IGNORED Edge from Node %d to Node %d of Total Path Length %d selected.\n", x.a, x.b, x.w);
            }
        }
        else
        {            
            printf("Edge from Node %d to Node %d of Total Path Length %d selected. Previous node %d.\n", x.a, x.b, x.w, x.a);
            M[x.b] = x.w;
            // 현재 노드에서 가장 가까운 노드를 찾았으므로 그 노드와 연결되어있는 노드들을 순회하면서 경로의 값을 업데이트 해줌.
            for (i = 0; i < Edges[x.b].size(); i++)
            {
                y.a = x.b;
                y.b = Edges[x.b][i].first;
                y.w = M[x.b] + Edges[x.b][i].second;

                priorityQueue.Insert(y);
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
*/