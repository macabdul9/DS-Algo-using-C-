#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> v;
  // push_back()- to push elements at the end of the list
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  for(auto& e : v)
    cout << e << " ";
  cout << endl;

  // being return and iterator of starting element and end returns ending element of the list
  cout << "being = "<< *v.begin() << " end = "<< *(v.end() - 1) << endl;
  return 0;
}
