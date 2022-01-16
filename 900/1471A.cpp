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
    ll n, x;

    cin >> n >> x;

    vl a(n);

    for (ll &i : a)
        cin >> i;

    /*
        more divisors -> beauty decreases
    */

    deque<ll> b;

    for (ll i : a)
        b.push_back(i);

    while (b.size() > 1)
    {
        ll f1, f2;

        f1 = b.front();
        b.pop_front();
        f2 = b.front();
        b.pop_front();

        if (ceil((double)(f1 + f2) / (double)x) <= (ceil((double)f1 / (double)x) + (ceil((double)f2 / (double)x))))
        {
            b.push_front(f1 + f2);
            continue;
        }
        else
        {
            b.push_front(f2);
            b.push_front(f1);
        }

        ll b1, b2;

        b1 = b.back();
        b.pop_back();
        b2 = b.back();
        b.pop_back();

        if (ceil((double)(b1 + b2) / (double)x) <= (ceil((double)b1 / (double)x) + (ceil((double)b2 / (double)x))))
        {
            b.push_back(b1 + b2);
        }
        else
        {
            b.push_back(b2);
            b.push_back(b1);
            break;
        }
    }

    ll mn = 0;

    for (ll i : b)
    {
        mn += ceil((double)i / (double)x);
    }

    b.clear();

    for (ll i : a)
        b.push_back(i);

    while (b.size() > 1)
    {
        ll f1, f2;

        f1 = b.front();
        b.pop_front();
        f2 = b.front();
        b.pop_front();

        if (ceil((double)(f1 + f2) / (double)x) >= (ceil((double)f1 / (double)x) + (ceil((double)f2 / (double)x))))
        {
            b.push_front(f1 + f2);
            continue;
        }
        else
        {
            b.push_front(f2);
            b.push_front(f1);
        }

        ll b1, b2;

        b1 = b.back();
        b.pop_back();
        b2 = b.back();
        b.pop_back();

        if (ceil((double)(b1 + b2) / (double)x) >= (ceil((double)b1 / (double)x) + (ceil((double)b2 / (double)x))))
        {
            b.push_back(b1 + b2);
        }
        else
        {
            b.push_back(b2);
            b.push_back(b1);
            break;
        }
    }

    ll mx = 0;

    for (ll i : b)
    {
        mx += ceil((double)i / (double)x);
    }

    if (mx < mn)
        swap(mn, mx);

    cout << mn << " " << mx << '\n';
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