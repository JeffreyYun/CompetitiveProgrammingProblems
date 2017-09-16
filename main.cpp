#if 1

// =========== START OF TEMPLATE ==============
#define TESTING
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

double EPS = 1e-9;
int MOD = 1000000007;
int INF = 1000000005;
long long INFF = 1000000000000000005ll;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

#ifdef TESTING
#define DEBUG fprintf(stderr,"====TESTING====\n")
//#define what_is(x) cerr << #x << " is " << x << endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define DEBUG
#define what_is(x)
#define debug(...)
#endif

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        v.emplace_back(x);
    return move(v);
}
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
    cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
    err(++it, args...);
}

#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define REP(i, j) for (int i=0; i<j; i++)
#define RREP(i, j) for (int i=j; i>=0; i--)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((ll)(x) * (x))
#define MEM(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define ALLA(arr,sz) arr,arr+sz
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline void OPEN (string s) {
    string dir = "/home/hunteryun/hackerrank-problems/hackerrank/";
    freopen ((dir + s + ".in").c_str (), "r", stdin);
    freopen ((dir + s + ".out").c_str (), "w", stdout);
}

inline void CLOSE () {
    fclose(stdin);
    fclose(stdout);
}

// =========== END OF TEMPLATE ==============

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void DFS(TreeNode* node, vector<int> &n_max, vector<int> &n_min, int level, int pos);


#define what_is(x) cerr << #x << " is " << x << endl
class Solution {
public:
    string decodeString(string s) {
        stack <string> ops;
        stack <string> text;
        int n = s.length();
        int freq;
        string t,prev;
        for (int i = 0; i < n; i++) {
            switch (s[i]){
            case '[':
                ops.push(to_string(s[i]));
                break;
            case '1':case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':case'0':
                freq = 0;
                freq += s[i] - '0';
                while (s[i] <= '9' && s[i] >= '0') {
                    i++;
                    freq *= 10;
                    freq += s[i] - '0';
                }
                ops.push(to_string(freq));
                break;
            case ']':
                ops.pop();
                freq = stoi(ops.top()); ops.pop();
                t = ops.top(); ops.pop();
                prev = text.top(); text.pop();
                for (int j = 0; j < freq; j++)
                    prev += t;
                text.push(prev);
                what_is(freq);what_is(t);what_is(prev);
                break;
            default:
                t = "";
                while (s[i] >= 'a' && s[i] <= 'z') {
                    t += s[i];
                    i++;
                }
                text.push(t);
            };
        };
        string res = text.top(); text.pop();
        return res;
    }
};

int main() {
    Solution a = Solution();
    cout << a.decodeString("3[a]");
    return 0;
}

#else if 1

{ }

#endif
