#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
char digit[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

string getDigitNum(int num, int n) // num의 n진수 구하기
{
    string result = "";
    while(1)
    {
        result += digit[num%n];
        num = num/n;
        if(num==0)
        {
            break;
        }
    }
    
    reverse(result.begin(), result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string numbers = "";
    int turn = 0;
    int turnIdx = p-1;
    int num = 0;
    
    while(turn < t)
    {
        numbers += getDigitNum(num, n);
        if(turnIdx < numbers.length())
        {
            answer+=numbers[turnIdx];
            turnIdx += m;
            turn++;
        }
        num++;
    }
    
    return answer;
}