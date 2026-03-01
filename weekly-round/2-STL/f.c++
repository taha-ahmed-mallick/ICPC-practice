#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
    int id, enter, exit;
} member;

int main()
{
    int logs, max = 0;
    cin >> logs;
    vector<member> mem;

    for (int i = 0; i < logs; i++)
    {
        char move;
        cin >> move;
        int id;
        cin >> id;

        if (move == '+')
            // member temp;
            // temp.id = id;
            // temp.enter = i;
            // temp.exit = 100;
            // mem.push_back(temp); //its equivalent ⬇
            mem.push_back({id, i, -1});
        else if (move == '-')
        {
            int j;
            bool found = false;
            for (j = mem.size() - 1; j >= 0; j--)
                if (mem[j].id == id)
                {
                    found = true;
                    break;
                }
            if (found)
                if (mem[j].exit == -1)
                    mem[j].exit = i;
                else
                    cerr << "This shouldn't occur AT ALL!" << endl;
            else
                mem.push_back({id, -1, i});
        }
    }

    for (int i = -1; i < logs; i++) {
        int count = 0;
        for (auto &curr: mem)
            if (curr.enter <= i && (curr.exit > i || curr.exit == -1))
                count++;
        if (count > max) max = count;
    }
    cout << max << endl;
    return 0;
}