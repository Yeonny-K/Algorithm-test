#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    string a = "";
    string b = "";
    string cmp_str = "";
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size()-1; i++)
    {
        if(phone_book[i] < phone_book[i+1])
        {
            a = phone_book[i];
            b = phone_book[i+1];
            cmp_str = string(b.begin(), b.begin()+a.size());
            
        }
        else
        {
            a = phone_book[i+1];
            b = phone_book[i];
            cmp_str = string(a.begin(), a.begin()+b.size());
        }
        
        if(a.compare(cmp_str)==0)
            {
                answer = false;
                break;
            }
    }
    
    
    return answer;
}