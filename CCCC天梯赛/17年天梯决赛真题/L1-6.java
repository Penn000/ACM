import java.math.BigInteger;
import java.util.*;
	
public class Main {
	static final int INF = 0x3f3f3f3f;
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		
		int x;
		while(cin.hasNext()) {
			x = cin.nextInt();
			BigInteger xbi = new BigInteger(Integer.toString(x));
			BigInteger tmp = new BigInteger("1");
			int n = 1;
			while(true) {
				if(tmp.mod(xbi).intValue() == 0) {
					System.out.printf("%s %d", tmp.divide(xbi).toString(), n);
					break;
				}
				tmp = tmp.multiply(new BigInteger("10"));
				tmp = tmp.add(new BigInteger("1"));
				n++;
			}
		}
	}
}

