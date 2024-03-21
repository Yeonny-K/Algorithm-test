#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
map<int, int> m;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    if(a.second == b.second) //value가 같다면
        return a.first < b.first; //key 기준 오름차순 정렬
    return a.second > b.second; //value가 다르다면, value 기준 내림차순 정렬
        
        
}


int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int nums = 0;
   
    for(int i=0; i<tangerine.size(); i++) //key, value 조합 만들기 위해 일단 map 생성
    {
        m[tangerine[i]]++;
    }
    vector<pair<int, int>> v(m.begin(), m.end()); //value 기준 정렬을 위해 vector에 복사
    sort(v.begin(), v.end(), cmp); // 정렬, 이후로는 vector로만 사용
    
 /*   for(auto num : v)
    {
        cout<<num.first<<num.second<<endl;
    }*/
    
 
        for(auto vv : v)
        {
            nums+=vv.second; //귤 개수 더하기
            answer++; //귤의 종류수 더하기
            if(nums >= k) //더한 귤이 얻어야 하는 k보다 같거나 커졌으면 리턴
                return answer;
        }



    return answer;
}