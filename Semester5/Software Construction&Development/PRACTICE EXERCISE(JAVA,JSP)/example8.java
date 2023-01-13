package examples;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;
public class example8 {
public static void main(String[] args) throws IOException {
		FileInputStream f = null;
		try {
			f = new FileInputStream("new.txt");
			Scanner s = new Scanner(f);
			while(s.hasNext()) {
				System.out.println(s.nextLine());
			}} 
		catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		finally {
		f.close();	
		}}}

