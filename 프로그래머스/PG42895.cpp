// 문제가 개편되었습니다. 이로 인해 함수 구성이나 테스트케이스가 변경되어, 과거의 코드는 동작하지 않을 수 있습니다.
// 새로운 함수 구성을 적용하려면 [코드 초기화] 버튼을 누르세요. 단, [코드 초기화] 버튼을 누르면 작성 중인 코드는 사라집니다.
#include <string>
#include <vector>
#include <stack>

using namespace std;

int minValue=9;

void dfs(int length, int n, int number, int sum){
    if(length>8)
        return;
    
    if(sum==number){
        minValue=min(minValue, length);
        return;
    }
    int presentN=n;
    for(int i=0; i<9; i++){
        dfs(length+i+1, n, number, sum+presentN);
        dfs(length+i+1, n, number, sum-presentN);
        if(sum!=0){
            dfs(length+i+1, n, number, sum*presentN);
            dfs(length+i+1, n, number, sum/presentN);
        }
        presentN=10*presentN+n;
    }
}
int solution(int N, int number) {
    int answer = 0;
    
    dfs(0, N, number, 0);
    if(minValue==9)
        minValue=-1;
    answer = minValue;
    return answer;
}