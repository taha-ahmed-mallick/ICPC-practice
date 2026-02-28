#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q_size;
    cin >> n >> q_size;
    vector<int> arr[n];
    int q[q_size][3];
    for (int i = 0; i < q_size; i++)
    {
        int op, t, x;
        cin >> op;
        if (!op)
            cin >> t >> x;
        else
            cin >> t;
        q[i][0] = op;
        q[i][1] = t;
        q[i][2] = x;
    }
    for (int i = 0; i < q_size; i++) {
        if (!q[i][0])
            arr[q[i][1]].push_back(q[i][2]);
        else
            if (q[i][0] == 1){
                for (int j = 0; j < arr[q[i][1]].size(); j++) {
                    cout << arr[q[i][1]][j];
                    if (j != arr[q[i][1]].size() - 1)
                        cout << " ";
                }
                cout << endl;
            } else if (q[i][0] == 2) {
                arr[q[i][1]].clear();
            }
    }
    return 0;
}