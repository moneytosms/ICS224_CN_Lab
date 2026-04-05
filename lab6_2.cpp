#include <bits/stdc++.h>
using namespace std;

string xor_op(string a, string b) {
  string result = "";
  for (int i = 1; i < b.length(); i++) {
    result += (a[i] == b[i]) ? '0' : '1';
  }
  return result;
}

string crc(string data, string gen) {
  int l_gen = gen.length();
  string a_data = data + string(l_gen - 1, '0');

  string temp = a_data.substr(0, l_gen);

  for (int i = l_gen; i < a_data.length(); i++) {
    if (temp[0] == '1') {
      temp = xor_op(temp, gen);
    } else {
      temp = xor_op(temp, string(l_gen, '0'));
    }
    temp = temp.substr(1) + a_data[i];
  }
  return temp.substr(0, l_gen - 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  return 0;
}
