#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool songSort(pair<int, float> S1, pair<int, float> S2){
    return S1.second < S2.second;
}

int solve(int N){
    vector<pair<int, float>> A(N);
    int Song, Time, C;
    float Frecuency;
    for(int i = 0; i < N; i++){
        cin >> Song >> Time >> Frecuency;
        A[i].first = Song;
        A[i].second = Time/Frecuency;
    }
    cin >> C;
    sort(A.begin(), A.end(), songSort);
    return A[C-1].first;
}
int main(){
    //freopen("songsin.txt", "r", stdin);
    //freopen("songsout.txt", "w", stdout);
    int N;
    while(cin >> N){
        cout << solve(N) << endl;
    }
}