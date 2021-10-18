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

class SegTree
{

    // PASS VECTOR BY REFERENCE , ELSE TIME COMPLEXITY WILL BE O(N^2)

public:
    int leftmost, rightmost;
    int val;
    SegTree *lChild, *rChild, *parent;

    SegTree(int leftmost, int rightmost, SegTree *parent, vector<SegTree *> &a)
    {
        // Here a is a array used to store the leaf nodes
        // pass the array instead and do necessarry changes if a is to be converted into SegTree

        this->leftmost = leftmost;
        this->rightmost = rightmost;
        this->val = 0;
        this->parent = parent;

        if (leftmost == rightmost)
        {
            lChild = NULL;
            rChild = NULL;

            a.push_back(this);
        }
        else
        {
            int mid = (leftmost + rightmost) / 2;

            lChild = new SegTree(leftmost, mid, this, a);
            rChild = new SegTree(mid + 1, rightmost, this, a);

            recalc();
        }
    }

    void recalc()
    {
        if (leftmost == rightmost)
            return;
        this->val = lChild->val + rChild->val;
    }

    void pointUpdate(int index, int val)
    {
        if (leftmost == rightmost)
        {
            this->val = val;
            return;
        }

        if (index <= lChild->rightmost)
        {
            lChild->pointUpdate(index, val);
        }
        else
        {
            rChild->pointUpdate(index, val);
        }

        recalc();
    }

    void rangeUpdate(int l, int r, int val)
    {
        if (l > r)
            return;

        if (l == leftmost && r == rightmost)
        {
            if (l == val || this->val != 0)
                return;

            this->val = val;
            return;
        }

        if (l >= leftmost && r <= rightmost)
        {

            if (this->val != 0)
                return;

            int mid = (leftmost + rightmost) / 2;

            if (l > mid)
            {
                rChild->rangeUpdate(l, r, val);
            }
            else if (r <= mid)
            {
                lChild->rangeUpdate(l, r, val);
            }
            else
            {
                lChild->rangeUpdate(l, mid, val);
                rChild->rangeUpdate(mid + 1, r, val);
            }
            return;
        }
    }

    void deleteChild()
    {
        if (lChild != NULL)
        {
            lChild->deleteChild();
            delete lChild;
        }
        if (rChild != NULL)
        {
            rChild->deleteChild();
            delete rChild;
        }
    }
};

void solve(int cc)
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    /*
        -+--+--+

        1  2 2 2  3  3  3  4  4  

        0 -1 0 -1 -2 -1 -2 -3 -2
        '' -> 1
        '-' -> 2
        '---+' -> 4
        '+--+--+' -> 4
        
    */

    vector<int> prefs_min = {0}, prefs_max = {0}, prefs_cur = {0};
    vector<int> sufx_min = {0}, sufx_max = {0}, sufx_cur = {0};

    int x = 0, cur_min = 0, cur_max = 0;

    for (char c : s)
    {
        if (c == '+')
            x++;
        else
            x--;
        cur_min = min(cur_min, x);
        cur_max = max(cur_max, x);
        prefs_cur.push_back(x);
        prefs_min.push_back(cur_min);
        prefs_max.push_back(cur_max);
    }

    // prefs_cur.push_back(prefs_cur.back());
    // prefs_min.push_back(prefs_min.back());
    // prefs_max.push_back(prefs_max.back());

    reverse(all(s));

    x = cur_min = cur_max = 0;

    for (char c : s)
    {
        if (c == '-')
            x++;
        else
            x--;
        cur_min = min(cur_min, x);
        cur_max = max(cur_max, x);
        sufx_min.push_back(cur_min);
        sufx_cur.push_back(x);
        sufx_max.push_back(cur_max);
    }

    reverse(all(sufx_min));
    reverse(all(sufx_cur));
    reverse(all(sufx_max));

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        // 0 to l-1
        int mn = prefs_min[l], mx = prefs_max[l];

        int neg_delta = sufx_cur[r + 1] - sufx_min[r + 1];
        int posi_delta = sufx_max[r + 1] - sufx_cur[r + 1];

        mn = min(mn, prefs_cur[l] - neg_delta);
        mx = max(mx, prefs_cur[l] + posi_delta);

        // debug(mn, mx);
        cout << mx - mn + 1 << '\n';
    }
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