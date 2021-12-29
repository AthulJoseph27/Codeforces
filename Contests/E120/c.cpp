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
    int n;

    ll k;

    cin >> n >> k;

    vl a(n);

    for (ll &i : a)
        cin >> i;

    ll sm = 0;

    for (ll i : a)
        sm += i;

    ll temp = sm;

    if (sm <= k)
    {
        cout << 0 << '\n';
        return;
    }

    sort(all(a));

    ll moves = sm - k;

    ll suf_sm = 0;

    for (int i = 1; i < n; i++)
    {
        /*
            let us set x elements to minimum value, i.e a[0]
            such that sm <= k

            decrease a[0] by y

            a[0] + a[1] + ... + a[n-x] + ... + a[n-1] = sm
            a[0] - y + a[1] + ... (a[n-x] + ... + a[n-1]) = sm-y
            a[0] - y + a[1] + .... (a[n-x]+...+a[n-1]) = sm-y
            a[0] - y + a[1] + .... + suffix = sm-y
            a[0] - y + a[1] + .... + suffix = sm-y
            a[0] - y + a[1] + .... + (a[0]-y)*x <= k
            sm-y - suffix + x*(a[0]-y) <= k

            sm - (x+1)y -suffix + xa[0] <= k
            sm - suffix + xa[0]-k <= (x+1)y
            y >= (sm - suffix + xa[0] - k)/(x+1)


        */

        // i represent length of the segment set to a[0]
        suf_sm += (a[n - i] - a[0]);

        ll num = max(sm - suf_sm - k, 0LL);
        ll den = i + 1;
        ll y;

        if (num % den != 0)
            y = num / den + 1LL;
        else
            y = num / den;

        // debug(a);
        // debug(y, i, suf_sm, num, den, num / den);
        moves = min(moves, y + i);
    }

    cout << max(moves, 0LL) << '\n';
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