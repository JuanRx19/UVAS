#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int binarytovalue(int l, int m, int r){
  return (l * (1 << 2)) + (m * (1 << 1)) + (r * (1 << 0));
}

void automata(vector<int>& rules, int value){
  int potencia = 7;
  int op;
  while (potencia != -1)
  {
    op = 1 << potencia;
    if(op <= value){
      value -= op;
      rules[potencia] = 1;
    }else{
      rules[potencia] = 0;
    }
    potencia-=1;
  }
}

void debug(vector<int>& prev){
  for (int i = 0; i < prev.size(); i++)
  {
    cout << prev[i];
  }
  cout << endl;
  
}

bool solve(vector<int>& rules, int tam, vector<int>& cadena, int i, vector<int>& prev){
  bool ans;
  if(i == tam){
    ans = (rules[binarytovalue(prev[i-1], prev[0], prev[1])] == cadena[0]) && (rules[binarytovalue(prev[i-2], prev[i-1], prev[0])] == cadena[i-1]);
  }else{
    int bit = 0;
    ans = false;
    while (!(ans) && bit < 2)
    {
      prev[i] = bit;
      //debug(prev);
      if(i < 2){
        ans = solve(rules, tam, cadena, i + 1, prev);
      }else if(i >= 2 && rules[binarytovalue(prev[i-2], prev[i-1], prev[i])] == cadena[i-1]){
        //cout << binarytovalue(prev[i-2], prev[i-1], prev[i]) << " " << cadena[i-1] << " " << prev[i-2] << " " << prev[i-1] << " " << prev[i] << endl;
        ans = solve(rules, tam, cadena, i + 1, prev);
      }
      bit+=1;
    }
  
  }

  return ans;
}

int main(){
  //freopen("edenin.txt", "r", stdin);
  //freopen("edenout.txt", "w", stdout);
  int value, tam;
  string data;
  while (cin >> value)
  {
    cin >> tam;
    vector<int> cadena(tam);
    cin >> data;
    vector<int> prev(tam);
    for (int i = 0; i < tam; i++)
    {
      if(data[i] == '0'){
        cadena[i] = 0;
      }else{
        cadena[i] = 1;
      }
    }
    vector<int> rules(8);
    automata(rules, value);
    bool ans = solve(rules, tam, cadena, 0, prev);
    if(ans){
      cout << "REACHABLE" << endl;
    }else{
      cout << "GARDEN OF EDEN" << endl;
    }
  }
  
  return 0;
}