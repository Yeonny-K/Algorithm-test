#include <string>
#include <vector>
#define MAX 8

using namespace std;
int answer = 0;
vector<bool> visited(MAX, false);

void DFS(vector<vector<int>>& dungeons, int CurTired, int idx, int count)
{
    if(count > answer)
        answer = count;
    
    visited[idx] = true;
    CurTired -= dungeons[idx][1];
    
    for(int i=0; i<dungeons.size(); i++)
    {
        if((visited[i]==false) && (dungeons[i][0]<=CurTired))
        {
            DFS(dungeons, CurTired, i, count+1);
        }
    }
    
    visited[idx] = false;
}


int solution(int k, vector<vector<int>> dungeons) {
    
    for(int i=0; i<dungeons.size(); i++)
    {
        if(k >= dungeons[i][0])
            DFS(dungeons, k, i, 1);
    }
    return answer;
}