// 모의고사 https://programmers.co.kr/learn/courses/30/lessons/42840
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> SearchTopStudent(vector<int> answers);

int main(void)
{
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(3);
    answers.push_back(2);
    answers.push_back(4);
    answers.push_back(2);

    vector<int> ans(3, 0);
    ans = SearchTopStudent(answers);
    vector<int>::iterator iter;
    for(iter = ans.begin(); iter != ans.end(); iter++)
    {
        cout<<*iter<<endl;
    }
    return 0;
}

vector<int> SearchTopStudent(vector<int> answers)
{
    vector<int> answer;
    vector<int> answerPattern_1 = {1, 2, 3, 4, 5};
    vector<int> answerPattern_2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> answerPattern_3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

    vector<int> score(3);

    for(int i=0; i<answers.size(); i++)
    {
        if (answers[i] == answerPattern_1[i % answerPattern_1.size()])
            score[0]++;
        if (answers[i] == answerPattern_2[i % answerPattern_2.size()])
            score[1]++;
        if (answers[i] == answerPattern_3[i % answerPattern_3.size()])
            score[2]++;
    }

    int max_score = *max_element(score.begin(), score.end());
    for(int i=0; i<3; i++)
    {
        if(max_score == score[i])
            answer.push_back(i+1);
    }

    return answer;

}
