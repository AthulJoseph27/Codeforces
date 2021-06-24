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

int qCount = 0;

int query(int l, int r)
{
    assert(qCount < 20);

    cout << "? " << (l + 1) << ' ' << (r + 1) << endl;

    int index;
    cin >> index;

    index--;
    qCount++;

    return index;
}

void solve(int cc)
{
    int n;
    cin >> n;

    qCount = 0;

    /*
        query the entire array to find the index of the second largest element
        query either one half and find out which half the largest element is in

        do smart queries, ie 1 query per iteration ~ 2 + log(10^5) ~ 19
    */

    int l = 0, r = n - 1, mid;

    int sli = query(l, r);

    mid = (l + r) / 2;

    if (sli != 0 && query(0, sli) == sli)
    {
        // largest is in the range [mid .... r]
        r = sli;

        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (query(mid, sli) == sli)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
    }
    else
    {
        // largest is in the range [l .... mid-1]
        l = sli;

        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (query(sli, mid) == sli)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
    }

    int q = query(l, r);
    if (q == l)
    {
        cout << "! " << (r + 1) << endl;
    }
    else
    {
        cout << "! " << (l + 1) << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(1);

    return 0;
}

// 5
// 4 1 5 2 3