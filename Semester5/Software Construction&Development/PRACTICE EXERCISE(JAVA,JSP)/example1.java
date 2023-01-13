package examples;

import java.io.FileOutputStream;
import java.io.IOException;
public class example1 {
public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		FileOutputStream o = new FileOutputStream("new.txt" , true);
		o.write(65);
		o.close();
		System.out.println("hello scd");
}}
