//2018-03-26
import java.util.*;

public class Main {
	static final int N = 100005;
	static double[][] dp = new double[N][2];
	static int [] arr = new int[N];
	static int [] fa = new int[N];
	static Vector<Integer> [] vec = new Vector[N];
	
	static void dfs(int rt) {
		int len = vec[rt].size();
		dp[rt][1] = arr[rt];
		for(int v: vec[rt]) {
			dfs(v);
		}
		for(int v: vec[rt]) {
			dp[rt][0] += Math.max(dp[v][0], dp[v][1]);
			dp[rt][1] += Math.max(dp[v][1]-0.5*arr[v], dp[v][0]);
		}
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		int n;
		while(cin.hasNext()) {
			n = cin.nextInt();
			for(int i = 1; i <= n; i++) {
				dp[i][0] = dp[i][1] = 0;
				arr[i] = cin.nextInt();
				fa[i] = -1;
				vec[i] = new Vector<Integer>();
			}
			int u, v;
			for(int i = 0; i < n-1; i++) {
				u = cin.nextInt();
				v = cin.nextInt();
				fa[v] = u;
				vec[u].add(v);
			}
			int root = 1;
			while(fa[root] != -1)root = fa[root];
			dfs(root);
			System.out.printf("%.1f\n", Math.max(dp[root][0], dp[root][1]));
		}
	}
}
