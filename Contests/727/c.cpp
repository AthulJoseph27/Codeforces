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
    long long n, k, x;

    cin >> n >> k >> x;

    vector<long long> a(n);

    for (long long &i : a)
        cin >> i;

    sort(all(a));

    vector<long long> rq;

    int grps = 1;

    for (int i = 1; i < n; i++)
    {
        if ((a[i] - a[i - 1]) > x)
        {
            long long diff = a[i] - a[i - 1];
            if (diff % x == 0)
            {
                rq.push_back(diff / x - 1);
            }
            else
            {
                rq.push_back(diff / x);
            }
            grps++;
        }
    }

    sort(all(rq));

    // debug(rq, k, grps);

    for (int i = 0; i < rq.size(); i++)
    {
        if (k > 0)
        {
            if (rq[i] <= k)
            {
                k -= rq[i];
                grps--;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    // debug(k);

    cout << grps << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}