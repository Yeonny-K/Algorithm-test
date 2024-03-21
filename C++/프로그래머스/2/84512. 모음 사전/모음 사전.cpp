#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
char c[] = {'A','E','I','O','U'};
vector<string> dic;

void Recur(const string &word, const string &s)
{
    for(int i=0; i<5; i++)
    {
        string temp = s;
        temp += c[i];
        dic.push_back(temp);
        if(temp.length()==5)
            continue;
        Recur(word, temp);
    }
    return;
    
}

int solution(string word) {
    int answer = 0;
    string s = "";
    Recur(word, s);
    answer = find(dic.begin(), dic.end(), word) - dic.begin() + 1;
    
    return answer;
}