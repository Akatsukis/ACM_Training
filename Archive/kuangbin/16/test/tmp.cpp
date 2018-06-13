#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 2000005;

struct TrieNode
{
    int num;    // 到当前节点的字符串个数
    int cnt;    // 当前节点后面回文子串个数
    TrieNode* nxt[26];
};

TrieNode node[MAXN];      // 避免动态申请空间的时间消耗
TrieNode* root;           // trie树的根节点
int bg[MAXN];             // bg[i]第i+1个字符串开始的位置
int ed[MAXN];             // ed[i]第i+1个字符串结束的位置
bool flag[2][MAXN];       // flag[0][i]为true表示原串后面为回文串   flag[1][i]表示反串
char S[MAXN];             // 存放原串
char T[MAXN];             // 存放反串
int nxt[MAXN];            // 存放next数组
int extend[MAXN];         // 用于判断是否为回文子串
LL ans;                   // 保存结果
int tot;                  // node数组的下标

void GetNext(char* T, int lhs, int rhs)
{
    int j = 0;
    while (lhs + j + 1 <= rhs && T[lhs + j] == T[lhs + j + 1]) ++j;
    nxt[lhs + 1] = j;
    int k = lhs + 1;
    for (int i = lhs + 2; i <= rhs; ++i)
    {
        int p = nxt[k] + k - 1;
        int L = nxt[lhs + i - k];
        if (L + i < p + 1) nxt[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j <= rhs && T[lhs + j] == T[i + j]) ++j;
            nxt[i] = j;
            k = i;
        }
    }
}

void ExtendKMP(char* S, char* T, int lhs, int rhs, bool sign)
{
    GetNext(T, lhs, rhs);
    int j = 0;
    while (j + lhs <= rhs && S[j + lhs] == T[j + lhs]) ++j;
    extend[lhs] = j;
    int k = lhs;
    for (int i = lhs + 1; i <= rhs; ++i)
    {
        int p = extend[k] + k - 1;
        int L = nxt[lhs + i - k];
        if (L + i < p + 1) extend[i] = L;
        else
        {
            j = max(0, p - i + 1);
            while (i + j <= rhs && S[i + j] == T[lhs + j]) ++j;
            extend[i] = j;
            k = i;
        }
    }
    for (int i = lhs; i <= rhs; ++i)
    {
        if (extend[i] == rhs - i + 1)
            flag[sign][i] = true;
    }
}

void Insert(char S[], int lhs, int rhs)
{
    TrieNode* temp = root;
    for (int i = lhs; i <= rhs; ++i)
    {
        int ch = S[i] - 'a';
        temp->cnt += flag[0][i];    // 更新当前节点后面回文子串的数目
        if (temp->nxt[ch] == NULL) temp->nxt[ch] = &node[tot++];
        temp = temp->nxt[ch];
    }
    ++temp->num; // 更新到当前节点的字符串数目
}

void Search(char S[], int lhs, int rhs)
{
    TrieNode* temp = root;
    for (int i = lhs; i <= rhs; ++i)
    {
        int ch = S[i] - 'a';
        temp = temp->nxt[ch];
        if (temp == NULL) break;
        if ((i < rhs && flag[1][i + 1]) || i == rhs)
            ans += temp->num;
    }
    if (temp) ans += temp->cnt;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        // 初始化
        tot = 0;
        ans = 0;
        memset(node, 0, sizeof(node));
        memset(flag, 0, sizeof(flag));
        root = &node[tot++];

        int l = 0;
        int L = 0;
        for (int i = 0; i < n; ++i)
        {
            // 输入一组数据
            scanf("%d", &l);
            scanf("%s", S + L);

            // 生成反串
            for (int j = 0; j < l; ++j)
                T[L + j] = S[L + l - 1 - j];

            bg[i] = L;
            ed[i] = L + l - 1;


            ExtendKMP(S, T , bg[i], ed[i], 0);
            ExtendKMP(T, S , bg[i], ed[i], 1);
            Insert(S, bg[i], ed[i]);

            L += l;
        }

        for (int i = 0; i < n; ++i)
            Search(T, bg[i], ed[i]);

        printf("%lld\n", ans);
    }
    return 0;
}
