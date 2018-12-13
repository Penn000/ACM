import java.util.Arrays;
import java.util.Scanner;

public class Main
{
	static final int N = 100005;
    public static void main(String[] args)
    {
    	Scanner cin = new Scanner(System.in);
        int n;
        int[] arr = new int[N];
        while(cin.hasNext()) {
        	n = cin.nextInt();
        	for(int i = 0; i < n; i++)
        		arr[i] = cin.nextInt();
        	Arrays.sort(arr, 0, n);
        	int in = n/2;
        	int sumIn = 0, sumOut = 0;
        	for(int i = 0; i < n; i++)
        		if(i < in) sumIn += arr[i];
        		else sumOut += arr[i];
        	System.out.printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n", n-in, in, sumOut-sumIn);
        }
    }
}
