#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

void solution(string str, vector<string> &ans, int index, string output)
{
    if (index >= str.size())
    {
        ans.push_back(output);
        return;
    }
    // Exclude
    solution(str, ans, index + 1, output);
    // Include
    // string temp = str.substr(index, 1);
    // output.append(temp);
    char temp = str[index];
    output.push_back(temp);
    solution(str, ans, index + 1, output);
}

int main()
{
    string str;
    cout << "Enter the String: " << endl;
    getline(cin, str);
    cout << endl
         << endl
         << str;
    vector<string> ans;
    solution(str, ans, 0, "");
    cout << endl
         << endl;
    cout << "{ ";
    for (auto key : ans)
    {
        cout << "( " << key << " ) ";
    }
    cout << " } \n\n\n";
}