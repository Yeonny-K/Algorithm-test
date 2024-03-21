#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 1;
    int cnt_1 = 1;
    int tmp = n;
    int num = n;
    
    while((tmp/2)!=0)
    {
        if((tmp%2)!=0)
            cnt++;
        tmp = tmp/2;
    }
    
   // cout<<cnt_0<<" "<<cnt_1<<endl;
    while(1)
    {
        num++;
        tmp = num;
         while((tmp/2)!=0)
         {
             if((tmp%2)!=0)
                 cnt_1++;
             tmp = tmp/2;
         }
        
         if((cnt==cnt_1))
             break;
        
        cnt_1 = 1;
        
    }
    
   
    
    answer = num;
    return answer;
}