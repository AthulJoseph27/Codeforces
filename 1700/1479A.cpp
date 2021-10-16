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

int query(int index)
{
    cout << "? " << (index + 1) << endl;
    int d;
    cin >> d;
    return d;
}

void output(int ans)
{
    cout << "! " << ans << endl;
}

void rec(int l, int r, vector<int> &a)
{
    if (found)
        return;

    if (l > r)
        return;

    if (l == r)
    {
        output(l + 1);
        found = true;
        return;
    }

    int mid = (l + r) / 2;

    a[mid] = query(mid);
    a[mid + 1] = query(mid + 1);

    if (a[mid] > a[mid + 1])
        rec(mid + 1, r, a);
    else
        rec(l, mid, a);
}

void solve(int cc)
{
    found = false;
    int n;
    cin >> n;

    if (n == 1)
    {
        output(1);
        return;
    }

    if (n == 2)
    {
        n = query(0);
        if (n == 1)
            output(1);
        else
            output(2);
        return;
    }

    vector<int> a(n);

    // check the border

    a[0] = query(0);
    a[1] = query(1);

    if (a[0] < a[1])
    {
        output(1);
        return;
    }

    a[n - 1] = query(n - 1);
    a[n - 2] = query(n - 2);

    if (a[n - 1] < a[n - 2])
    {
        output(n);
        return;
    }

    rec(1, n - 2, a);

    if (!found)
    {
        for (int i = 1; i < n; i++)
        {
            if (a[i] < min(a[i - 1], a[i + 1]))
            {
                output(i + 1);
                return;
            }
        }
    }

    assert(found);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}