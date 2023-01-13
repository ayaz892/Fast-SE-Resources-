package task1;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
public class Mouse extends JFrame implements MouseMotionListener {
	JLabel l;
	JPanel p;
	public Mouse()
	{
		
		 l=new JLabel();
		 p=new JPanel();
		 p.setLayout(null);
		 Dimension size=l.getPreferredSize();
		 l.setBounds(150,100,size.width,size.height);
		 p.add(l);
		 add(p);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		addMouseMotionListener(this);
		setBounds(10,10,500,500);
	
		
		
		
	}
	
	

	@Override
	public void mouseMoved(MouseEvent m) {
		int mouseX = m.getX();
		int mouseY = m.getY();
	    l.setBounds(mouseX, mouseY,80, 40);
		l.setText(mouseX + "  ,  "+ mouseY);
		
	}

	@Override
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	
}
