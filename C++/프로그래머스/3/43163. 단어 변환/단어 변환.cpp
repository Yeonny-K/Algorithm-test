#include <string>
#include <vector>

using namespace std;

int visited[60];
int answer = 0;

bool cmp_str(string A, string B)
{
    int n = A.size();
    int cnt = 0;
    
    for(int i=0; i<n; i++)
    {
        if(A[i]!=B[i])
            cnt++;
    }
    
    if(cnt==1)
        return true;
    return false;
}

void DFS(string begin, string target, vector<string> words, int step)
{
    if(begin==target)
    {
        answer = step;
        return;
    }
    
    for(int i=0; i<words.size(); i++)
    {
        if((cmp_str(begin, words[i])) && !visited[i])
        {
            visited[i] = true;
            DFS(words[i], target, words, step+1);
            visited[i] = false;
        }
    }
    
    return;
}

int solution(string begin, string target, vector<string> words) {
    
    
    DFS(begin, target, words, 0);
    
    if(answer == words.size())
        answer = 0;
    return answer;
}