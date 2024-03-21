#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

int visited[8];
set<int> s;

bool is_prime(int n)
{
    if(n==0 || n==1)
        return false;
    
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
            return false;
    }
    
    return true;
}

void DFS(string original, string temp)
{
    
        for(int i=0; i<original.size(); i++)
        {
            if(!visited[i])
            {
                visited[i] = true;
                DFS(original, temp+original[i]);
                if(is_prime(stoi(temp+original[i])))
                    s.insert(stoi(temp+original[i]));
                 
                visited[i] = false;
            }
        }
    return;
}

int solution(string numbers) {
    int answer = 0;
    DFS(numbers, "");
    answer = s.size();
    return answer;
}