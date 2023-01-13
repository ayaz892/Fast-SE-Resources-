package taskk2;

//package ex1;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.JFrame;

import java.lang.Math.*;




class firsteq extends JFrame
{ 
   JTextField a1,a2,a3,a4,a5,a6,a7,a8,a9;
   firsteq()
   {
	   
	JLabel b1=new JLabel("centre (x1):");
	
    JLabel b2=new JLabel("centre (y1):");
    
    JLabel b3=new JLabel("point(x2):");
    JLabel b4=new JLabel("point(y2):");
    
    JLabel b5=new JLabel("Distance (S)=");
    JLabel b6=new JLabel("Radius (r)=");
    JLabel b7=new JLabel("Digonal (d)=");
    JLabel b8=new JLabel("Circumference (C)=");
    JLabel b9=new JLabel("Area (A)=");
    
  
    a1=new JTextField(15);
    a2=new JTextField(15);
    a3=new JTextField(15);
    a4=new JTextField(15);
    a5=new JTextField(15);
    a6=new JTextField(15);
    a7=new JTextField(15);
    a8=new JTextField(15);
    a9=new JTextField(15);
  
    JPanel j1=new JPanel(new GridLayout(10,2));
  
    JButton j2 = new JButton("Find");
  
    j2.addActionListener(new ActionListener(){
    	
    	
	  public void actionPerformed(ActionEvent e){
		  
    	String n1=a1.getText();
        String n2=a2.getText();
        String n3=a3.getText();
        String n4=a4.getText();
      
        
        
        int number1 = Integer.parseInt(n1);
        int number2 = Integer.parseInt(n2);
        int number3 = Integer.parseInt(n3);
        int number4 = Integer.parseInt(n4);
        
        Double Distance=Math.sqrt((number3-number1)*(number3-number1)+(number4-number2)*(number4-number2));
        Double Radius=Distance;
        Double Digonal=2*Radius;
        Double Circum=2*(3.14)*Radius;
        Double Area=(3.14)*(Radius)*2;
      
        a5.setText(Double.toString(Distance));
        a6.setText(Double.toString(Radius));
        a7.setText(Double.toString(Digonal));
        a8.setText(Double.toString(Circum));
        a9.setText(Double.toString(Area));
        
        
        
    }
});
    j1.add(b1);
    j1.add(a1);
    
    j1.add(b2);
    j1.add(a2);
    
    j1.add(b3);
    j1.add(a3);
    
    j1.add(b4);
    j1.add(a4);
    
    j1.add(b5);
    j1.add(a5);
    
    j1.add(b6);
    j1.add(a6);
    
    j1.add(b7);
    j1.add(a7);
    
    j1.add(b8);
    j1.add(a8);
    
    j1.add(b9);
    j1.add(a9);
    
    
    j1.add(j2);
    add(j1);
    
    setVisible(true);

    pack();
  
}

	
	public static void main(String[] args) {
		
		new firsteq();
	
	}

}
