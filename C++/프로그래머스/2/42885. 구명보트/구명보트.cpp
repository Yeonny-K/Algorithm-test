#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int min = 0;
    int max = 0;
    int sum = 0;
    int temp = 0;
    priority_queue<int, vector<int>, greater<int>> MinQ; //오름차순큐, 가벼운
    priority_queue<int, vector<int>> MaxQ; //내림차순큐, 무거운
    
    for(int i=0; i<people.size(); i++)
    {
        if(people[i]<=(limit/2)) //가벼운 애들은 오름차순큐에 넣기
        {
            MinQ.push(people[i]);
        }
        else
            MaxQ.push(people[i]);
    }
    
    while( !(MinQ.empty() && MaxQ.empty()) )
    {
        //cout<<"진입확인5"<<endl;
        if(MaxQ.empty()) //무거운애들이 다 나간 거라면 가벼운 애들은 둘씩 짝지어 보트 타면 됨
        {
          // cout<<"진입확인1"<<endl;
            temp = MinQ.size() / 2;
            if((MinQ.size() % 2) == 1)
                temp++;
            answer += temp;
            break;
        }
        if(MinQ.empty()) //가벼운 애들이 다 나간 거라면 무거운 애들은 한명씩 보트 타야함
        {
          //  cout<<"진입확인2"<<endl;
            temp = MaxQ.size();
            answer += temp;
            break;
        }
        
        min = MinQ.top();
        max = MaxQ.top();
        sum = min+max;
       // cout<<min<<"작"<<max<<" 큰"<<endl;
        
        if(sum<=limit)
        {
         //   cout<<"진입확인3"<<endl;
            answer++;
            MinQ.pop();
            MaxQ.pop();
        }
        else
        {
          //  cout<<"진입확인4"<<endl;
            answer++;
            MaxQ.pop();
        }
    }
    
    
    return answer;
}