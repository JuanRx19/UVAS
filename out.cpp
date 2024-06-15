#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool verificar(vector<int>& values){
  return !(values[0] == 0 && values[1] == 0 && values[2] == 0 && values[3] == 0 && values[4] == 0);
}

bool conflict(int count, int value, int x){
  bool ans;
  if(x == 3 && (count % value != 0)){
    ans = false;
  }else{
    ans = true;
  }

  return ans;
}

bool solve(vector<int>& values, int count, int i){
  bool ans;
  if (i == 0)
  {
    ans = count - values[0] == 0;
  }else{
    ans = false;
    int x = 1;
    while(!(ans) && x < 4){
      if (conflict(count, values[i], x))
      {
        if(x == 1){
          ans = solve(values, count - values[i], i - 1);
        }else if(x == 2){
          ans = solve(values, count + values[i], i - 1);
        }else{
          ans = solve(values, count / values[i], i - 1);
        }
      }
      x++;
    }
  }

  return ans;
}

int main(){
  //freopen("outin.txt", "r", stdin);
  //freopen("outout.txt", "w", stdout);
  bool ans;
  vector<int> values(5);
  for (int i = 0; i < 5; i++)
  {
    cin >> values[i];
  }
  while (verificar(values)){
    sort(values.begin(), values.end());
    ans = false;
    do
    {
      ans = solve(values, 23, 4);
    } while (!(ans) && next_permutation(values.begin(), values.end()));

    if(ans){
      cout << "Possible" << endl;
    }else{
      cout << "Impossible" << endl;
    }
    

    for (int i = 0; i < 5; i++)
    {
      cin >> values[i];
    }

  }
  
  return 0;
}