#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
 
   int answer = 0;
   answer = n - lost.size();

   vector<int> ::iterator iter;
   vector<int> ::iterator tmpIter;
 
   sort(lost.begin(), lost.end());
   sort(reserve.begin(), reserve.end());
 
   // 예외처리: 만약 reserve랑 lost에 똑같은 학생이 있으면
   // reserve와 lost에서 지워주고 수업받을 수 있는 학생의 수인 answer에는 더해주어야 함 
 
   vector<int> inter(lost.size()+reserve.size());
   auto i_iter = set_intersection(lost.begin(), lost.end(), reserve.begin(), reserve.end(), inter.begin());
   inter.erase(i_iter, inter.end());

   vector<int> ::iterator interIter;
   if(inter.size() > 0)
   {
       for (interIter = inter.begin(); interIter != inter.end(); interIter++)
       {
           iter = find(lost.begin(), lost.end(), *interIter);
           if (iter != lost.end())
           {
               lost.erase(iter);
           }
           iter = find(reserve.begin(), reserve.end(), *interIter);
           if (iter != reserve.end())
           {
               reserve.erase(iter);
               answer++;
           }
       }
   }
   

   for(iter = lost.begin(); iter != lost.end(); iter++)
   {
       int curStudent = *iter;
       tmpIter = find(reserve.begin(), reserve.end(), curStudent-1);
       if(tmpIter != reserve.end())
       {
           reserve.erase(tmpIter);
           answer++;
       }
       else
       {
           tmpIter = find(reserve.begin(), reserve.end(), curStudent+1);
           if (tmpIter != reserve.end())
           {
               reserve.erase(tmpIter);
               answer++;
           }
       }
   }

   cout<<answer<<endl;
   return answer;
}