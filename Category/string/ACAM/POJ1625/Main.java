import java.math.*;
import java.io.*;
import java.util.*;

public class Main{
    static final int maxn = 110;
    static final BigInteger zero = BigInteger.ZERO, one = BigInteger.ONE;
    static int nxt[][] = new int [maxn][256], fail[] = new int [maxn], last[] = new int [maxn];
    static int code[] = new int [256];
    static int idx;
    public static void init(int u)
    {
        for(int i = 0; i < 256; i++)nxt[u][i] = -1;
        fail[u] = last[u] = 0;
    }
    public static void init()
    {
        init(0);
        idx = 0;
    }
    public static void insert(String s)
    {
        int rt = 0;
        for(int i = 0; i < s.length(); i++){
            int u = s.charAt(i);
            int v = code[u];
            if(nxt[rt][v] == -1){
                nxt[rt][v] = ++idx;
                init(idx);
            }
            rt = nxt[rt][v];
        }
        last[rt] = 1;
    }
    public static void getFail(int n)
    {
        Queue<Integer> q = new LinkedList<Integer>();
        int rt = 0;
        for(int i = 0; i < n; i++){
            if(nxt[rt][i] == -1)nxt[rt][i] = rt;
            else{
                fail[nxt[rt][i]] = rt;
                q.add(nxt[rt][i]);
            }
        }
        while(!q.isEmpty()){
            int u = q.remove();
            for(int i = 0; i < n; i++){
                int v = nxt[u][i], w = fail[u];
                if(v == -1)nxt[u][i] = nxt[w][i];
                else{
                    fail[v] = nxt[w][i];
                    if(last[fail[v]] == 1)last[v] = 1;
                    q.add(v);
                }
            }
        }
    }
    public static void main(String args[])
    {
        init();
        Scanner cin = new Scanner(new BufferedInputStream(System.in), "ISO-8859-1");
        int n = cin.nextInt(), m = cin.nextInt(), p = cin.nextInt();
        String t = cin.nextLine();
        t = cin.nextLine();
        for(int i = 0; i < t.length(); i++){
            int c = t.charAt(i);
            code[c] = i;
        }
        for(int i = 0; i < p; i++){
            String s = cin.next();
            insert(s);
        }
        getFail(n);
        BigInteger dp[][] = new BigInteger [60][110];
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= idx; j++)dp[i][j] = zero;
        }
        dp[0][0] = one;
        for(int i = 0; i < m; i++){
            for(int j = 0; j <= idx; j++){
                if(last[j] == 1)continue;
                for(int k = 0; k < n; k++){
                    int np = nxt[j][k];
                    if(last[np] == 1)continue;
                    dp[i+1][np] = dp[i+1][np].add(dp[i][j]);
                }
            }
        }
        BigInteger ans = zero;
        for(int i = 0; i <= idx; i++){
            ans = ans.add(dp[m][i]);
        }
        System.out.println(ans);
    }
}

