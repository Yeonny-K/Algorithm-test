#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> AQ; //A는 오름차순으로
    priority_queue<int, vector<int>> BQ; //B는 내림차순으로
    int tmpA = 0; //A에서 뽑을 수
    int tmpB = 0; //B에서 뽑을 수
    
    for(int i=0; i<A.size(); i++) // 길이가 같다고 했으니까
    {
        AQ.push(A[i]);
        BQ.push(B[i]);
    }
    
    while(!AQ.empty()) // 길이가 같으니까
    {
        tmpA = AQ.top();
        AQ.pop();
        tmpB = BQ.top();
        BQ.pop();
        answer += tmpA*tmpB;       
    }



    return answer;
}