#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int getX(string& ops){
    stack<int> stack;
    stack.push(0);
    int cantN = 0;
    int signo = 0;
    for(char letra : ops){
        if(letra == 'x' && signo == 1){
            cantN += 1;
        }else if(letra == '-'){
            if(stack.top() == 1){
                signo = 0;
            }else{
                signo = 1;
            }
        }else if(letra == '+'){
            if(stack.top() == 1){
                signo = 1;
            }else{
                signo = 0;
            }
        }else if(letra == '('){
            stack.push(signo);
        }else if(letra == ')'){
            stack.pop();
        }
    }
    
    return cantN;
}

int solve(string& ops, int X, vector<int> val){
    sort(val.begin(), val.end());
    int cant = getX(ops);
    int ans = 0;
    for(int i = 0; i < X; i++){
        if(i <= cant-1){
            ans -= val[i];
        }else{
            ans += val[i];
        }
    }
    
    return ans;
}

int main()
{
    string ops;
    int C;
    int X;
    cin >> C;
    for(int i = 0; i < C; i++){
        cin >> ops;
        cin >> X;
        vector<int> val(X);
        for(int j = 0; j < X; j++){
            cin >> val[j];
        }
        cout << solve(ops, X, val) << endl;
    }
}