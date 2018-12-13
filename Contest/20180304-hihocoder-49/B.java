import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	static final int N = 110;
	static final long MOD = 1000000009;
	
	static long pow(long a, long n) {
		long ans = 1;
		while(n != 0) {
			if((n & 1) != 0) ans = ans*a%MOD;
			a = a*a%MOD;
			n >>= 1;
		}
		return ans;
	}
	
	static long inv(long x) {
		return pow(x, MOD-2);
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n, m, k, a;
		long [] fact = new long[N];
		fact[0] = 1;
		for(int i = 1; i < 105; i+=1) {
			fact[i] = (long) (fact[i-1]*i%MOD);
		}
		while(cin.hasNext()) {
			n = cin.nextInt();
			m = cin.nextInt();
			k = cin.nextInt();
			int[] cnt = new int[N];
			for(int i = 0; i < n; i+=1) {
				a = cin.nextInt();
				cnt[a%k] += 1;
			}
			long ans = 0;
			for(int i = 0; i < k; i+=1) {
				if(cnt[i] >= m)
					ans += (((fact[cnt[i]]*inv(fact[m]))%MOD*inv(fact[cnt[i]-m]))%MOD)%MOD;
			}
			System.out.println(ans);
		}
		
	}

}
