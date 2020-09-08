#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0; i<timetable.size(); i++){
        string time=timetable[i];
        int hour=stoi(time.substr(0, 2));
        int minute=stoi(time.substr(3,2));
        int minuteOuput=hour*60+minute;
        pq.push(minuteOuput);
    }
    
    int time=9*60;
    
    for(int i=0; i<n-1; i++){
        int startTime=9*60+i*t;
        int cnt=0;
        
        while(pq.size()>0 && cnt<m){
            if(pq.top()<=startTime){
                pq.pop();
                cnt++;
            }else
                break;
        }
    }
    
    int startTime=9*60+(n-1)*t;
    int cnt=0;
    
    while(pq.size()>0 && cnt<m-1){
        if(pq.top()<=startTime){
            pq.pop();
            cnt++;
        }else
            break;
    }
    int result=0;
    if(pq.empty() || pq.top()>startTime)
        result=startTime;
    else
        result=pq.top()-1;
    
    int hour=result/60;
    int minute=result%60;
    cout << hour <<"\t"<<minute <<"\n";
    string hourTemp="";
    string minuteTemp="";
    
    if(hour<10)
        hourTemp="0"+to_string(hour);
    else
        hourTemp=to_string(hour);
    
    if(minute<10)
        minuteTemp="0"+to_string(minute);
    else
        minuteTemp=to_string(minute);
        
    string output=hourTemp+":"+minuteTemp;
    answer=output;
    return answer;
}