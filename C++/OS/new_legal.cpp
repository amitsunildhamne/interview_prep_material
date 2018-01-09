#include <iostream>
#include <vector>
class Fred {
public:
  Fred(int n): v(n) {}
  std::vector<int> v;
};

int main() {
  using namespace std;
  Fred f(1);
  f.v[0] = 5;
  cout << f.v[0] << endl;
  f = 7;          // is this legal?
  cout << f.v.size(); // what is output here?
return 0;
}
