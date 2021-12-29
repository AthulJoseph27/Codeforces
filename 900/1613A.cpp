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
    ll x1, p1;
    ll x2, p2;

    cin >> x1 >> p1 >> x2 >> p2;

    while (x1 % 10 == 0)
    {
        x1 /= 10;
        p1++;
    }

    while (x2 % 10 == 0)
    {
        x2 /= 10;
        p2++;
    }

    string s1 = std::to_string(x1);
    string s2 = std::to_string(x2);

    while (s1.size() < s2.size() && p1 > 0)
    {
        s1 += '0';
        p1--;
    }

    while (s2.size() < s1.size() && p2 > 0)
    {
        s2 += '0';
        p2--;
    }

    x1 = stoll(s1);
    x2 = stoll(s2);

    if (x1 == x2)
    {
        if (p1 == p2)
        {
            cout << "=\n";
            return;
        }
        if (p1 > p2)
        {
            cout << ">\n";
            return;
        }

        cout << "<\n";
        return;
    }

    if (x1 > x2)
    {
        if (p1 >= p2)
        {
            cout << ">\n";
            return;
        }

        cout << "<\n";
    }
    else
    {
        if (p1 <= p2)
        {
            cout << "<\n";
            return;
        }

        cout << ">\n";
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