#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    int MaxIdx = 0;
    queue<pair<int,int>> q;
    
    for(int i=0; i<priorities.size(); i++)
    {
        q.push(make_pair(priorities[i],i));
    }
    
    sort(priorities.begin(), priorities.end(), greater<int>());
    
    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        
        if(cur.first == priorities[MaxIdx])
        {
            if(cur.second == location)
                return answer;
            
            MaxIdx++;
            answer++;
        }
        else
            q.push(cur);
    }
    
    return answer;
}