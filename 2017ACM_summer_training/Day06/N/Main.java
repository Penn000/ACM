import java.util.*;

public class Main{
	static final int N = 60;
	static int[] fa = new int[N];
	static int[] arr = new int[N];
	static long[] pow = new long[N];

	static void init(){
		pow[0] = 1;
		for(int i = 1; i < N; i++){
			fa[i] = i;
			pow[i] = pow[i-1]*2;
		}
	}
	
	static int getfa(int x){
		if(fa[x] ==  x)return x;
		return fa[x] = getfa(fa[x]);
	}

	static void merge(int a, int b){
		int af = getfa(a);
		int bf = getfa(b);
		if(af != bf)
			fa[bf] = af;
	}

	public static void main(String args[]){
		int n, m, a, b;
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			n = cin.nextInt();
			m = cin.nextInt();
			init();
			for(int i = 0; i < m; i++){
				a = cin.nextInt();
				b = cin.nextInt();
				merge(a, b);
			}
			int cnt = 0;
			for(int i = 1; i <= n; i++)
				if(fa[i] == i)
					cnt++;
			if(m == 0)System.out.printf("1\n");
			else System.out.println(pow[n-cnt]);
		}
	}
}
