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
    int n, ln;
    cin >> n >> ln;

    vector<int> a(n);

    for (int &i : a)
        cin >> i;

    int l = 0, r = n - 1;
    double lpos = 0, rpos = ln;
    int vl = 1, vr = 1;

    double cur_time = 0;

    while (l <= r)
    {
        double t1 = ((double)a[l] - lpos) / (double)vl;
        double t2 = (rpos - (double)a[r]) / (double)vr;

        cur_time += (1'000'000'000 * min(t1, t2));

        if (t1 == t2)
        {
            vl++;
            vr++;
            lpos = a[l];
            rpos = a[r];
            l++;
            r--;
        }
        else if (t1 > t2)
        {
            rpos = a[r];
            lpos += ((double)vl * t2);
            vr++;
            r--;
        }
        else
        {
            lpos = a[l];
            rpos -= ((double)vr * t1);
            vl++;
            l++;
        }
    }

    double dist = rpos - lpos;
    dist *= 1'000'000'000;
    double speed = vl + vr;
    speed *= 1'000'000'000;

    double time = cur_time / 1'000'000'000 + dist / speed;

    printf("%.15llf\n", time);
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