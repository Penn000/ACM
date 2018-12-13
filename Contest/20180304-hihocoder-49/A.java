import java.io.BufferedInputStream;
import java.util.Scanner;

public class Main {
	static final char[] hex = new char[] {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'}; 
	
	public static int transform(char ch) {
		int res = 0;
		if(ch >= '0' && ch <= '9')res = ch-'0';
		if(ch >= 'a' && ch <= 'f')res = ch-'a'+10;
		return res;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		
		String str;
		while(cin.hasNext()) {
			str = cin.nextLine();
			int a = 16*transform(str.charAt(1))+transform(str.charAt(2));
			int b = 16*transform(str.charAt(3))+transform(str.charAt(4));
			int c = 16*transform(str.charAt(5))+transform(str.charAt(6));
			int aa = a / 17;
			if(a-17*aa > 17*aa+17-a)aa += 1;
			int bb = b / 17;
			if(b-17*bb > 17*bb+17-b)bb += 1;
			int cc = c / 17;
			if(c-17*cc > 17*cc+17-c)cc += 1;
			if(aa>=16)aa = 15;
			if(bb >= 16) bb = 15;
			if(cc >= 16) cc = 15;
			System.out.println("#"+hex[aa]+hex[bb]+hex[cc]);
		}
	}

}
