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
    int n, k;
    cin >> n >> k;

    // [1,2,3,2] no of inv = 1
    // p = [1,3,2]
    // b[i] = p[a[i]]
    // b = [1,3,2,3]

    /*
        basically map one number in a to another, such that inversion remains same but lexico max
        no of inversion = k + k+1 + ....+(n-1) = n*(n-1)/2 - k*(k-1)/2

        [1,2,1] => [2,1]
        [2,1,2]

        [1,2,3,2] => [1,3,2]
        [1,3,2,3] k = 3, n = 4 , n-k = 1

        [1,2,3,4,3,2,1] => [4,3,2,1]
        [4,3,2,1,2,3,4]
        
        [1,2,3,...k,k-1,k-2,....,k-(n-k)]
    */

    for (int i = 1; i < (k - (n - k)); i++)
    {
        cout << i << " ";
    }

    for (int i = k; i >= (k - (n - k)); i--)
    {
        cout << i << " ";
    }

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