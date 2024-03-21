#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int Idx = 0;
    bool flag = true;
    int cnt = 0;
    int num = 0;
    
    for(int i=0; i<skill_trees.size(); i++)
    {
        for(int j=0; j<skill_trees[i].size(); j++)
        {
            char temp = skill_trees[i][j];
            if(find(skill.begin(), skill.end(), temp)==skill.end())
            {
                cnt++;
                continue;
            }
            Idx = find(skill.begin(), skill.end(), temp) - skill.begin();
            if(num==Idx)
                num++;
            else
                flag = false;
        }
        if(cnt==skill_trees[i].size())
        {
            answer++;
        }
        else if(flag)
        {
            answer++;
        }
        
        flag = true;
        cnt = 0;
        num = 0;
        
    }
    return answer;
}