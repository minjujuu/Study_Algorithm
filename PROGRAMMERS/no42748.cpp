/** K번째 수 https://programmers.co.kr/learn/courses/30/lessons/42748#
 * 로직
 *  1. commands의 행 개수만큼 반복
    2. n행의 '0번째 숫자-1' 부터 '1번째 숫자'까지 array를 자름
    3. sort를 통해 정렬함
    4. '2번째 숫자-1' 인덱스에 있는 숫자를 answer에 push함
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
  
  // 1. commands의 행 개수만큼 반복
    for(int row=0; row<commands.size(); row++) {
        int i = commands[row][0]-1;
        int j = commands[row][1];
        int k = commands[row][2]-1;

        vector<int> copyArray;
        // 2. n행의 '0번째 숫자-1' 부터 '1번째 숫자'까지 array를 자름
        copyArray.assign(array.begin() + i, array.begin() + j);
        // 3. sort를 통해 정렬함
        sort(copyArray.begin(), copyArray.end());
        // 4. '2번째 숫자-1' 인덱스에 있는 숫자를 answer에 push함
        answer.push_back(copyArray[k]);
    }
    return answer;
}