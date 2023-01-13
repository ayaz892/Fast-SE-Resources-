package examples;

import java.io.*;
public class example7 {
public static void main(String[] args) throws IOException {
	InputStreamReader r=new InputStreamReader(System.in);
		
	
		BufferedReader br = new BufferedReader( r);;

		System.out.println("enter name");
		String s=br.readLine();
		System.out.println("welcome "+s);
		
}}
