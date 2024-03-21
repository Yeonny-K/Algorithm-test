#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    vector<string> temp;
    int cnt = 0;
    int check = 0;

    
    for(int i=0; i<number.size(); i++)
    {
        for(int j=0; j<number[i]; j++)
        {
            m[want[i]]++;
        }
        
    }
    
    
    for(int i=0; i<=discount.size()-10; i++)
    {
        
        for(auto mm : m)
        {
            cnt = 0;
            for(int j=i; j<i+10; j++)
                {
                    if(mm.first == discount[j])
                    {
                       // cout<<"진입1/"<<mm.first<<"/"<<discount[j]<<endl;
                        cnt++; //할인 품목 있으면 cnt 추가  
                    }
                }
            if(cnt >= mm.second) //할인 품목 개수가 원하는 개수랑 같으면
            {
               // cout<<"진입2/"<<mm.second<<"/"<<cnt<<endl;
                check++;
            }
        }
        if(check == m.size())
        {
       //     cout<<"진입3/"<<check<<"/"<<i<<endl;
            answer++;
        }
        
        check = 0;
      

    }
    
    
  /*  for(auto mm : m)
    {
        cout<<mm.first<<"/"<<mm.second<<endl;
    }*/
    
    
    return answer;
}