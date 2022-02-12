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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    bool positive = ((a + b) % 2 == 0);
    bool less_than_1 = (b > 0) || (c > 0);
    bool greater_than_1 = (a > 0) || (d > 0);

    if (greater_than_1 && !positive)
    {
        cout << "Ya ";
    }
    else
    {
        cout << "Tidak ";
    }

    if (less_than_1 && !positive)
    {
        cout << "Ya ";
    }
    else
    {
        cout << "Tidak ";
    }

    if (less_than_1 && positive)
    {
        cout << "Ya ";
    }
    else
    {
        cout << "Tidak ";
    }

    if (greater_than_1 && positive)
    {
        cout << "Ya";
    }
    else
    {
        cout << "Tidak";
    }

    cout << '\n';

    /*
        B1 B2 B3 B4

        B1*B2 -> B3,B4
        B1*B3 -> B1,B2
        B1*B4 -> B1

        B2*B3 -> B2
        B2*B4 -> B1,B2
        B3*B4 -> B3,B4

        B1 -> {B1>0 -> B2==0, B1==0 -> B2>0}
        B2 -> {B2==0, }
        B3 -> {B1+B2 % 2 == 0}
        B4 -> {B1+B2 % 2 == 0}
    */
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