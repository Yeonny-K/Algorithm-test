#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    char temp;
    int cnt = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        temp = s[i];
        if(temp == '(')
            cnt++;
        else
            cnt--;
        if(cnt == -1)
        {
            answer = false;
            break;
        }
    }
    
    if(cnt == 0)
        answer = true;
    else
        answer = false;

    return answer;
}