#include <iostream>
using namespace std;

int main() {
  int n = 10;
  int total_packets = 0;
  int retransmissions = 0;
  int seq = 0;

  for (int i = 0; i < n; i++) {

    cout << "Sender: Sending Frame " << i << " (sequence number = " << seq
         << ")" << endl;
    total_packets++;

    if ((i + 1) % 4 == 0) { // simulate loss

      cout << "Timeout occurred. Retransmitting Frame " << i
           << " (sequence number = " << seq << ")" << endl
           << endl;

      retransmissions++;
      total_packets++;

      cout << "Receiver: Frame " << i << " received successfully." << endl;
      cout << "Receiver: ACK " << seq << " sent" << endl;
    } else {
      cout << "Receiver: Frame " << i << " received successfully." << endl;
      cout << "Receiver: ACK " << seq << " sent" << endl;
    }

    seq = 1 - seq; // toggle sequence number
  }

  cout << "Total packets transmitted: " << total_packets << endl;
  cout << "Total frames retransmitted: " << retransmissions << endl;

  return 0;
}
