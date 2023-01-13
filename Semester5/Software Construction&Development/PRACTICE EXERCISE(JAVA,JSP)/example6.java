package examples;

import java.io.FileInputStream;
import java.io.IOException;
public class example6 {
public static void main(String[] args) throws IOException {
		FileInputStream f = new FileInputStream("new.txt");
		int i = 0;
		 while((i=f.read())!= -1) {
			 System.out.print((char)i);
		 }
		 f.close(); 
}}
