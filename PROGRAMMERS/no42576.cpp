#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    // - participant를 key로 해서 hash map에 숫자를 저장
    // - completion을 순회하면서 participant에서 find함. 찾으면 map에서 지움
    
    // participant를 순회하면서 completion에 동일한 이름이 있는지 찾음.
    // 찾으면 completion에서 삭제 (중복때문에)
    
    // 순회가 끝나면 participant에 남아있는 애를 출력
    

    vector<string>::iterator iter;
    
    for(iter = participant.begin(); iter != participant.end(); iter++) {
        auto it = find(completion.begin(), completion.end(), *iter);
        if(it != completion.end()) {
            participant.erase(remove(participant.begin(), participant.end(), *iter), participant.end());
        }
    }

   
    answer = participant.back();

    return answer;
}