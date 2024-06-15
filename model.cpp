#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 201

vector<int> p(MAX), rango(MAX);

bool dfsAux(int u, vector<vector<int>>& G, vector<int>& vis, vector<int>& color, int colorSelect){
  bool ans = false;
  vis[u] = true;
  color[u] = -colorSelect;
  //cout << "visiting " << u << endl;
  for(auto v : G[u]){
    if(!vis[v]){
      ans = dfsAux(v, G, vis, color, -colorSelect);
    }else if(color[v] == color[u]){
      ans = true;
    }
  }

  return ans;
}

bool dfs(vector<vector<int>>& G){
  bool ans = false;
  vector<int> vis(G.size());
  for (int i = 0; i < G.size(); i++) vis[i] = false;
  vector<int> color(G.size());
  for (int i = 0; i < G.size(); i++) vis[i] = 0;
  int colorSelect = -1;
  for (int i = 1; i < G.size(); i++)
  {
    if(!vis[i]){
      ans = dfsAux(i, G, vis, color, colorSelect);
    }
  }
  
  return ans;
}

struct Arista{
    int origen;
    int destino;
    int peso;
};

bool cmpPeso(const Arista& a, const Arista& b){
    return a.peso < b.peso;
}

void makeSet(int v){
    p[v] = v;
    rango[v] = 0;
}

int findSet(int v){
    int ans = 0;
    if(v == p[v]){
        ans = v;
    }else{
        p[v] = findSet(p[v]);
        ans = p[v];
    }
    return ans;
}

void unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);
    if(u != v){
        if(rango[u] < rango[v]){
            u, v = v, u;
        }
        p[v] = u;
        if(rango[u] == rango[v]){
            rango[u]++;
        }
    }
}

int Kruskal(int n, vector<Arista>& aristas){
    for (int i = 1; i < n + 1; i++) makeSet(i);
    int ans = 0;
    int numAristas = 0;
    sort(aristas.begin(), aristas.end(), cmpPeso);
    vector<Arista> mst(n-1);
    for (int i = 0; i < n-1; i++) mst[i].peso = 0;

    for (int i = 0; i < aristas.size(); i++)
    {
        if(findSet(aristas[i].origen) != findSet(aristas[i].destino)){
            unionSet(aristas[i].origen, aristas[i].destino);
            //cout << aristas[i].origen << " " << aristas[i].destino << endl;
            //cout << findSet(aristas[i].origen) << " " << findSet(aristas[i].destino) << endl;
            mst[numAristas] = aristas[i];
            numAristas++;
            ans+= aristas[i].peso;
        }else if (aristas[i].peso < 0)
        {
          ans+=aristas[i].peso;
        }
        
    }
    
    return ans;
}

int main(){
  //freopen("modelin.txt", "r", stdin);
  //freopen("modelout.txt", "w", stdout);
  int N, M;
  int o, d, p;
  while (cin >> N, N != 0)
  {
    cin >> M;
    vector<vector<int>> grafocheck(N+1);
    vector<Arista> aristas(M);
    for (int i = 0; i < M; i++)
    {
      cin >> o >> d >> p;
      aristas[i].origen = o;
      aristas[i].destino = d;
      aristas[i].peso = p;
      grafocheck[o].push_back(d);
      grafocheck[d].push_back(o);
    }

    if(dfs(grafocheck)){
      cout << "Invalid data, Idiot!" << endl;
    }else{
      cout << Kruskal(N, aristas) << endl;
    }
    
  }
  
  return 0;
}