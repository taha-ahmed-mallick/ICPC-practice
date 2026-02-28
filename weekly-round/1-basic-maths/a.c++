#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int N[T], X[T];
    for (int i = 0; i < T; i++)
        cin >> N[i] >> X[i];

    for (int i = 0; i < T; i++) {
        int packets = ceil(float(N[i] - X[i]) / 4);
        packets = packets < 0 ? 0 : packets;
        cout << packets << endl;
    }
    return 0;
}