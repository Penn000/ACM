import java.util.Scanner;

public class Main {
	static int n, m;
	static int[] arr = new int[110];
	
	public static void main(String[] args){
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNext()) {
			n = cin.nextInt();
			m = cin.nextInt();
			for(int i = 0; i < n; i++)
				arr[i] = cin.nextInt();
			
		}
	}
}

