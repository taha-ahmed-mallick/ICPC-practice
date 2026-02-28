#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int logs, max_mem = 0;
    cin >> logs;
    vector<int> mem[logs];
    for (int i = 0; i < logs; i++)
    {
        char move;
        cin >> move;
        int id;
        cin >> id;
        if (move == '+')
            mem[i].push_back(id);
        else if (move == '-')
        {
            bool found = false;
            for (int j = 0; j < i; j++)
                for (int itr : mem[j])
                    if (itr == id)
                    {
                        found = true;
                        break;
                    }

            if (!found)
                if (i == 0)
                    mem[i].push_back(id);
                else
                    for (int j = 0; j < i; j++)
                        mem[j].push_back(id);
        }
    }
    for (int i = 0; i < logs; i++)
    {
        if (mem[i].size() > max_mem)
            max_mem = mem[i].size();
    }
    cout << max_mem;
    return 0;
}