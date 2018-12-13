import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	static final int N = 110;
	
	static int [][] arr = new int[N][N];
	static int [][][][] dp = new int[N][N][N*2][2]; // dp[i][j][k][l]表示从l方向到达(i,j)点，拐了k次弯的最小代价，令l=0为从左到右，l=1为从上到下
	static int INF = 0x3f3f3f3f;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		int n;
		while(cin.hasNext()) {
			n = cin.nextInt();
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					arr[i][j] = cin.nextInt();
				}
			}
			for(int i = 1; i <= n; i++) 
				for(int j = 1; j <= n; j++) 
					for(int k = 0; k <= i+j; k++) 
						dp[i][j][k][0] = dp[i][j][k][1] = INF;
			dp[1][1][0][0] = arr[1][1];
			dp[1][1][0][1] = arr[1][1];
			for(int i = 1; i <= n; i++) {
				for(int j = 1; j <= n; j++) {
					for(int k = 0; k <= i+j; k++) {
						if(k > 16)continue; // 剪枝
						dp[i][j+1][k][0] = Math.min(dp[i][j+1][k][0], dp[i][j][k][0]+arr[i][j+1]);
						dp[i+1][j][k+1][1] = Math.min(dp[i+1][j][k+1][1], dp[i][j][k][0]+arr[i+1][j]+(int)Math.pow(2, k));
						dp[i+1][j][k][1] = Math.min(dp[i+1][j][k][1], dp[i][j][k][1]+arr[i+1][j]);
						dp[i][j+1][k+1][0] = Math.min(dp[i][j+1][k+1][0], dp[i][j][k][1]+arr[i][j+1]+(int)Math.pow(2, k));
					}
				}
			}
			int ans = INF;
			for(int k = 0; k <= 2*n; k++)
				for(int l = 0; l < 2; l++)
					if(ans > dp[n][n][k][l])
						ans = dp[n][n][k][l];
			System.out.println(ans);
		}
	}

}
