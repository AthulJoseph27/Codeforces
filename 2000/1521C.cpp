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

long long queryCount = 0;

int query(int t, int x, int i, int j)
{
    queryCount++;
    cout << "? " << t << ' ' << (i + 1) << ' ' << (j + 1) << ' ' << x << '\n';
    cout.flush();

    int sm;

    cin >> sm;

    assert(sm != -1);

    return sm;
}

void solve(int cc)
{

    int n;
    cin >> n;

    assert(n != -1);

    vector<int> a(n);

    bool hseen = false;
    bool lseen = false;

    /*
            t1 = max(min(pi,x),min(pj,x+1))
            t2 = min(max(pi,x),max(pj,x+1))
     
            max(min(n-1,pi),min(n,pj))
            max(min(n-1,pi),pj)
            output is n, then pj == n
            if pj == n:
                min(pi,pj) = pi
     
     
            min(max(pi,1),max(pj,2))
            if pi == 1 then output is 1

            t1 = n-1 t2 = 2

            max(min(pi,n-1),min(pj,n)) = n-1

            pi == n and pj == 1
            min(max(1,pi),max(2,pj)) = 2
     
        */

    for (int i = 1; i < n; i += 2)
    {
        int t1 = query(1, n - 1, i, i - 1);
        int t2 = query(2, 1, i, i - 1);

        if (t1 == n)
        {
            a[i - 1] = n;
            a[i] = t2;
        }
        if (t2 == 1)
        {
            a[i] = 1;
            a[i - 1] = t1;
        }

        /*
                min(max(1,pi),max(2,pj))
                if pj == 1 and pi>=2
                output is 2
                max(min(pi,n-1),min(pj,n)) = max(pi,pj) = pi
            */
        if (a[i] == 0 && t2 == 2)
        {
            int t3 = query(2, 1, i - 1, i);
            if (t3 == 1)
            {
                a[i - 1] = 1;
                int t4 = query(1, n - 1, i - 1, i);
                if (t4 == n)
                {
                    a[i] = n;
                }
                else
                {
                    a[i] = t1;
                }
            }
        }
        if (a[i] == 0 && t1 == n - 1)
        {
            int t3 = query(1, n - 1, i - 1, i);
            if (t3 == n)
            {
                a[i] = n;
                int t4 = query(2, 1, i - 1, i);
                if (t4 == 1)
                {
                    a[i - 1] = 1;
                }
                else
                {
                    a[i - 1] = t2;
                }
            }
        }

        if (a[i] == 0 && a[i - 1] == 0)
        {
            int t3 = query(1, t2, i - 1, i);
            /*
                    t1 = max(pi,pj)
                    t2 = min(pi,pj)
                    t3 = max(min(pj,t2),min(t2+1,pi))
                    if pi>pj
                        max(t2,t2+1) = t2+1
                    else
                        max(pi,pi) = pi = t2
                */

            if (t2 == t3)
            {
                a[i] = t2;
                a[i - 1] = t1;
            }
            else
            {
                a[i] = t1;
                a[i - 1] = t2;
            }
        }
    }

    unordered_map<int, int> seen;

    for (int i = 0; i < n; i++)
    {
        seen[a[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (seen[i] == 0)
        {
            a[n - 1] = i;
            break;
        }
    }

    cout << "! ";

    for (int i : a)
        cout << i << ' ';

    cout << '\n';

    cout.flush();
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