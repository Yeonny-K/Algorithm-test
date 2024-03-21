#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

string digitNum = "";

bool isPrime(long n)
{
    if(n==0 || n==1)
        return false;
    
    for(int i=2; i<=sqrt(n); i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}

void findDigit(int n, int k)
{
    while(1)
    {        
        digitNum += to_string(n%k);
        n = n/k;
        if(n<=k)
        {
            digitNum += to_string(n%k);
            break;
        }
    }
    
    reverse(digitNum.begin(), digitNum.end());
    
    return;
  
    
}

int solution(int n, int k) {
    int answer = 0;
    string temp = "";
    int target = 0;
    bool flag = false;
    
    if(k==10)
    {
        digitNum += to_string(n);
    }
    else
    {
        findDigit(n, k);
    }
    
    for(int i=0; i<digitNum.size(); i++)
    {
        if(digitNum[i]=='0')
        {
            if(!flag)
            {
                target = stol(temp);
           //     cout<<target<<endl;
                temp = "";
                flag = true;
                if(isPrime(target))
                    answer++;
            }
            else
            {
                continue;
            }
        }
        else
        {
            flag = false;
            temp += digitNum[i];
        }
                
    }
    
    if(temp!="")
    {
        int cnt = 0;
        for(int i=0; i<temp.size(); i++)
        {
            if(temp[i]=='0')
                cnt++;
        }
        if(cnt==0)
        {
            if(isPrime(stol(temp)))
                answer++;
        }
    }
    
 
    return answer;
}