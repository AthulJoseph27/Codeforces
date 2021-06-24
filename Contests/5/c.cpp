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

    /*
        t=1 max(min(x,pi),min(x+1,pj))
        t=2 min(max(x,pi),max(x+1,pj)).

        for t = 1,
        if x = n-1
        then the output will be n or max(pi, pj)
        if the output is n, then pj is n

        for t = 2,
        x = 1
        then the output will be 1 or min(pi,pj)
        if output is 1 , then  pi is 1

        assume pi and pj not equal to n-1 and n

        max(min(pi,n-1),min(x+1,pi)) = max(pi,pj)
        

     */

    // unordered_map<int, int> mp;

    int mx = n - 1;
    int mn = 1;

    for (int i = 1; i < n; i += 2)
    {
        // debug(a);
        // atmost 5 queries to find out 2 values , but using all 5 query should be very rare
        // 2 5 3 4 1

        int t1 = query(1, mx, i, i - 1);
        int t2 = query(2, mn, i, i - 1);
        if (t1 == mx + 1)
        {
            /*
                what if t2 = mn+1
                min(max(pi,mn),max(pj,mn+1))
                pj < mn+1
                min(pi,mn+1) = mn+1
            */
            a[i - 1] = t1;
            // mx--;
        }
        if (t2 == mn)
        {
            a[i] = t2;
            // mn++;
        }

        if (t1 == mx)
        {
            /*
                t=1 max(min(x,pi),min(x+1,pj))
                t=2 min(max(x,pi),max(x+1,pj))

                for t = 1
                if pi > x and pj < x:
                    max(x,pj) = x
                    swap i and j and query
                    max(min(x,pj),min(pi,x+1))
                    pi cannot be greater than x+1
                    max(pi,pj) = pi
            */
            int t4 = query(1, mx, i - 1, i);
            if (t4 == mx + 1)
            {
                a[i] = mx + 1;
                // mx--;
            }
            else
            {
                a[i] = mx;
            }
        }

        if (t2 == mn + 1)
        {
            /*
                t=1 max(min(x,pi),min(x+1,pj))
                t=2 min(max(x,pi),max(x+1,pj))

                for t = 2
                if pi > x+1 and pj <= x+1:
                    min(pi,x+1) = x+1
                    swap i and j and query
                    min(max(x,pj),min(pi,x+1))
                    min(max(x,pj),x+1)
                    if pj == x+1 , then output will be x+1
                    else output will be x
                    max(pi,pj) = pi
            */
            int t4 = query(2, mn, i - 1, i);
            if (t4 == mn + 1)
            {
                a[i - 1] = mn + 1;
                // mn++;
            }
            else
            {
                a[i - 1] = mn;
            }
        }

        if (a[i] != 0 && a[i - 1] == 0)
        {
            a[i - 1] = t1;
        }
        else if (a[i - 1] != 0 && a[i] == 0)
        {
            a[i] = t2;
        }

        if (a[i] == 0 && a[i - 1] == 0)
        {
            /*
                t1 = max(a[i],a[i-1])
                t2 = min(a[i],a[i-1])

                assume a[i] > a[i-1]

                query with a[i] , a[i-1] , t2
                max(min(a[i],t2),min(t2+1,a[i-1]))
                if a[i-1] is the minimum
                    max(t2,a[i-1]) = t2
                else
                    max(a[i],t2+1) = t2+1 or a[i-1]
                
            */
            int t3 = query(1, t2, i, i - 1);

            if (t3 == t2)
            {
                // second element is the minimum
                a[i - 1] = t2;
                a[i] = t1;
            }
            else
            {
                a[i - 1] = t1;
                a[i] = t2;
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

/*
    2 5 3 4 1
    max(min(4,5),min(5,2)) = 4
    min(max(1,5),max(2,2)) = 2
    max(min(2,4),min(5,5)) = 5
    min(max(2,1),max(5,2)) = 2
    max(min(3,4),min(4,3)) = 3
    min(max(2,4),max(3,3)) = 3
    max(min(3,3),min(4,4)) = 4
    min(max(3,2),max(4,3)) = 3

    3 1 4 2
    max(min(3,1),min(4,3)) = 3
    min(max(1,1),max(2,3)) = 1
    min(max(3,3),max(4,1)) = 3
    max(min(3,2),min(4,4)) = 4
    min(max(1,2),max(2,4)) = 2
    min(max(1,4),max(2,2)) = 2

*/
