import java.util.Arrays;
import java.util.Scanner;

public class A {
	
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int n;
		String str;
		while(cin.hasNext()) {
			n = cin.nextInt();
			str = cin.next();
			Node.calOrd(str);
			Node[] nodes = new Node[n];
			for(int i = 0; i < n; i++) {
				String ss = cin.next();
				nodes[i].setSb(new StringBuilder(ss));
			}
			Arrays.sort(nodes);
			for(Node node: nodes) {
				System.out.println(node.sb.toString());
			}
		}
	}
}

class Node{
	static int[] ord = new int[26];
	public StringBuilder sb;
	
	static public void calOrd(String str) {
		for(int i = 0; i < 26; i++) {
			ord[str.charAt(i)-'a'] = i;
		}
	}
	
	public void setSb(StringBuilder _sb) {
		this.sb = _sb;
	}
	
	public int compareTo(Node x) {
		int len1 = sb.length();
		int len2 = x.sb.length();
		for(int i = 0; i < len1 && i < len2; i++) {
			if(sb.charAt(i) == x.sb.charAt(i))continue;
			return ord[sb.charAt(i)-'a'] < ord[x.sb.charAt(i)-'a'] ? -1 : 1;
		}
		if(len1 < len2)return -1;
		else return 1;
	}
}
