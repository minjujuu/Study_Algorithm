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

int main()
{
    // 1. 입력 받기
    // 2. 입력받은 정보를 엣지 배열에 다 넣기 (연결된 노드 번호 및 그 노드로 향하는 엣지 웨이트)
    // 3. 임의의 노드 (여기에선 1번 노드)를 현재 노드로 지정하고 들렸다는 마킹
    // 4. 현재 노드의 모든 엣지를 큐에 넣기 (가장 weight가 적은 걸 알기 위해)
    // 5. 큐에 모두 빌 때까지 다시 다 꺼내면서 다음을 확인 (큐가 비었다는 건 주변 노드가 없다는 것 )
    // - 사이클을 만드는지 (두 노드가 이미 마킹되어 있으면 사이클을 만드는 엣지임)
    // - 사이클을 만들지 않으면 현재 노드의 주변 노드와 그 엣지를 다시 큐에 모두 추가 

    int n, m;
    TREE x, y;
    int a, b, w;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        Edges[a].push_back(make_pair(b, w));
        Edges[b].push_back(make_pair(a, w));
    }

    int curIdx = 1; 
    M[curIdx] = 1; 

    for(int i = 0; i < Edges[curIdx].size(); i++) 
    {
        x.a = curIdx;
        x.b = Edges[curIdx][i].first;
        x.w = Edges[curIdx][i].second;
        priorityQueue.Insert(x);
    }

    while(priorityQueue.IsEmpty() == 0)
    {
        y = priorityQueue.Delete();

        bool isCycle = M[y.a] == 1 && M[y.b] == 1;
        if(isCycle) {
            continue;
        }
        else {
            printf("Edge from Node %d to Node %d of Weight %d selected.\n", y.a, y.b, y.w);
            curIdx = y.b;
            M[curIdx] = 1;
            
            for(int i = 0; i < Edges[curIdx].size(); i++)
            {
                x.a = curIdx;
                x.b = Edges[curIdx][i].first;
                x.w = Edges[curIdx][i].second;
                priorityQueue.Insert(x);
            }
        }
    }

    return 0;
}