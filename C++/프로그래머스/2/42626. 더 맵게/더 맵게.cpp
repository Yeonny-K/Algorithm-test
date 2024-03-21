#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int food1 = 0;
    int food2 = 0;
    int new_food = 0;
    priority_queue<int, vector<int>, greater<int>> pq; //오름차순
    
    for(int i=0; i<scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    
    if(pq.top() >= K)
        return 0;
    
    while(!pq.empty())
    {
        food1 = pq.top();
        pq.pop();
        food2 = pq.top();
        new_food = food1 + (food2*2);
        answer++;
        pq.push(new_food);
        pq.pop();       
        if(pq.top() >= K)
        {
            return answer;
        }
        
        if(pq.size()==1 && pq.top()<K)
            return -1;
    }
    return -1;
}