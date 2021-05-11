/*
You have n barrels lined up in a row, numbered from left to right from one. Initially, the i-th barrel contains ai

liters of water.

You can pour water from one barrel to another. In one act of pouring, you can choose two different barrels x
and y (the x-th barrel shouldn't be empty) and pour any possible amount of water from barrel x to barrel y

(possibly, all water). You may assume that barrels have infinite capacity, so you can pour any amount of water in each of them.

Calculate the maximum possible difference between the maximum and the minimum amount of water in the barrels, if you can pour water at most k

times.

Some examples:

    if you have four barrels, each containing 5

liters of water, and k=1, you may pour 5 liters from the second barrel into the fourth, so the amounts of water in the barrels are [5,0,5,10], and the difference between the maximum and the minimum is 10
;
if all barrels are empty, you can't make any operation, so the difference between the maximum and the minimum amount is still 0
. 
*/
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
    vector<long long> b(n);

    for (int i = 0; i < n; i++)
        cin >> b[i];

    sort(all(b));

    int index = n - 2;

    while (index >= 0 && k > 0)
    {
        if (b[index] == 0)
        {
            break;
        }
        b[n - 1] += b[index];
        b[index] = 0;
        k--;
        index--;
    }

    cout << b[n - 1] << '\n';
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