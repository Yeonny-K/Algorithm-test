#include <iostream>

using namespace std;

int GetRoundNum(int n)
{
    if(n % 2 ==0) // 짝수라면
        return n/2; // 몫이 그 다음 노드 수가 된다 (참가자 순서)
    else // 홀수라면
        return (n/2)+1; // 몫+1이 그 다음 노드 수가 된다 (참가자 순서)
}

int solution(int n, int a, int b)
{
    int answer = 1; // 1라운드부터 시작
    
    while(n > 1) // 둘이 붙을 때까지
    {
        if(abs(a-b)==1) // 서로 바로 붙어있다면
        {
            if( (b>a) && (b%2==0) ) // b가 더 크고 b가 2로 나눠떨어진다면
            {
                return answer; // 1,2 끼리 붙은 경우 
            }
            else if( (b<a) && (a%2==0)) // a가 더 크고 a가 2로 나눠떨어진다면
            {
                return answer; // 2,1 끼리 붙은 경우
            }
        }
        
        a = GetRoundNum(a); // a의 다음 라운드에서의 순서 찾기
        b = GetRoundNum(b); // b의 다음 라운드에서의 순서 찾기
        n = n/2; // 라운드 지나면 n은 반으로 줄어든다
        answer++; //라운드 지났으니까 라운드 추가
    }
    return answer;
}