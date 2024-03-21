#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<int> elements) {
    int answer = 0;
    int sum = 0;
    int start = 0;
    int end = 0;
    int cnt = 1;
    int len = elements.size();
    set<int> s;
    
    while(start<len)
    {
        if(cnt > len)
        {
            start++;
            cnt = 1;
        }
        
        for(end=start; end<(start+cnt); end++)
        {
            sum += elements[end%len];
        }
        s.insert(sum);
        sum = 0;
        cnt++;
        
    }
   
    answer = s.size();
    return answer;
}