#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool customSort(const pair<int, int> &a, const pair<int, int> &b) {
    bool ans;
    if (a.first == b.first) {
        ans = a.second > b.second;
    }else{
        ans = a.first < b.first;
    }

    return ans;
}

bool customSort2(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void solve(int P, int N, vector<pair<int, int>> A){
    int cont;
    int tam = N;
    sort(A.begin(), A.end(), customSort);

    for (int i = 0; i < tam; i++)
    {
        cont = P/N;
        if (cont < A[i].first)
        {
            A[i].first = cont;
        }
        P-=A[i].first;
        N-=1;
    }

    sort(A.begin(), A.end(), customSort2);
    
    for (int j = 0; j < tam; j++) 
    {
        if(tam-1 != j){
            cout << A[j].first << " ";
        }else{
            cout << A[j].first << endl;
        }
        
    }
}

int main(){
    //freopen("divisionin.txt", "r", stdin);
    //freopen("divisionout.txt", "w", stdout);
    int C, P, N, val;
    int total;
    cin >> C;
    while(C--){
        total = 0;
        cin >> P >> N;
        vector<pair<int, int>> A(N);
        for (int i = 0; i < N; i++) 
        {
            cin >> val;
            A[i].first = val;
            A[i].second = i;
            total+=A[i].first;
        }
        
        if(total >= P){
            solve(P, N, A);
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}