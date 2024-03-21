#include<bits/stdc++.h>
using namespace std;


int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int row = maps.size();
    int col = maps[0].size();
    
    struct Node
    {
        int row;
        int col;
    };
    
    int visited[101][101] = {0, };
    queue<Node> q;
    q.push({0,0});
    visited[0][0] = 1; // 첫 세팅 만들어놓기
    
    while(!q.empty())
    {
        Node now = q.front();
        q.pop();
        
        if(now.row == row-1 && now.col == col-1)
        {
            answer = visited[row-1][col-1];
            break;
        }
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        
        for(int i=0; i<4; i++)
        {
            int nextRow = now.row + dr[i];
            int nextCol = now.col + dc[i];
            
            // 범위를 벗어났을 때
            if((nextRow < 0) || (nextRow >= row) || (nextCol < 0) || (nextCol >= col))
                continue;
            // 막혔을 때
            if(maps[nextRow][nextCol]==0)
                continue;
            // 방문했을 때
            if(visited[nextRow][nextCol] > 0)
                continue;
            
            visited[nextRow][nextCol] = visited[now.row][now.col] + 1;
            q.push({nextRow, nextCol});
        
        }
    }
    
    if(!answer)
        answer = -1;
    
    
    return answer;
}