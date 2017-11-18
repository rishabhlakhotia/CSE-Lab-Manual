import java.util.Scanner;

public class Fibonnaci {
	public static void main(String[] args) {
		int a=1, b=1, i, l, t=0;
		Scanner scan = new Scanner(System.in);
		System.out.print("Enter the length of the Fibonnaci sequence: ");
		l = scan.nextInt();
		System.out.print(a);
		for (i=0; i<l; i++) {
			System.out.print(" " + b);
			t = b;
			b = a+b;
			a = t;
		}
		scan.close();
	}
}
