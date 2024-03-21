#include <iostream>
#include<string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int index = 0;
    string tmp = "";
    tmp += s[0];
    
    for(int i=1; i<s.size(); i++)
    {
        tmp += s[i];
        index = tmp.size()-1;
        
        if(tmp[index]==tmp[index-1])
        {
           // cout<<"erase"<<endl;
            tmp.erase(tmp.begin()+(index-1), tmp.end());
        }
        //cout<<tmp<<"/"<<index<<endl;
    }
    
    if(tmp=="")
        answer = 1;
    else 
        answer = 0;


    return answer;
}