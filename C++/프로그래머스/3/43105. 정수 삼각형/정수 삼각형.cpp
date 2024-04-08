#include <string>
#include <vector>
#include <algorithm> //max 때문에

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> num(triangle.size(), vector<int>(triangle.size(), 0)); // 필요한 사이즈 만큼만 vector 만들기. 총 줄 수 만큼 벡터 만들어주는데, 그 줄들은 triangle 마지막 줄의 원소 수만큼의 칸이 있다.
    num[0][0] = triangle[0][0]; //제일 첫 단계는 무조건 방문하니까
    
    for(int i=1; i < triangle.size(); i++){ //i는 행, 첫단계를 뛰어 넘었으니 1부터
        for(int j=0; j < triangle[i].size(); j++){ //j는 열
            if(j == 0){
                num[i][0] = num[i-1][0] + triangle[i][0]; //1열은 기존 1열 값 + 현재 값 더하기
            } else if(j == triangle[i].size() -1){ //마지막 열은 이전 마지막 값 더하기
                num[i][triangle[i].size() -1] = num[i-1][triangle[i].size() -2] + triangle[i][triangle[i].size()-1];
            } else { //2개 중 더 큰 값
                num[i][j] = max(num[i-1][j-1], num[i-1][j]) + triangle[i][j];
            }
        }
    }
    
    answer = *max_element(num[triangle.size()-1].begin(), num[triangle.size()-1].end());
    return answer;
}