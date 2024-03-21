#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> dic;
    int a = 65;
    string temp = "";
    string w = "";
    string c = "";
    int Idx = 0;
    int start = 0;
    int end = 0;
    int cnt = 0;
    bool flag = false;
    
    for(int i=0; i<26; i++)
    {
        char c = a+i;
        temp+=c;
        dic.push_back(temp);
        temp = "";
    }
    
    
    for(int i=0; i<msg.length(); i++)
    {
        string s = "";
        s += msg[i];
        int n = 0;
        
        //없을 때까지 계속 붙인다
        while(find(dic.begin(), dic.end(), s)!=dic.end())
        {
            n++;
            s+=msg[i+n];
        }
        
        int idx = find(dic.begin(), dic.end(), s.substr(0,n)) - dic.begin(); //새로 추가한 거 말고 원래 있던 애를 출력해야해서 그 인덱스 찾는 과정
        answer.push_back(idx+1);
        dic.push_back(s);
        i += n-1;
    }
    
    
  
 
    
    

       
    
    return answer;
}