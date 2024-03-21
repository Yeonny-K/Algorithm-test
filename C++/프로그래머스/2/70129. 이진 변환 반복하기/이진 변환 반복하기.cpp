#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int tmplen = 0;
    int length = 0;
    int cnt = 0;
    int cnt_0 = 0;
    string tmp = "";
    
  
   /* tmp = "";
        tmplen = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        cnt_0 += tmplen - s.size(); //길이 비교하여 제거한 0의 개수 찾기
        length = s.size();
        
        while(length!=0)
        {
            tmp += to_string(length%2);
            length = length/2;
           
        }
            
        cnt++;
        reverse(tmp.begin(), tmp.end());
        s = tmp;     
    cout<<s<<"첫번째"<<endl;
    
        tmp = "";
       tmplen = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        cnt_0 += tmplen - s.size(); //길이 비교하여 제거한 0의 개수 찾기
        length = s.size();
        
        while(length!=0)
        {
            tmp += to_string(length%2);
            length = length/2;
           
        }
            
        cnt++;
        reverse(tmp.begin(), tmp.end());
        s = tmp;
    cout<<s<<"두번째"<<endl;
    
        tmp = "";
    tmplen = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        cnt_0 += tmplen - s.size(); //길이 비교하여 제거한 0의 개수 찾기
        length = s.size();
        
        while(length!=0)
        {
            tmp += to_string(length%2);
            length = length/2;
           
        }
            
        cnt++;
        reverse(tmp.begin(), tmp.end());
        s = tmp;
    cout<<s<<"세번째"<<endl;
    
    tmp = "";
    tmplen = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        cnt_0 += tmplen - s.size(); //길이 비교하여 제거한 0의 개수 찾기
        length = s.size();
        
        while(length!=0)
        {
            tmp += to_string(length%2);
            length = length/2;
           
        }
            
        cnt++;
        reverse(tmp.begin(), tmp.end());
        s = tmp;
    cout<<s<<"네번째"<<endl;*/
    
    while(1)
    {
        tmp = "";
        tmplen = s.size();
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        cnt_0 += tmplen - s.size(); //길이 비교하여 제거한 0의 개수 찾기
        length = s.size();
        
        while(length!=0)
        {
            tmp += to_string(length%2);
            length = length/2;
           
        }
            
        cnt++;
        reverse(tmp.begin(), tmp.end());
        s = tmp;
        
        if(s.size()==1)
            break;
            
    }
    
     answer.push_back(cnt);
     answer.push_back(cnt_0);
    
    return answer;
}