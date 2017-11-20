import java.io.*;
class BRRead {
	public static void main(String args[]) throws IOException
	{
		char c;
		int i;
		FileOutputStream fout = new FileOutputStream(args[0]);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter characters, 'q' to quit.");
		// read characters from console and write to file
		do {
			c = (char) br.read();
			if(c!='q') fout.write(c);
		} while(c!='q');
		fout.close();
		System.out.println("**** Lets display the contents of the file ****");

		//read characters from the file and write back to console
		FileInputStream fin = new FileInputStream(args[0]);
		do {
				i = fin.read();
				if(i != -1) System.out.print((char) i);
		} while(i != -1);
		fin.close();
	}
}
