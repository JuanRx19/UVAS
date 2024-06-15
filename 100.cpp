#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main(){
  //freopen("testin.txt", "r", stdin);
  //freopen("testout.txt", "w", stdout);
  int li, ls, cont, res = 0;
  while (cin >> li >> ls)
  {
    res = 0;
    for (int i = min(li, ls); i < max(li, ls) + 1; i++)
    {
      long n = i;
      cont = 0;
      while (n != 1)
      {
        if(n % 2 != 0){
          n = 3*n + 1;
        }else{  
          n /=2;
        }
        cont++;
      }
      res = max(res, cont+1);
    }

    cout << li << " " << ls << " " << res << endl;
    
  }
  
  return 0;
}