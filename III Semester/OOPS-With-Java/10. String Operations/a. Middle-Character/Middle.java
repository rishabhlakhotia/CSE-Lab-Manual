import java.util.Scanner;

public class Middle { 
	public static void main (String args []) {
		Scanner in = new Scanner(System.in);
		System.out.println("Enter word: ");
		String str = in.next();
		System.out.println("Middle = "  + middle(str));
} //end main

	public static String middle(String str)
	{
		if ((str.length() % 2) == 0)
		{
			if (str.length() > 2) {
				return str.substring(str.length()/2 - 1, str.length()/2 + 1);
			}
			else {
				return str;
			}
		}
		else {return str.substring(str.length()/2,str.length()/2+1);}
	}   // end middle
}
