#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int deuda;
void dfs(int u, vector<bool>& vis, vector<vector<int>>& friends, vector<int>& deudas){
    //cout << "visiting " << u << " " << endl;
    vis[u] = true;
    deuda += deudas[u];
    for(auto& v : friends[u]){
      if(!vis[v]){
        dfs(v, vis, friends, deudas);
      }
    }
}

int main(){
  //freopen("testin.txt", "r", stdin);
  //freopen("testout.txt", "w", stdout);
  int cases, n, m, origen, destino, padre;
  bool flag;
  cin >> cases;
  while (cases--)
  {
    cin >> n >> m;
    vector<int> deudas;
    vector<vector<int>> friends(n, deudas);
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
      cin >> deuda;
      deudas.push_back(deuda);
    }

    for (int i = 0; i < m; i++)
    {
      cin >> origen >> destino;
      friends[origen].push_back(destino);
      friends[destino].push_back(origen);
    }
    deuda = 0;
    flag = true;
    for (int i = 0; i < n && flag; i++)
    {
      if(!vis[i]){
        dfs(i, vis, friends, deudas);
      }
      if(deuda != 0){
        flag = false;
      }else{
        deuda = 0;
      }
    }
    if(flag){
      cout << "POSSIBLE" << endl;
    }else{
      cout << "IMPOSSIBLE" << endl;
    }
  }
  
  return 0;
}