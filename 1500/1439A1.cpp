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

vector<vector<int>> fix(vector<vector<int>> &a, int y, int x)
{
    // cells are (y,x) (y,x+1) (y+1,x) (y+1,x+1)

    int count = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (a[y + i][x + j] == 1)
                count++;
        }
    }

    if (count == 0)
        return {};

    vector<vector<int>> res;

    if (count == 1)
    {
        if (a[y][x] == 1)
        {
            /*
                10 -> 01 -> 10 -> 00
                00    10    11    00
            */
            res = {{y, x, y + 1, x, y, x + 1}, {y, x, y, x + 1, y + 1, x + 1}, {y, x, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y + 1][x] == 1)
        {
            /*
                00 -> 10 -> 01 -> 00
                10    01    11    00
            */

            res = {{y, x, y + 1, x, y + 1, x + 1}, {y, x, y + 1, x, y, x + 1}, {y, x + 1, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y][x + 1] == 1)
        {
            /*
                01 -> 10 -> 01 -> 00
                00    01    11    00
            */
            res = {{y, x, y, x + 1, y + 1, x + 1}, {y, x, y + 1, x, y, x + 1}, {y, x + 1, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y + 1][x + 1] == 1)
        {
            /*
                00 -> 01 -> 10 -> 00
                01    10    11    00
            */
            res = {{y + 1, x + 1, y + 1, x, y, x + 1}, {y, x, y, x + 1, y + 1, x + 1}, {y, x, y + 1, x, y + 1, x + 1}};
        }
        else
        {
            assert(false);
        }
    }
    else if (count == 2)
    {
        if (a[y][x] == 1 && a[y][x + 1] == 1)
        {
            /*
                11 -> 01 -> 00
                00    11    00
            */
            res = {{y, x, y + 1, x, y + 1, x + 1}, {y, x + 1, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y][x] == 1 && a[y + 1][x] == 1)
        {
            /*
                10 -> 01 -> 00
                10    11    00
            */
            res = {{y, x, y, x + 1, y + 1, x + 1}, {y, x + 1, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y][x] == 1 && a[y + 1][x + 1] == 1)
        {
            /*
                10 -> 01 -> 00
                01    11    00
            */
            res = {{y, x, y + 1, x, y, x + 1}, {y, x + 1, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y][x + 1] == 1 && a[y + 1][x + 1] == 1)
        {
            /*
                01 -> 10 -> 00
                01    11    00
            */
            res = {{y, x, y + 1, x, y, x + 1}, {y, x, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y][x + 1] == 1 && a[y + 1][x] == 1)
        {
            /*
                01 -> 10 -> 00
                10    11    00
            */

            res = {{y, x, y, x + 1, y + 1, x + 1}, {y, x, y + 1, x, y + 1, x + 1}};
        }
        else if (a[y + 1][x] == 1 && a[y + 1][x + 1] == 1)
        {
            /*
                00 -> 11 -> 00
                11    10    00
            */
            res = {{y, x, y, x + 1, y + 1, x + 1}, {y, x, y + 1, x, y, x + 1}};
        }
        else
        {
            assert(false);
        }
    }
    else if (count == 3)
    {
        res.push_back({});

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (a[y + i][x + j] == 1)
                {
                    res.back().push_back(y + i);
                    res.back().push_back(x + j);
                }
            }
        }
    }
    else
    {
        /*
        11  ->  00  ->  01 -> 10 -> 00
        11      01      10    11    00

        4 moves per 4 cells -> 1 move per cell

        */

        res = {{y, x, y + 1, x, y, x + 1}, {y + 1, x + 1, y + 1, x, y, x + 1}, {y, x, y, x + 1, y + 1, x + 1}, {y, x, y + 1, x, y + 1, x + 1}};
    }

    a[y][x] = 0;
    a[y][x + 1] = 0;
    a[y + 1][x] = 0;
    a[y + 1][x + 1] = 0;

    return res;
}

void solve(int cc)
{
    int m, n;
    cin >> m >> n;

    vector<vector<int>> a(m, vector<int>(n));

    for (int y = 0; y < m; y++)
    {
        for (int x = 0; x < n; x++)
        {
            char c;
            cin >> c;
            a[y][x] = (c == '1');
        }
    }

    vector<vector<int>> ans;

    for (int y = 0; y <= m - 2; y += 2)
    {
        for (int x = 0; x <= n - 2; x += 2)
        {
            vector<vector<int>> res = fix(a, y, x);
            for (auto i : res)
                ans.push_back(i);
        }

        if (n % 2 != 0)
        {
            vector<vector<int>> res = fix(a, y, n - 2);
            for (auto i : res)
                ans.push_back(i);
        }
    }

    if (m % 2 != 0)
    {
        int y = m - 2;
        for (int x = 0; x <= n - 2; x += 2)
        {
            vector<vector<int>> res = fix(a, y, x);
            for (auto i : res)
                ans.push_back(i);
        }

        if (n % 2 != 0)
        {
            vector<vector<int>> res = fix(a, y, n - 2);
            for (auto i : res)
                ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j : ans[i])
        {
            cout << (j + 1) << ' ';
        }
        cout << '\n';
    }
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