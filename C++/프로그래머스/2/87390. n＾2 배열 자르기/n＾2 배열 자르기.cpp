#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for(long long i=left+1; i<=right+1; i++)
    {
        if(i%n == 0)
        {
            answer.push_back(n);
        }
        else if(i%n <= (i/n)+1)
        {
            answer.push_back((i/n)+1);
        }
        else
        {
            answer.push_back(i%n);
        }
    }
    return answer;
}