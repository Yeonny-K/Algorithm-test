#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    return a.size() < b.size(); //긴 놈이 뒤로 가게 
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> temp;
    vector<vector<int>> tuple;
    string num = "";
    
    for(int i=0; i<s.size()-1; i++)
    {
        if(isdigit(s[i])!=0)
        {
            num += s[i];
        }
        
        else if (s[i] == ',' && num!="")
        {
            temp.push_back(stoi(num));
            num = "";
        }
        
        else if(s[i]=='}')
        {
          //  cout<<num<<endl;
            temp.push_back(stoi(num));
            tuple.push_back(temp);
            num.clear();
            temp.clear();
        }
    }
    
    
    sort(tuple.begin(), tuple.end(), cmp);
    
  /*  for(int i=0; i<tuple.size(); i++)
    {
        for(int j=0; j<tuple[i].size(); j++)
            cout<<tuple[i][j];
        cout<<"/"<<endl;
    }*/
    
    for(int i=0; i<tuple.size(); i++)
    {
        for(int j=0; j<tuple[i].size(); j++)
        {
            if (find(answer.begin(), answer.end(), tuple[i][j]) == answer.end())
                answer.push_back(tuple[i][j]);
        }
    }
    
    return answer;
}