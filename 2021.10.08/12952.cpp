#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> board(15, 0);

int N;
int output=0;

bool isAvailable(int idx){
    for(int i=0; i<idx; i++){
        if(board[i]==board[idx])
            return false;
        if(abs(board[i]-board[idx])==abs(i-idx))
            return false;
    }
    return true;
}
void backtracking(int k){
    if(k==N){
        output++;
        return;
    }
        
    for(int i=0; i<N; i++){
        board[k]=i;
        if(isAvailable(k)==true)
            backtracking(k+1);
        board[k]=0;
    }
}
int solution(int n) {
    int answer = 0;
    N=n;
    backtracking(0);
    answer =output;
    return answer;
}