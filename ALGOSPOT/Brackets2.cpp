#include <iostream>
#include <stack>
#include <vector>
using namespace std;
#define SIZE 3

bool IsOpenBracket(vector<char> & open, char target);
bool IsMatch(char open, char close);
bool SearchBracketCouple(string input, vector<char> open_bracket);

int main(void)
{
    vector<char> open_bracket = {'(', '{', '['};
    vector<char> close_bracket = { ')', '}', ']'};
    
    vector<string> inputs;
    int testcase = 0;
    cin>>testcase;
    for(int i=0; i<testcase; i++)
    {
        string temp;
        cin>>temp;
        inputs.push_back(temp);
    }

    for(int i=0; i<testcase; i++)
    {
        if(inputs[i].size() % 2 != 0)
        {
            cout<<"NO"<<endl;
            continue;
        }

        if(SearchBracketCouple(inputs[i], open_bracket))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
            
    }

    return 0;
}

bool SearchBracketCouple(string input, vector<char> open_bracket)
{
     stack<char> open;
    // 1. string을 순회한다
    // 2. 여는 괄호이면 push
    // 3. 닫는 괄호이면 stack의 top과 비교
    // - 맞으면 여는 괄호 pop
    // - 틀리면 탐색 종료
    
    for(int i=0; i<input.size(); i++)
    {
        // cout<<input_1[i]<<endl;
        if(IsOpenBracket(open_bracket, input[i]))
        {
            open.push(input[i]);
        }
        else
        {
            if(!open.empty())
            {
                if(IsMatch(open.top(), input[i]))
                {
                    open.pop();
                }
                else
                {
                    return false;
                }
            }
            else
                return false; 
        }
    }

    if(open.empty()) // 여는 괄호만 있어서 stack이 비워지지 못하면 false
        return true;
    else
        return false;

}
bool IsOpenBracket(vector<char> & open, char target)
{
    for(int i=0; i<open.size(); i++)
    {
        if(target == open[i])
        {
            return true;
        }
    }
    return false;
}

bool IsMatch(char open, char close)
{
    if(open == '{' && close == '}' )
        return true;
    else if(open == '[' && close == ']')
        return true;
    else if(open == '(' && close == ')')
        return true;
    else
        return false;

}
