#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int cnt = 1;
    vector<int> H_Index;
    
    sort(citations.begin(), citations.end());
    
    for(int i=0; i<citations.size(); i++)
    {
        cnt = 1;
        for(int j=i+1; j<citations.size(); j++)
        {
            if(citations[i]<=citations[j])
            {
                cnt++;
            }
        }
        if(citations[i] <= cnt)
            H_Index.push_back(citations[i]);        
        else
            H_Index.push_back(cnt);
    }
    sort(H_Index.begin(), H_Index.end());
    answer = H_Index.back();
    
    return answer;
}