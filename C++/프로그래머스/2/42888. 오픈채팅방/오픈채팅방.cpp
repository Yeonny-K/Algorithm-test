#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> action;
    vector<string> id;
    map<string,string> name;

    for(int i = 0; i < record.size() ; i++)
    {
        stringstream ss(record[i]);
        string temp;
        if(ss >> temp) action.push_back(temp);
        if(ss >> temp) id.push_back(temp);
        if(ss >> temp) {
            name[id.back()] = temp;
        }
    }
    
    for(int i=0; i<action.size(); i++)
    {
        string s = "";
        if(action[i] == "Enter")
        {
            s += name[id[i]];
            s += "님이 들어왔습니다.";
            answer.push_back(s);
        }
        if(action[i] == "Leave")
        {
            s += name[id[i]];
            s += "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    
   /* for(int i=0; i<action.size(); i++)
    {
        cout<<action[i]<<"/"<<endl;
    }
    for(int i=0; i<id.size(); i++)
    {
        cout<<id[i]<<"/"<<endl;
    }
    
    for(auto mm:name)
    {
        cout<<mm.first<<"/"<<mm.second<<endl;
    }*/
    return answer;
}