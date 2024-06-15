#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int main(){
  priority_queue<int> pq;
  pq.push(10);
  pq.push(9);
  pq.push(11);
  while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
  
  vector<int> mst;
  mst.push_back(2);
  cout << mst[0] << endl;
  return 0;
}