#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define all(v) v.begin(), v.end()

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

int dfs(int node, int parent, vector<vector<int>> &g, vector<bool> &visited, vector<vector<int>> &c_height)
{
    if (visited[node])
    {
        return *max_element(all(c_height[node])) + 1;
    }

    visited[node] = true;

    vector<int> hs;

    for (int child : g[node])
    {
        int h;
        if (child == parent)
            h = -1;
        else
            h = dfs(child, node, g, visited, c_height);
        hs.push_back(h);
    }

    c_height[node] = hs;

    if (hs.size() == 1)
        return 1;

    return *max_element(all(hs)) + 1;
}

void fix(vector<vector<int>> &c_height, vector<vector<int>> &g, int node)
{
    if (c_height[node].size() == 1)
        return;
    for (int j = 0; j < c_height[node].size(); j++)
    {
        if (c_height[node][j] == -1)
        {
            int parent = g[node][j];
            for (int k = 0; k < c_height[parent].size(); k++)
            {
                if (c_height[parent][k] == -1)
                {
                    fix(c_height, g, parent);
                }
            }
            int parent_mx = -1;
            for (int k = 0; k < c_height[parent].size(); k++)
            {
                if (g[parent][k] == node)
                    continue;
                parent_mx = max(c_height[parent][k], parent_mx);
            }
            parent_mx = max(parent_mx, 0);
            c_height[node][j] = parent_mx + 1;
        }
    }
}

void solve(int cc)
{
    int n, k;
    cin >> n >> k;

    if (n == 1)
    {
        if (k > 0)
        {
            cout << 0 << '\n';
            return;
        }
        cout << 1 << '\n';
        return;
    }

    vector<pair<int, int>> e(n - 1);

    for (auto &p : e)
    {
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
    }

    vector<vector<int>> g(n);

    for (auto p : e)
    {
        g[p.first].push_back(p.second);
        g[p.second].push_back(p.first);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> c_height(n);

    dfs(0, -1, g, visited, c_height);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
    {
        fix(c_height, g, i);
    }

    vector<int> cnt(n);

    for (int i = 0; i < n; i++)
    {
        if (c_height[i].size() < 2)
            cnt[i] = 1;
        else
        {
            sort(all(c_height[i]));
            cnt[i] = c_height[i][c_height[i].size() - 2] + 1;
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (cnt[i] > k)
            count++;
    }

    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }

    return 0;
}