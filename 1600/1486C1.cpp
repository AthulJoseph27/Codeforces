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

bool found = false;

int cnt = 0;

int query(int l, int r)
{
    int index;
    cnt++;

    assert(cnt < 41);

    cout << "? " << (l + 1) << ' ' << (r + 1) << endl;

    cin >> index;

    index--;

    return index;
}

void solve(int n)
{
    int l = 0, r = n - 1;

    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        int si = query(l, r);

        if (si <= mid)
        {
            int q2 = query(l, mid);
            if (q2 == si)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        else
        {
            int q2 = query(mid, r);
            if (q2 == si)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
    }
    int q2 = query(l, r);
    if (q2 == r)
        cout << "! " << (l + 1) << endl;
    else
        cout << "! " << (r + 1) << endl;
    return;
}

// 4 3 2 1 5

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    solve(n);

    return 0;
}