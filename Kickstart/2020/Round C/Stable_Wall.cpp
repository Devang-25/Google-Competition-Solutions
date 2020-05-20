// Never Give UP- Devang Sharma, MAIT DELHI

#include <bits/stdc++.h>
using namespace std;
#define ll long long

typedef vector<vector<int>> graph;

graph buildGraph(int numCourses, vector<pair<int, int>> &prerequisites)
{
    graph g(numCourses);
    for (auto p : prerequisites)
    {
        g[p.second].push_back(p.first);
    }
    return g;
}

vector<int> computeIndegrees(graph &g)
{
    vector<int> degrees(g.size(), 0);
    for (auto adj : g)
    {
        for (int v : adj)
        {
            degrees[v]++;
        }
    }
    return degrees;
}

vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites)
{
    graph g = buildGraph(numCourses, prerequisites);
    vector<int> degrees = computeIndegrees(g);
    vector<int> order;
    for (int i = 0; i < numCourses; i++)
    {
        int j = 0;
        for (; j < numCourses; j++)
        {
            if (!degrees[j])
            {
                order.push_back(j);
                break;
            }
        }
        if (j == numCourses)
        {
            return {};
        }
        degrees[j]--;
        for (int v : g[j])
        {
            degrees[v]--;
        }
    }
    return order;
}

string solve()
{
    int r, c, uniq = 0;
    cin >> r >> c;
    vector<vector<char>> A(r, vector<char>(c, 0));
    unordered_set<char> present;
    unordered_map<int, char> mp, pm;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> A[i][j];
            if (present.find(A[i][j]) == present.end())
            {
                present.insert(A[i][j]);
                mp[uniq] = A[i][j];
                pm[A[i][j]] = uniq;
                uniq++;
            }
        }
    }
    vector<pair<int, int>> pre;
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i + 1][j] == A[i][j])
                continue;
            else
                pre.push_back({pm[A[i][j]], pm[A[i + 1][j]]});
        }
    }

    vector<int> ans = findOrder(uniq, pre);
    string ret;
    if (ans.size() == 0)
        return "-1";
    for (int i = 0; i < ans.size(); i++)
    {
        ret += mp[ans[i]];
    }
    return ret;
}

int main()
{
    ll t;
    cin >> t;
    for (ll x = 1; x <= t; x++)
    {
        cout << "case #" << x << ": " << solve() << endl;
    }
    return 0;
}