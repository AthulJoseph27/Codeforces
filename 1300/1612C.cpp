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
    ll k, x;
    cin >> k >> x;

    ll l = 1, r = 2 * k - 1;

    ll ans = r;

    while (l <= r)
    {
        ll mid = (r - l) / 2 + l;
        ll sm = 0;

        /*
            1 1
            2 2
            3 3
            4 4
            5 3
            6 2
            7 1

            mid = 5
            delta = mid - k + 1 = 2

            sm(k) + sm(k-1) - sm(k-delta)
        */

        if (mid <= k)
        {
            sm = (mid * (mid + 1ll)) / 2ll;
        }
        else
        {
            ll sm1 = (k * (k + 1ll)) / 2ll;
            ll sm2 = (k * (k - 1ll)) / 2ll;
            ll delta = mid - k + 1;
            ll tmp = k - delta;
            ll sm3 = (tmp * (tmp + 1ll)) / 2ll;
            sm = sm1 + sm2 - sm3;
        }

        if (sm == x)
        {
            ans = mid;
            break;
        }
        if (sm > x)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    // for (ll mid = max(0ll, l - 100ll); mid <= min(2ll * k - 1, l + 100); mid++)
    // {
    //     ll sm = 0;
    //     if (mid <= k)
    //     {
    //         sm = (mid * (mid + 1ll)) / 2ll;
    //     }
    //     else
    //     {
    //         ll sm1 = (k * (k + 1ll)) / 2ll;
    //         ll sm2 = (k * (k - 1ll)) / 2ll;
    //         ll delta = mid - k + 1;
    //         ll tmp = k - delta;
    //         ll sm3 = (tmp * (tmp + 1ll)) / 2ll;
    //         sm = sm1 + sm2 - sm3;
    //         // debug(mid, sm, x, sm <= x);
    //     }

    //     ans = mid;

    //     if (sm >= x)
    //     {
    //         break;
    //     }
    // }

    // debug(ans, l - 10, l + 10);

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