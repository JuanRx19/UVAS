#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#define inf 0x3f3f3f3f;
using namespace std;
#define MAX 100
vector<int> p(100), rango(100);

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

pair <vector<Arista>, int> Kruskal(int n, vector<Arista>& aristas, int start){
    for (int i = 1; i < n + 1; i++) makeSet(i);
    int INF = inf;
    int numAristas = 0;
    vector<Arista> mst(n-1);
    for (int i = 0; i < n-1; i++) mst[i].peso = 0;
    bool flag = true;

    while(start != aristas.size() && flag){
        if(findSet(aristas[start].origen) != findSet(aristas[start].destino)){
            unionSet(aristas[start].origen, aristas[start].destino);
            //cout << aristas[start].origen << " " << aristas[start].destino << endl;
            //cout << findSet(aristas[start].origen) << " " << findSet(aristas[start].destino) << endl;
            mst[numAristas] = aristas[start];
            numAristas++;
        }

        if(numAristas == n-1){
            flag = false;
        }
        start++;
    }
    
    return make_pair(mst, numAristas);
}

int solve(int n, int k, vector<Arista>& aristas){
    int INF = inf;
    int ans = inf;
    int numAristas;
    pair <vector<Arista>, int> Krus;
    vector<Arista> arbol;
    sort(aristas.begin(), aristas.end(), cmpPeso);
    int start = 0;
    bool flag = true;
    while (flag)
    {
        Krus = Kruskal(n, aristas, start);
        arbol = Krus.first;
        numAristas = Krus.second;
        if(numAristas != n-1){
            flag = false;
        }else{
            ans = min(ans, arbol[arbol.size()-1].peso - arbol[0].peso);
            start++;
        }
    }
    
    if(ans == INF){
        ans = -1;
        
    }
    return ans;
}

int main(){
    //freopen("spanin.txt", "r", stdin);
    //freopen("spanout.txt", "w", stdout);
    int infinito = inf;
    int ans;
    int n, k;
    while (cin >> n >> k, n != 0)
    {
        vector<Arista> aristas(k);
        for( int i = 0; i < k; i++){
            cin >> aristas[i].origen >> aristas[i].destino >> aristas[i].peso;
        }
        if(k == 0){
            cout << -1 << endl;
        }else{
            cout << solve(n, k, aristas) << endl;
        }
        
    }
    return 0;
}