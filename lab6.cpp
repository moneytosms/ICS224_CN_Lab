#include <bits/stdc++.h>
using namespace std;

int genCheckSum(vector<int> blocks){

  int sum = accumulate(blocks.begin(),blocks.end(),0);

  while(sum >> 8){
    sum = (sum & 0xFF) +(sum >> 8);
  }
  return ~sum & 0xFF;  
}


int main(){

  // Test Case 1: No error 
  cout << "=== Test Case 1: No Error ===" << endl;

  vector<int> test1 = {160, 12, 171, 20};

  cout << "Original Data: ";
  for (int x : test1) cout << x << " ";
  cout << endl;

  int checksum1 = genCheckSum(test1);
  cout << "Generated Checksum: " << checksum1 << endl;

  test1.push_back(checksum1);

  cout << "Checksum at Receiver: " << genCheckSum(test1) << endl;

  if (genCheckSum(test1) == 0){
    cout << "Result: No error detected." << endl;
  }
  else{
    cout << "Result: Data has been corrupted." << endl;
  }

  cout << endl;

  // Test Case 2: Corrupted bits
  cout << "=== Test Case 2: Corrupted Bits ===" << endl;

  vector<int> test2 = {160, 12, 171, 20};

  cout << "Original Data: ";
  for (int x : test2) cout << x << " ";
  cout << endl;

  int checksum2 = genCheckSum(test2);
  cout << "Generated Checksum: " << checksum2 << endl;

  // Flip bits using XOR to simulate corruption
  test2[0] ^= (1 << 7); // leftmost bit of 1st byte
  test2[1] ^= (1 << 6); // 2nd bit from leftmost of 2nd byte
  test2[2] ^= (1 << 7); // leftmost bit of 3rd byte
  test2[3] ^= (1 << 5); // 3rd bit from leftmost of 4th byte

  cout << "Corrupted Data: ";
  for (int x : test2) cout << x << " ";
  cout << endl;

  test2.push_back(checksum2);

  cout << "Checksum at Receiver: " << genCheckSum(test2) << endl;

  if (genCheckSum(test2) == 0){
    cout << "Result: No error detected." << endl;
  }
  else{
    cout << "Result: Data has been corrupted." << endl;
  }

  return 0;

}

