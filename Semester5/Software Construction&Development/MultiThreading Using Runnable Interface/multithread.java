package com;
import java.util.Scanner;

//Gravitaional Force F = (G*m1*m2)/r2

import java.io.*;
import java.util.*;

class multithread implements Runnable{  
	 public static void main(String args[]){  
		
		 
		 Scanner s=new Scanner(System.in);
		 System.out.println("Enter Gravitaional Constant:");
		 float G=s.nextFloat();
		 System.out.println("Enter mass1 of body:");
		 float m1=s.nextFloat();
		 System.out.println("Enter mass2 of body:");
		 float m2=s.nextFloat();
		 System.out.println("Enter radius:");
		 float r=s.nextFloat();
		 
		  

	  Runnable r1=new Runnable(){  
	    public void run(){  
	      System.out.println("Using Thread 1 value of G is: "+G);  
	    }  
	  };  
	  
	  Runnable r2=new Runnable(){  
	    public void run(){  
		      System.out.println("Using Thread 2 value of m1 is: "+m1);  
	    }  
	  };  
	  
	  Runnable r3=new Runnable(){  
		    public void run(){  
			      System.out.println("Using Thread 3 value of m2 is: "+m2);  
		    }  
		  }; 
		  
		  Runnable r4=new Runnable(){  
			    public void run(){  
				      System.out.println("Using Thread 4 value of r is: "+r);  
			    }  
			  };
			  
			 float F=(G*m1*m2)/(r*r);
			  Runnable r5=new Runnable(){  
				    public void run(){  
					      System.out.println("Gravitational Force[F = (G*m1*m2)/r2]= "+F);  
				    }  
				  }; 

			  

	      
	  Thread t1=new Thread(r1);  
	  Thread t2=new Thread(r2);
	  Thread t3=new Thread(r3); 
	  Thread t4=new Thread(r4);
	  Thread t5=new Thread(r5);

	  
	  t1.start();  
	  try {
		t1.join();
	} catch (InterruptedException e) {
		e.printStackTrace();
	}
	  t2.start();
	  try {
		t2.join(1000);
	} catch (InterruptedException e) {
		e.printStackTrace();
	}
	  t3.start();
	  try {
		t3.join(1000);
	} catch (InterruptedException e) {
		e.printStackTrace();
	}
	  t4.start();
	  try {
		t4.join(1000);
	} catch (InterruptedException e) {
		e.printStackTrace();
	}
	  t5.start();
	 }

	@Override
	public void run() {
				
	}  

}