#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct GENRE{
    string name; //장르명
    int total_plays; //장르 재생횟수
    vector<pair<int,int>> music; //노래 재생횟수, 고유번호 
};

GENRE Arr[110];

bool compare_genre(GENRE A, GENRE B)
{
    if(A.total_plays > B.total_plays)
        return true;
    return false;
}

bool compare_music(pair<int,int> A, pair<int,int> B)
{
    if(A.first > B.first)
        return true;
    
    if(A.first == B.first)
    {
        if(A.second < B.second)
            return true;
        return false;
    }
    
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int Idx = 0;
    
    for(int i=0; i<genres.size(); i++)
    {
        string name = genres[i];
        bool Flag = false; 
        
        for(int j=0; j<Idx; j++)
        {
            if(Arr[j].name==name)
            {
                Flag = true;
                Arr[j].total_plays = Arr[j].total_plays + plays[i];
                Arr[j].music.push_back(make_pair(plays[i],i));
                break;
            }
        }
        
        if(Flag == false)
        {
            Arr[Idx].name = name;
            Arr[Idx].total_plays = plays[i];
            Arr[Idx].music.push_back(make_pair(plays[i],i));
            Idx++;
        }
    }
    
    sort(Arr, Arr+Idx, compare_genre);
    
    for(int i=0; i<Idx; i++)
    {
        sort(Arr[i].music.begin(), Arr[i].music.end(), compare_music);
        if(Arr[i].music.size() == 1)
            answer.push_back(Arr[i].music[0].second);
        else
        {
            for(int j=0; j<2; j++)
            {
                answer.push_back(Arr[i].music[j].second);
            }
        }
    }
    
    
    return answer;
}