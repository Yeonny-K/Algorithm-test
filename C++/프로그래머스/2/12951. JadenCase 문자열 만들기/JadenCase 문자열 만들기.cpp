#include <string>
#include <vector>
#include <cctype> //toupper, tolower

using namespace std;

string solution(string s) {
    s[0] = toupper(s[0]);
    for(int i=1; i<s.size(); i++)
    {
        if(s[i-1] == ' ') // 공백 후 첫글자라면
        {
            s[i] = toupper(s[i]);
        }
        else
        {
            s[i] = tolower(s[i]);
        }
    }
    return s;
}