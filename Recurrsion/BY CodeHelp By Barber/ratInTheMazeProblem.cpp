#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    bool isSafe(vector<vector<int>> &m, int size, int newx, int newy, vector<vector<int>> &visited)
    {
        if ((newx >= 0 && newx < size) && (newy >= 0 && newy < size) && visited[newx][newy] == 0 && m[newx][newy] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void ratInTheMaze(vector<vector<int>> &m, int size, int x, int y, vector<vector<int>> &visited, vector<string> &ans, string path)
    {
        // base case
        if (x == (size - 1) && y == (size - 1))
        {
            ans.push_back(path);
            return;
        }

        visited[x][y] = 1;
        // 4 choices ==> d,r,u,l
        // For Right
        int newx = x;
        int newy = y + 1;
        if (isSafe(m, size, newx, newy, visited))
        {
            path.push_back('R');
            ratInTheMaze(m, size, newx, newy, visited, ans, path);
            path.pop_back();
        }
        // For Down
        newx = x + 1;
        newy = y;
        if (isSafe(m, size, newx, newy, visited))
        {
            path.push_back('D');
            ratInTheMaze(m, size, newx, newy, visited, ans, path);
            path.pop_back();
        }
        // For Left
        newx = x;
        newy = y - 1;
        if (isSafe(m, size, newx, newy, visited))
        {
            path.push_back('L');
            ratInTheMaze(m, size, newx, newy, visited, ans, path);
            path.pop_back();
        }

        // For UP
        newx = x - 1;
        newy = y;
        if (isSafe(m, size, newx, newy, visited))
        {
            path.push_back('U');
            ratInTheMaze(m, size, newx, newy, visited, ans, path);
            path.pop_back();
        }

        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        string path = "";
        vector<vector<int>> visited = m;
        vector<string> ans;
        if (m[0][0] == 0)
        {
            return ans;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }

        ratInTheMaze(m, n, 0, 0, visited, ans, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    vector<vector<int>> maze = {{1, 1, 1, 1, 0}, {1, 1, 0, 0, 0}, {1, 0, 0, 0, 0}, {1, 1, 1, 1, 0}, {0, 0, 1, 1, 1}};

    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl
         << endl;
    Solution a;
    vector<string> ans = a.findPath(maze, 5);
    cout << ans[0];
}