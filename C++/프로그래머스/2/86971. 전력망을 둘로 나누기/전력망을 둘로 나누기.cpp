#include <string>
#include <vector>

#define MAX 101

using namespace std;
int graph[MAX][MAX] = {0};
vector<bool> visited;

int DFS(int cur, int n)
{
    if(visited[cur])
        return 0;
    
    visited[cur] = true;
    int ret = 1;
    
    for(int i=1; i<=n; i++)
    {
        if(graph[cur][i])
            ret += DFS(i, n);
    }
    
    return ret;
}


int solution(int n, vector<vector<int>> wires) {
    int answer = 102;
    
    for(int i=0; i<wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];
        graph[x][y] = 1;
        graph[y][x] = 1;
    }
    
    for(int i=0; i<wires.size(); i++)
    {
        int x = wires[i][0];
        int y = wires[i][1];
        graph[x][y] = graph[y][x] = 0;
        
        visited = vector<bool> (n+1, false);
        vector<int> diff;
        
        for(int i=1; i<=n; i++)
        {
            int tmp = DFS(i, n);
            if(!tmp)
                continue;
            diff.push_back(tmp);
        }
        
        answer = min(answer, abs(diff[0]-diff[1]));
        if(answer == 0)
            break;
        
        graph[x][y] = graph[y][x] = 1;
        
    }
    return answer;
}