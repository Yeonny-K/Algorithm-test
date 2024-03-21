#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        stack<char> st;
        for(int j=0; j<s.size(); j++)
        {
            if(s[j]=='}' && st.top()=='{')
            {
                st.pop();
                continue;
            }
            else if(s[j]==']' && st.top()=='[')
            {
                st.pop();
                continue;
            }
            else if(s[j]==')' && st.top()=='(')
            {
                st.pop();
                continue;
            }
            else
            {
                st.push(s[j]);
            }
        }
        if(st.empty())
            answer++;
        
        rotate(s.begin(), s.begin()+1, s.end());
    }
    return answer;
}