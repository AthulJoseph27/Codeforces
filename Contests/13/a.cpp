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

void solve(int cc)
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> a(r, vector<char>(c));

    int ii = -1, jj = -1;

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (ii == -1 && a[i][j] != '.')
            {
                ii = i;
                jj = j;
            }
        }

    if (ii == -1)
    {
        a[0][0] = 'R';
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
            {
                if (a[i][j] == '.')
                {
                    if (i != 0)
                    {
                        if (a[i - 1][j] == 'R')
                            a[i][j] = 'W';
                        else
                            a[i][j] = 'R';
                    }
                    else
                    {
                        if (a[i][j - 1] == 'R')
                            a[i][j] = 'W';
                        else
                            a[i][j] = 'R';
                    }
                }
            }

        cout << "YES\n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << a[i][j];
            }
            cout << '\n';
        }

        return;
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (ii % 2 == i % 2)
            {
                if (jj % 2 == j % 2)
                {
                    if (a[i][j] != '.' && a[i][j] != a[ii][jj])
                    {
                        cout << "NO" << '\n';
                        return;
                    }

                    a[i][j] = a[ii][jj];
                }
                else
                {
                    if (a[i][j] != '.' && a[i][j] == a[ii][jj])
                    {
                        cout << "NO" << '\n';
                        return;
                    }

                    if (a[ii][jj] == 'W')
                        a[i][j] = 'R';
                    else
                        a[i][j] = 'W';
                }
            }
            else
            {
                if (jj % 2 != j % 2)
                {
                    if (a[i][j] != '.' && a[i][j] != a[ii][jj])
                    {
                        cout << "NO" << '\n';
                        return;
                    }

                    a[i][j] = a[ii][jj];
                }
                else
                {
                    if (a[i][j] != '.' && a[i][j] == a[ii][jj])
                    {
                        cout << "NO" << '\n';
                        return;
                    }

                    if (a[ii][jj] == 'W')
                        a[i][j] = 'R';
                    else
                        a[i][j] = 'W';
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j];
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