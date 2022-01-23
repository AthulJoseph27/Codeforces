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
#define rall(v) v.rbegin(), v.rend()

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

    string tmp = s;

    sort(all(tmp));

    bool all_same = true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != tmp[i])
        {
            all_same = false;
            break;
        }
    }

    if (all_same)
    {
        cout << 0 << '\n';
        return;
    }

    int o = 0, z = 0;

    for (char c : s)
    {
        if (c == '1')
            o++;
        else
            z++;
    }

    vi a;

    int l = 0, r = n - 1;

    while (l < r)
    {
        if (s[r] == '1')
        {
            r--;
            continue;
        }

        //s[r] == 0

        while ((l < r) && s[l] == '0')
        {
            l++;
        }

        if (l == r)
            break;

        a.push_back(l);
        a.push_back(r);

        l++;
        r--;
    }

    sort(all(a));

    if (a.size() == 0)
    {
        cout << 0 << '\n';
        return;
    }

    cout << 1 << '\n';

    cout << a.size() << ' ';

    for (int i : a)
        cout << (i + 1) << ' ';

    cout << '\n';
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