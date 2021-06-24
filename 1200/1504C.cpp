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

string inverse(string s)
{
    string inv = "";

    for (char c : s)
        if (c == '1')
            inv += '0';
        else
            inv += '1';

    return inv;
}
void solve(int cc)
{
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;

    if (s == f)
    {
        cout << "YES" << '\n';
        return;
    }

    vector<int> b;

    for (char c : s)
    {
        if (c == '1')
            b.push_back(1);
        else
            b.push_back(-1);
    }

    for (int i = 1; i < n; i++)
    {
        b[i] += b[i - 1];
    }

    // the indices where b[i] = 0, 0......i is flippable
    // so even sub range should be equal or inverse of b
    vector<int> indicies;

    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
            indicies.push_back(i);
    }

    if (indicies.size() == 0)
    {
        cout << "NO" << '\n';
        return;
    }

    string tmp = s.substr(0, indicies[0] + 1);
    string ftmp = f.substr(0, indicies[0] + 1);

    if (!(tmp == ftmp || tmp == inverse(ftmp)))
    {
        cout << "NO" << '\n';
        return;
    }

    for (int i = 1; i < indicies.size(); i++)
    {
        tmp = s.substr(indicies[i - 1] + 1, indicies[i] - indicies[i - 1]);
        ftmp = f.substr(indicies[i - 1] + 1, indicies[i] - indicies[i - 1]);

        // debug(tmp, ftmp);

        if (tmp == ftmp || tmp == inverse(ftmp))
        {
            continue;
        }
        cout << "NO" << '\n';
        return;
    }

    if (indicies.back() + 1 >= s.size() || s.substr(indicies.back() + 1, s.size() - indicies.back()) == f.substr(indicies.back() + 1, f.size() - indicies.back()))
    {
        cout << "YES" << '\n';
        return;
    }

    cout << "NO" << '\n';
    return;
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