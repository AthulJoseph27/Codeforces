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

bool can(vector<vector<char>> &a)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            bool yes = true;

            for (int k = 0; k < 5; k++)
            {
                if (a[i][j + k] != 'X')
                {
                    yes = false;
                    break;
                }
            }

            if (yes)
                return true;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            bool yes = true;

            for (int k = 0; k < 5; k++)
            {
                if (a[j + k][i] != 'X')
                {
                    yes = false;
                    break;
                }
            }

            if (yes)
                return true;
        }
    }

    for (int i = 0; i <= 5; i++)
    {
        for (int j = 0; j <= 5; j++)
        {
            bool yes = true;

            for (int k = 0; k < 5; k++)
            {
                if (a[i + k][j + k] != 'X')
                {
                    yes = false;
                    break;
                }
            }

            if (yes)
            {
                return true;
            }
        }
    }

    for (int i = 0; i <= 5; i++)
    {
        for (int j = 4; j < 10; j++)
        {
            bool yes = true;

            for (int k = 0; k < 5; k++)
            {
                if (a[i + k][j - k] != 'X')
                {
                    yes = false;
                    break;
                }
            }

            if (yes)
            {
                return true;
            }
        }
    }

    return false;
}

void solve(int cc)
{
    vector<vector<char>> a(10, vector<char>(10, '.'));

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> a[i][j];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (a[i][j] == '.')
            {
                a[i][j] = 'X';
                bool b = can(a);
                if (b)
                {
                    cout << "YES" << '\n';
                    return;
                }
                a[i][j] = '.';
            }
        }
    }
    cout << "NO" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}