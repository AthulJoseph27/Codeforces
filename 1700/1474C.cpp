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
    // 1 2 3 3 4 5 6 7 11 14

    /*
        14 => 11+3 => 5+6 => 4+2 => 1+3
        decomposition should start from the largest number in the array
        and one of the contributing number should be the largest number in the array

        ie largert = second larget + x
    */

    int n;
    cin >> n;

    vector<int> a(2 * n);

    multiset<int> st;

    set<int> stt;

    for (int &i : a)
        cin >> i;

    for (int i : a)
    {
        st.insert(i);
        stt.insert(i);
    }

    vector<pair<int, int>> ans;
    auto ptr = st.end();
    ptr--;
    int largest = *ptr;
    int temp = largest;
    st.erase(ptr);

    for (int i : stt)
    {
        bool found = true;

        largest = temp;

        st.clear();
        for (int j : a)
        {
            st.insert(j);
        }
        ptr = st.find(i);
        st.erase(ptr);

        ptr = st.end();
        ptr--;
        if ((*ptr) != largest)
        {
            continue;
        }
        st.erase(ptr);

        ans.clear();

        while (!st.empty())
        {
            ptr = st.end();
            ptr--;
            int second_largest = *ptr;
            st.erase(ptr);
            int x = largest - second_largest;
            ptr = st.find(x);
            if (ptr == st.end())
            {
                found = false;
                break;
            }
            st.erase(ptr);
            ans.push_back({x, second_largest});
            largest = second_largest;
        }

        if (found)
        {
            cout << "YES\n";
            cout << temp + i << '\n';
            cout << i << " " << temp << '\n';

            for (auto p : ans)
            {
                cout << p.first << " " << p.second << '\n';
            }
            return;
        }
    }

    cout << "NO\n";
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