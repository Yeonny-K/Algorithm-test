#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int tick;
    int Idx = 0;
    int size = prices.size();
    
    while(Idx<size)
    {
        tryAgain :
        tick = 0;

        for(int i=1; (Idx+i)<size; i++)
        {
            
            if(prices[Idx] <= prices[Idx+i])
            {
                tick++;
        
            }
            else
            {
                tick++;
                Idx++;
                answer.push_back(tick);
                goto tryAgain;
            }
        }
        answer.push_back(tick);
        Idx++;
    }
    return answer;
}