#include <bits/stdc++.h>

#define endl "\n"


int main(int argc, char const *argv[]) {
  std::vector<int> v;



  int n, var, sum ;
  sum = 0;
  std::cin >> n;
  for(int i = 0; i < n; i++ ){
    std::cin >> var;
    v.push_back(var);
  }


  sort(v.begin(), v.end());

  std::vector<int, v[v.size()- 1]> aux;


  memset(aux, 0)



  for(int i = 0 ; i < v.size(); i++){
    if(v[i] == i)
      aux[i] += 1;
  }

  for(int i = 0; i < aux.size(); i++){
    if(aux[i] != 0)
      std::cout << i << "== " << aux[i] << endl;
  }




  // for(auto i: v)
  //   // sum += i;
  //   std::cout << i << " ";
  //
  // std::cout << '\n';
  // std::cout << sum << endl;

  return 0;
}
