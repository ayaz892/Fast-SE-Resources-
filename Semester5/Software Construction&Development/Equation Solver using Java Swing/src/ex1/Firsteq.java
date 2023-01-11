package ex1;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import javax.swing.JFrame;



class Firsteq extends JFrame
{ 
   JTextField a1,a2,a3,a4;
   Firsteq()
   {
	   
	JLabel b1=new JLabel("Intitial Velocity (Vi):");
	
    JLabel b2=new JLabel("Time in seconds (t):");
    
    JLabel b3=new JLabel("Acceleration (a):");
    
    JLabel b4=new JLabel("Distance (S)=");
  
    a1=new JTextField(15);
    a2=new JTextField(15);
    a3=new JTextField(15);
    a4=new JTextField(15);
  
    JPanel j1=new JPanel(new GridLayout(5,2));
  
    JButton j2 = new JButton("Find");
  
    j2.addActionListener(new ActionListener(){
    	
    	
	  public void actionPerformed(ActionEvent e){
		  
    	String n1=a1.getText();
        String n2=a2.getText();
        String n3=a3.getText();
        
        int number1 = Integer.parseInt(n1);
        int number2 = Integer.parseInt(n2);
        int number3 = Integer.parseInt(n3);
       
        Double distance=(number1*number2) + (0.5)*(number3)*(number2*number2);
   
        a4.setText(Double.toString(distance));
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
    
    j1.add(j2);
    add(j1);
    
    setVisible(true);

    pack();
  
}

	
	public static void main(String[] args) {
		
		Firsteq q1=new Firsteq();
	
	}

}
