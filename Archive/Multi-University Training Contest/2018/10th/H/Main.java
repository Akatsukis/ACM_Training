import java.math.*;
import java.util.*;
public class Main
{
    public static void main(String[] args)
    {
        Scanner cin = new Scanner(System.in);
        int T = cin.nextInt();
        while(T-- != 0){
            int n = cin.nextInt();
            BigInteger ans = new BigInteger("1");
            BigInteger tmp = new BigInteger("2");
            for(int i = 0; i < n; i++){
                ans = ans.multiply(tmp);
            }
            System.out.println(ans);
        }
    }
}
