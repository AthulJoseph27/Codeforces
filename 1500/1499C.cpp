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
    long long n;
    cin >> n;

    vector<long long> c(n);
    for (long long &i : c)
        cin >> i;

    /*
        we make k turns
        l1+l3+....+lk = n
        l2+l4+....+lk-1 = n
        l1*c1 + l3*c3 + l5*c5 + .... + lk*ck = cost1
        l2*c2 + l4*c4 + ..... + lk-1*ck-1 = cost2

    */

    long long ans = c[0] * n + c[1] * n;
    long long mei = 0, moi = 1;

    vector<long long> prefs = {0};

    for (int i = 0; i < n; i++)
    {
        prefs.push_back(prefs.back() + c[i]);
    }

    for (int i = 3; i <= n; i++)
    {
        // spend as much as possible at min
        if (i % 2 == 0)
        {
            // at odd position, max out at odd and even min

            if (c[moi] > c[i - 1])
            {
                moi = i - 1;
            }

            long long buffer_even = mei / 2 + ((i - 2) / 2 - mei / 2);
            long long left_even = n - buffer_even;
            long long buffer_odd = i / 2 - 1;
            long long left_odd = n - buffer_odd;
            long long cost = left_even * c[mei] + prefs[i] - c[mei] - c[moi] + c[moi] * left_odd;
            ans = min(cost, ans);
        }
        else
        {
            if (c[mei] > c[i - 1])
            {
                mei = i - 1;
            }

            long long buffer_odd = (moi - 1) / 2 + ((i - moi) / 2 - 1);
            long long left_odd = n - buffer_odd;
            long long buffer_even = (i - 1) / 2;
            long long left_even = n - buffer_even;
            long long cost = left_odd * c[moi] + prefs[i] - c[moi] - c[mei] + c[mei] * left_even;
            ans = min(cost, ans);
        }
    }

    cout << ans << '\n';
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