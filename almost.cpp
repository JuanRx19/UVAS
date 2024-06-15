#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Node{
    int dad;
    int tam;
    int sum;
};

int find(int p, vector<Node>& nodos){
    int ans = 0;
    if(nodos[p].dad == p){
        ans = p;
    }else{
        ans = find(nodos[p].dad, nodos);
    }
    return ans;
}

void Union(int p, int q, vector<Node>& nodos){
    int padre = find(nodos[p].dad, nodos);
    int hijo = find(nodos[q].dad, nodos);
    if(padre != hijo){
        nodos[q].dad = padre;
        nodos[hijo].dad = padre;
        nodos[padre].tam += nodos[hijo].tam;
        nodos[padre].sum += nodos[hijo].sum;
    }
}

void move(int p, int q, vector<Node>& nodos){
    int padre = find(nodos[p].dad, nodos);
    int hijo = find(nodos[q].dad, nodos);
    if(padre != hijo){
        nodos[p].dad = hijo;
        nodos[hijo].tam += 1;
        nodos[padre].tam -= 1;
        nodos[hijo].sum += p+1;
        nodos[padre].sum -= p+1;
    }
}

void solve(int n, int m){
    int opc, v1, v2, ans = 0;
    vector<Node> nodos;
    for (int num = 0; num < n; num++)
    {
        Node nodo;
        nodo.dad = num + n;
        nodo.tam = 0;
        nodo.sum = 0;
        nodos.push_back(nodo);
    }
    
    for (int num = n; num < n*2; num++)
    {
        Node nodo;
        nodo.dad = num;
        nodo.tam = 1;
        nodo.sum = num - n + 1;
        nodos.push_back(nodo);
    }
    
    /*for (const auto& nodo : nodos)
    {
        cout << nodo.dad << endl;
    }*/

    for (int op = 0; op < m; op++)
    {
        cin >> opc;
        if(opc == 1){
            cin >> v1 >> v2;
            Union(v1-1, v2-1, nodos);
        }else if(opc == 2){
            cin >> v1 >> v2;
            move(v1-1, v2-1, nodos);
        }else if(opc == 3){
            cin >> v1;
            ans = find(v1-1, nodos);
            cout << nodos[ans].tam << " " << nodos[ans].sum << endl;
        }
    }
}
int main(){
    //freopen("almostin.txt", "r", stdin);
    //freopen("almostout.txt", "w", stdout);
    int n, m;
    while(cin>>n>>m){
        solve(n, m);
    }
}

//Prueba