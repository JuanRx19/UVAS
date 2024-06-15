#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct Node{
    string dad;
    string animal;
    int tam;
};

string find(string p, unordered_map<string, Node>& nodos){
    string ans;
    if(nodos[p].dad == p){
        ans = p;
    }else{
        ans = find(nodos[p].dad, nodos);
    }
    return ans;
}

int Union(string p, string q, unordered_map<string, Node>& nodos){
    string padre = find(nodos[p].dad, nodos);
    string hijo = find(nodos[q].dad, nodos);
    if(padre != hijo){
        nodos[q].dad = padre;
        nodos[hijo].dad = padre;
        nodos[padre].tam += nodos[hijo].tam;
    }

    return padre != hijo ? nodos[padre].tam : 0;
}

int main(){
  //freopen("testin.txt", "r", stdin);
  //freopen("testout.txt", "w", stdout);
  int C, R, maxTam;
  string animal, cazador;
  while (cin >> C >> R, C != 0 || R != 0)
  {
    unordered_map<string, Node> animals(C);
    maxTam = 1;
    for (int i = 0; i < C; i++)
    {
      
      cin >> animal;
      animals[animal].dad = animal;
      animals[animal].animal = animal;
      animals[animal].tam = 1;
    }
    
    for (int i = 0; i < R; i++)
    {
      cin >> animal >> cazador;
      maxTam = max(Union(animal, cazador, animals), maxTam);
    }
    
    cout << maxTam << endl;
  }
  
  return 0;
}