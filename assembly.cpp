#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int N, vector<int> val){
    int ans = 0;
    int iterSort = 1;

    for (int i = 0; i < N; i++)
    {
        if (val[i] != iterSort)
        {
            ans+=1;
        }else
        {
            iterSort+=1;
        }
        
    }
    
    return ans;
}

int main(){
    int C,  N, ans;
    cin >> C;
    int i = 0;
    while (C > i)
    {
        cin >> N;
        vector<int> val(N);
        for (int i = 0; i < N; i++) cin >> val[i];
        
        cout << "Case " << i+1 << ": " << solve(N, val) << endl;
        i++;
    }
    
    return 0;
}