#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct Node{
    int dad;
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
    }
}

int main(){
  //freopen("testin.txt", "r", stdin);
  //freopen("testout.txt", "w", stdout);
  int cases, cantidad, accert, failed;
  cin >> cases;
  while(cases--){
    accert = 0, failed = 0;
    cin >> cantidad;
    vector<Node> nodos(cantidad + 1);
    for (int i = 1; i < nodos.size(); i++)
    {
      nodos[i].dad = i;
    }

    string data;
    cin.ignore();
    while (getline(cin, data), data != "")
    {
      stringstream k(data);
      char opcion;
      int origen, destino;
      k >> opcion >> origen >> destino;
      if(opcion == 'c'){
        Union(origen, destino, nodos);
      }else{
        if(find(origen, nodos) == find(destino, nodos)){
          accert++;
        }else{
          failed++;
        }
      }
    }

    cout << accert << "," << failed << endl;
    if(cases > 0){
      cout << endl;
    }
  }
  return 0;
}