import java.util.*;

public class Main{
	public static void main(String args[]){
		int n;
		Scanner cin = new Scanner(System.in);
		while(cin.hasNext()){
			n = cin.nextInt();
			if(n == 0)break;
			if(n <= 2)System.out.println("Alice");
			else System.out.println("Bob");
		}
	}
}
