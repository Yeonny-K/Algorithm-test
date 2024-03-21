#include <vector>
#include <set>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    set<vector<vector<int>>> s;
    vector<vector<int>> temp;
    vector<vector<int>> rtemp;
    int curSize = 0;
    vector<int> co = {0,0};
    unordered_map<string, int> m;
    string t = "";
    string rt = "";
    bool flag = true;
    
    for(int i=0; i<dirs.size(); i++)
    {
        flag = true;
        t.clear();
        rt.clear();

        if(dirs[i]=='U') //상
        {
            if(co[1]+1 <=5) //초과하지 않을 경우
            {
                temp.push_back(co);
                co[1]++;
                temp.push_back(co);
                t+=to_string(temp[0][0]);
                t+=to_string(temp[0][1]);
                t+=to_string(temp[1][0]);
                t+=to_string(temp[1][1]);
                rt+=to_string(temp[1][0]);
                rt+=to_string(temp[1][1]);
                rt+=to_string(temp[0][0]);
                rt+=to_string(temp[0][1]);
                temp.clear();
            }
            else //초과하면
            { 
                continue;
            }
        }
        if(dirs[i]=='D') //하
        {
            if(co[1]-1 >= -5) //초과하지 않을 경우
            {
                temp.push_back(co);
                co[1]--;
                temp.push_back(co);
                t+=to_string(temp[0][0]);
                t+=to_string(temp[0][1]);
                t+=to_string(temp[1][0]);
                t+=to_string(temp[1][1]);
                rt+=to_string(temp[1][0]);
                rt+=to_string(temp[1][1]);
                rt+=to_string(temp[0][0]);
                rt+=to_string(temp[0][1]);
                temp.clear();
            }
            else //초과하면
            { 
                continue;
            }
        }
        if(dirs[i]=='L') //좌
        {
            if(co[0]-1 >= -5) //초과하지 않을 경우
            {
                temp.push_back(co);
                co[0]--;
                temp.push_back(co);
                t+=to_string(temp[0][0]);
                t+=to_string(temp[0][1]);
                t+=to_string(temp[1][0]);
                t+=to_string(temp[1][1]);
                rt+=to_string(temp[1][0]);
                rt+=to_string(temp[1][1]);
                rt+=to_string(temp[0][0]);
                rt+=to_string(temp[0][1]);
                temp.clear();
            }
            else //초과하면
            { 
                continue;
            }
        }
        if(dirs[i]=='R') //우
        {
            if(co[0]+1 <=5) //초과하지 않을 경우
            {
                temp.push_back(co);
                co[0]++;
                temp.push_back(co);
                t+=to_string(temp[0][0]);
                t+=to_string(temp[0][1]);
                t+=to_string(temp[1][0]);
                t+=to_string(temp[1][1]);
                rt+=to_string(temp[1][0]);
                rt+=to_string(temp[1][1]);
                rt+=to_string(temp[0][0]);
                rt+=to_string(temp[0][1]);
                temp.clear();
            }
            else //초과하면
            { 
                continue;
            }
        }
        
        m[t]++;
        m[rt]++;
        if(m[t] > 1 || m[rt] > 1)
            flag = false;
        
        if(flag)
            answer++;
    }
    return answer;
}