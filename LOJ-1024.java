import java.math.BigInteger;
import java.util.Scanner;
 
class Main{
	public static void main(String args[]) {
 
		Scanner sc = new Scanner(System.in);
 
		int t = sc.nextInt();
 
		for(int tc=1; tc<=t; tc++) {
			int n = sc.nextInt();
 
			BigInteger LCM = sc.nextBigInteger();
 
			for(int i=2; i<=n; i++) {
				BigInteger num = sc.nextBigInteger();
				LCM = (LCM.multiply(num)).divide(LCM.gcd(num));
			}
 
			System.out.println("Case " + tc + ": " + LCM);
			System.gc();
		}
	}
}