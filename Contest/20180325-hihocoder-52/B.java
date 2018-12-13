import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	static int[] dx = {0, 1, 0, -1};
	static int[] dy = {1, 0, -1, 0};
	static StringBuilder[] M = new StringBuilder[20];
	static int n, m;
	static Map<String, Long> dp = new HashMap<String, Long>();
	
	static String MtoString() {
		StringBuilder sb = new StringBuilder("");
		for(int i = 0; i < n; i++) {
			sb.append(M[i]);
		}
		return sb.toString();
	}
	
	static boolean isOK(int x, int y) {
		for(int i = 0; i < 4; i++){
	        int nx = x + dx[i];
	        int ny = y + dy[i];
	        if(nx < 0 || nx >= n || ny < 0 || ny >= m)
	          continue;
	        if(M[nx].charAt(ny) == '1')return true;
	    }
	    return false;
	}
	
	static long dfs(int mie) {
		if(mie == 1)return 1;
		if(dp.get(MtoString()) != null)return dp.get(MtoString());
		long sum = 0;
		for(int i = 0; i < n; i++){
	        for(int j = 0; j < m; j++){
	            if(M[i].charAt(j) == '0' && isOK(i, j)){
	                M[i].setCharAt(j, '1');
	                sum += dfs(mie-1);
	                M[i].setCharAt(j, '0');
	            }
	        }
	    }
		dp.put(MtoString(), sum);
		return sum;
	}
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		int mie;
		while(cin.hasNext()) {
			dp.clear();
			n = cin.nextInt();
			m = cin.nextInt();
			mie = 0;
			for(int i = 0; i < n; i++) {
				M[i] = new StringBuilder(cin.next());
				for(int j = 0; j < m; j++)
					if(M[i].charAt(j) == '0')
						mie++;
			}
			System.out.println(dfs(mie));
		}
	}
}
