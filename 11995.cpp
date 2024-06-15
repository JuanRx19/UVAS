#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <queue>
using namespace std;

int main(){
  //freopen("testin.txt", "r", stdin);
  //freopen("testout.txt", "w", stdout);
  priority_queue<int> pq;
  stack<int> pila;
  queue<int> cola;
  int data, accert = 0, contpq = 0, contp = 0, contq = 0;
  int op, x;
  bool flag;
  while (cin >> data)
  {
    flag = false;
    pq = priority_queue<int>();
    pila = stack<int>();
    cola = queue<int>();
    accert = 0, contpq = 0, contp = 0, contq = 0;
    for (int i = 0; i < data; i++)
    {
      cin >> op >> x;
      if(op == 1){
        pq.push(x);
        pila.push(x);
        cola.push(x);
      }else{
        if(pq.empty()){
          flag = true;
        }else{
          pq.top() == x ? contpq++: contpq+=0;
          pq.pop();
          pila.top() == x ? contp++: contp+=0;
          pila.pop();
          cola.front() == x ? contq++: contq+=0;
          cola.pop();
          accert++;
        }
        
      }
    }
    if(max(contpq, max(contp, contq)) != accert || flag){
      cout << "impossible" << endl;
    }else if (contpq != accert && contp != accert && accert == contq)
    {
      cout << "queue" << endl;
    }else if(contpq == accert && contp != accert && accert != contq){
      cout << "priority queue" << endl;
    }else if(contpq != accert && contp == accert && accert != contq){
      cout << "stack" << endl;
    }else{
      cout << "not sure" << endl;
    }
    
  }
  
  return 0;
}