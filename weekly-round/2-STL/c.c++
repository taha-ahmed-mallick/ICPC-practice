#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    cin >> num;
    cin.ignore();
    string parenthesis[num];
    for (int i = 0; i < num; i++)
        getline(cin, parenthesis[i]);

    for (int i = 0; i < num; i++)
    {
        vector<char> arr;
        bool auth = true;
        for (int j = 0; j < parenthesis[i].length(); j++)
            if (parenthesis[i][j] == '(' || parenthesis[i][j] == '[')
                arr.push_back(parenthesis[i][j]);
            else if (arr.empty()) {
                auth = false;
                break;
            }
            else if ((parenthesis[i][j] == ')' && arr.back() == '(') || (parenthesis[i][j] == ']' && arr.back() == '['))
                arr.pop_back();
            else
            {
                auth = false;
                break;
            }
        if (!arr.empty()) auth = false;
        cout << (auth ? "Yes" : "No") << endl;
    }
    return 0;
}