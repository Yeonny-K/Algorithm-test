#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    int person = 0;
    int cnt = 0;
    int idx = 0;
   
    for(int i=0; i<words.size(); ++i) //이 for문은, kick을 놓고 tank비교 -> know를 놓고 tank, kick 비교 -> wheel을 놓고 tank, kick, know를 비교 ... 
    {
        for(int j=0; j<i; ++j) //같은 단어가 있다
        {
            if(words[j]==words[i])
            {
            
                person = (i+1)%n == 0 ? n : (i+1)%n;
                cnt = (i+1)%n == 0 ? (i+1)/n : (i+1)/n +1;    
                answer.push_back(person);
                answer.push_back(cnt);
                return answer;
            }
        }
        
        if( ((i+1)!=words.size()) && (words[i][words[i].size()-1] != words[i+1][0]) )
        {
            person = (i+2)%n == 0 ? n : (i+2)%n;    
            cnt = (i+2)%n == 0 ? (i+2)/n : (i+2)/n +1;  
            answer.push_back(person);
            answer.push_back(cnt);
            return answer;
        }
        
       
        
    }
    
    answer.push_back(0);
    answer.push_back(0);


    return answer;
}