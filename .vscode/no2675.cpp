#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int repeat = 0;
    cin >> repeat;
    
    vector <string> answers;
    for(int i=0; i<repeat; i++) {
        int count = 0;
        cin >> count; // 반복 횟수 입력받음
        string input;
        cin >> input; // 문자열 입력받음

        string answer;
        int idx = 0;
        for(int j=0; j<input.size(); j++)
        {
            for (int k = 0; k < count; k++)
            {
                answer.push_back(input[j]);
            }            
        }
        answers.push_back(answer);        
    }

    vector<string>::iterator iter;
    for(iter = answers.begin(); iter != answers.end(); iter++)
    {
        cout<< *iter<<endl;
    }
    return 0;
}