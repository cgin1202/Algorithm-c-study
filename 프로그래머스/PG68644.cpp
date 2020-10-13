#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    sort(numbers.begin(), numbers.end());
    map<int, int> m;
    
    int size=numbers.size();
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            int sum=numbers[i]+numbers[j];
            m[sum]++;        
        }
    }
    
    map<int, int>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
        answer.push_back(it->first);
    
    
    return answer;
}