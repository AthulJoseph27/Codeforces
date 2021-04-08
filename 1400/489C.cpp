#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define push push_back
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
    int m, s, temp;

    cin >> m >> s;

    if (s == 0)
    {
        if (m == 1)
        {
            cout << "0 0" << '\n';
            return;
        }
        cout << "-1 -1" << '\n';
        return;
    }

    if (m * 9 < s)
    {
        cout << "-1 -1" << '\n';
        return;
    }

    string n = "1", mn, mx;

    for (int i = 1; i < m; i++)
        n += '0';

    temp = s;

    // min

    s--;

    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (s > 9)
        {
            n[i] = '9';
            s -= 9;
        }
        else
        {
            n[i] = (char)('0' + s);
            s = 0;
            if (i == 0)
                n[0] = (char)(n[0] + 1);
            break;
        }
    }

    if (s != 0)
    {
        cout << -1 << " " << -1 << '\n';
        return;
    }

    cout << n << " ";
    // max

    n = "1";
    s = temp;

    for (int i = 1; i < m; i++)
        n += '0';

    for (int i = 0; i < n.size(); i++)
    {
        if (s > 9)
        {
            n[i] = '9';
            s -= 9;
        }
        else
        {
            n[i] = (char)('0' + s);
            s = 0;
            break;
        }
    }

    cout << n << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}