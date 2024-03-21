#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    vector<int> divs;
    int realNum = yellow + brown;
    int w = 0;
    int h = 0;
    
    for(int i=1; i<=realNum; i++)
    {
        if(realNum%i == 0)
            divs.push_back(i);
    }
    
    for(int i=0; i<divs.size(); i++)
    {
        h = divs[i];
        w = realNum / divs[i];
        if((h-2)*(w-2) == yellow)
        {
            answer.push_back(w);
            answer.push_back(h);
            break;
        }
    }
    
    return answer;
}