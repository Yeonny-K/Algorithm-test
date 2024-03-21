#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    if(cacheSize == 0)
        return 5*cities.size();
    
    vector<string> cache;
    
    for(int i=0; i<cities.size(); i++)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        auto iter = find(cache.begin(), cache.end(), cities[i]);
        
        if(iter == cache.end())
        {
            if(cache.size()==cacheSize)
                cache.erase(cache.begin());
            answer+=5;
        }
        else
        {
            answer++;
            cache.erase(iter);
        }
        cache.push_back(cities[i]);
    }
    
    return answer;
}