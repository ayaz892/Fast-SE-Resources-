package examples;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
public class example4 {
public static void main(String[] args) throws FileNotFoundException {
		FileOutputStream f = new FileOutputStream("new.txt" , true);
		//another way to pass file object directly in constructor
		//PrintWriter p = new PrintWriter(new FileOutputStream("new.txt" , true));
		PrintWriter p = new PrintWriter(f);
		p.println("hello this is me");
		System.out.println("written");
		p.close();
}
}
