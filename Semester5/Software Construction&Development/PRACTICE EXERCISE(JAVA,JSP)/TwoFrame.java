import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class TwoFrame implements ActionListener {
	static JFrame f1;
	static JFrame f2;
	static JButton next1;
	static JButton close1;
	static JButton back1;
	

	public static void main(String[] args) {
		
		f1=new JFrame("Frame1");
		f1.setSize(250,250);
		f1.setLayout(null);
		f1.setBackground(Color.white);
		next1=new JButton("Next");
		close1=new JButton("Close");
		next1.setBounds(75, 50, 100,50);
		close1.setBounds(75,150,100,50);
		f1.add(next1);
		f1.add(close1);
		TwoFrame obj=new TwoFrame();
		next1.addActionListener(obj);
		close1.addActionListener(obj);
		f1.setVisible(true);
		

	}


	@Override
	public void actionPerformed(ActionEvent e) {
		String button=e.getActionCommand();
		if(button.equals("Next"))
		{
			create_f2();
		}
		if(button.equals("Close"))
		{
			f1.dispose();
		}
		if(button.equals("Back"))
		{
			f2.dispose();
		}

		
	}


	private void create_f2() {
		
		f2 = new JFrame("Frame 2");
		f2.setSize(250,250);
		f2.setLayout(null);
		f2.setBounds(75,100,100,50);
		back1=new JButton("Back");
		f2.add(back1);
		TwoFrame obj = new TwoFrame();
		back1.addActionListener(obj);
		f2.setVisible(true);
		
		
	}
	

}
