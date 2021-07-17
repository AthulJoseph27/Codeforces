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

bool isSafe(vector<vector<int>> &a, int i, int j)
{
    int n = a.size();
    int m = a[0].size();

    if (i != 0)
    {
        if (j != 0)
        {
            if (a[i - 1][j - 1] == 1)
                return false;

            if (a[i][j - 1] == 1)
                return false;
        }

        if (a[i - 1][j] == 1)
            return false;

        if (j != (m - 1))
        {
            if (a[i - 1][j + 1] == 1)
                return false;

            if (a[i][j + 1] == 1)
                return false;
        }
    }

    if (i != (n - 1))
    {
        if (j != 0)
        {
            if (a[i + 1][j - 1] == 1)
                return false;

            if (a[i][j - 1] == 1)
                return false;
        }

        if (a[i + 1][j] == 1)
            return false;

        if (j != (m - 1))
        {
            if (a[i + 1][j + 1] == 1)
                return false;

            if (a[i][j + 1] == 1)
                return false;
        }
    }

    return true;
}

void solve(int cc)
{
    int h, w;
    cin >> h >> w;

    int c1 = 0, c2 = 0;
    vector<vector<int>> a(h, vector<int>(w, 0));
    vector<vector<int>> b(h, vector<int>(w, 0));

    a[0][0] = 1;
    b[0][1] = 1;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if ((i == 0 || j == 0 || i == (h - 1) || j == (w - 1)))
            {
                if (!isSafe(a, i, j))
                    continue;
                a[i][j] = 1;
                c1++;

                if (!isSafe(b, i, j))
                    continue;
                b[i][j] = 1;
                c2++;
            }
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (c1 > c2)
                cout << a[i][j];
            else
                cout << b[i][j];
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