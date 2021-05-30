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
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    m = min(n, m);

    bool can = false;

    for (char c : s)
    {
        if (c == '1')
        {
            can = true;
            break;
        }
    }

    if (!can)
    {
        cout << s << '\n';
        return;
    }

    for (int j = 0; j < m; j++)
    {
        string news = s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
                continue;
            if (s[i] == '0')
            {
                if (i != 0 && i != (n - 1))
                {
                    if (s[i - 1] == s[i + 1])
                        continue;
                    else if (s[i - 1] == '1' || s[i + 1] == '1')
                    {
                        news[i] = '1';
                    }
                }
                else
                {
                    if (i == 0)
                    {
                        if (s[1] == '1')
                        {
                            news[i] = '1';
                        }
                    }
                    else if (i == (n - 1))
                    {
                        if (s[n - 2] == '1')
                        {
                            news[n - 1] = '1';
                        }
                    }
                }
            }
        }
        if (s == news)
        {
            cout << news << '\n';
            return;
        }
        s = news;
    }

    cout << s << '\n';
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