#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pi;

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
    int n;
    cin >> n;

    string s;
    cin >> s;

    int q = 0;

    for (char c : s)
    {
        if (c == '?')
            q++;
    }

    if (q == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                s[i] = 'B';
            }
            else
            {
                s[i] = 'R';
            }
        }

        cout << s << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i] != '?')
        {
            if (q == 0)
                continue;

            q = 0;
            bool same = false;

            char sm = s[i];
            char nxt = s[i];

            if (sm == 'R')
                nxt = 'B';
            else
                nxt = 'R';
            for (int j = i - 1; j >= 0; j--)
            {
                if (s[j] != '?')
                    break;
                if (same)
                    s[j] = sm;
                else
                    s[j] = nxt;
                same = !same;
            }
        }
        else
        {
            q++;
        }
    }

    q = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] != '?')
        {
            if (q == 0)
                continue;

            q = 0;
            bool same = false;

            char sm = s[i];
            char nxt = s[i];

            if (sm == 'R')
                nxt = 'B';
            else
                nxt = 'R';
            for (int j = i + 1; j < n; j++)
            {
                if (s[j] != '?')
                    break;
                if (same)
                    s[j] = sm;
                else
                    s[j] = nxt;
                same = !same;
            }
        }
        else
        {
            q++;
        }
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