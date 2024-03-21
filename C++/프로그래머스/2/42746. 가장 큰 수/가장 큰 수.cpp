#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp_str(const string &a, const string &b)
{
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> numtostr;
    string temp = "";
    
    for(int i=0; i<numbers.size(); i++)
    {
        temp = to_string(numbers[i]);
        numtostr.push_back(temp);
    }
    
    sort(numtostr.begin(), numtostr.end(), cmp_str);
    
   /* for(int i=0; i<numtostr.size(); i++)
    {
        cout << numtostr[i] << endl;
    }*/
    
    if(numtostr[0]=="0")
        return "0";
    
    for(int i=0; i<numtostr.size(); i++)
    {
        answer+=numtostr[i];
    }
    
    
    
    return answer;
}