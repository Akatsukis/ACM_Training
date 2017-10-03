#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <sstream>
#include <queue>
#include <map>
#include <functional>
#include <bitset>
using namespace std;
char s[800010];

int main()
{
    int p, i, m, l, r, ans;
    scanf("%s", s);
    i = strlen(s);
    ans = 0;
    for(p=0; p<=i-1; p++)
    {
        m = ((i-1)-p) / 2;
        if( ((i-1)-p)%2 == 0 )
        {
            l = p + m - 1;
            r = p + m + 1;
        }
        else
        {
            l = p + m;
            r = p + m + 1;
        }
        while( l >= p )
        {
            if( s[l] == s[r])
            {
                ans++;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
    }
    for(p=i-2; p>=1; p--)
    {
        m = p / 2;
        if( p%2 == 0 )
        {
            l = m - 1;
            r = m + 1;
        }
        else
        {
            l = m;
            r = m + 1;
        }
        while( l >= 0 )
        {
            if( s[l] == s[r] )
            {
                ans++;
                l--;
                r++;
            }
            else
            {
                break;
            }
        }
    }
    printf("%d\n",ans + i);
    return 0;
}
