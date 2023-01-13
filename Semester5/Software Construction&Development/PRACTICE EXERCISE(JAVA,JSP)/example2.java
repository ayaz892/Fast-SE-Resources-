package examples;

import java.io.FileOutputStream;
import java.io.IOException;
public class example2 {
	public static void main(String args[]) throws IOException {
		FileOutputStream o = new FileOutputStream("new.txt" , true);
		String s = "i am ayaz";
		byte[] b = s.getBytes();
		o.write(b);
		o.close();
		System.out.println("hello");
	}
}
