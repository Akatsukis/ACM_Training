#include <stdio.h>

int Stack[100000];
int top, sz;

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        while(sz && Stack[top] < x){
            top--;
            sz--;
        }
        ans += sz;
        Stack[++top] = x;
        sz++;
    }
    printf("%d\n", ans);
	return 0;
}


