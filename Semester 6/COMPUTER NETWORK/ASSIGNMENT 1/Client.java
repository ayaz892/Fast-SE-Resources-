package Client;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

public class Client extends JFrame implements ActionListener {

    // UI components
    private JTextArea chatBox;
    private JTextField messageBox;
    private JButton sendButton;
    private JButton connectButton;
    private JTextField ipBox;
    private JTextField portBox;

    // Networking components
    private Socket socket;
    private BufferedReader in;
    private PrintWriter out;

    public Client() {
        super("Client");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 400);
        setLayout(new BorderLayout());

        // Initialize chat box
        chatBox = new JTextArea();
        chatBox.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(chatBox);
        add(scrollPane, BorderLayout.CENTER);

        // Initialize message input panel
        JPanel inputPanel = new JPanel(new BorderLayout());
        messageBox = new JTextField();
        sendButton = new JButton("Send");
        sendButton.addActionListener(this);
        inputPanel.add(messageBox, BorderLayout.CENTER);
        inputPanel.add(sendButton, BorderLayout.EAST);
        add(inputPanel, BorderLayout.SOUTH);

        // Initialize connection input panel
        JPanel connectPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JLabel ipLabel = new JLabel("IP:");
        ipBox = new JTextField("127.0.0.1");
        JLabel portLabel = new JLabel("Port:");
        portBox = new JTextField("0000");
        connectButton = new JButton("Connect");
        connectButton.addActionListener(this);
        connectPanel.add(ipLabel);
        connectPanel.add(ipBox);
        connectPanel.add(portLabel);
        connectPanel.add(portBox);
        connectPanel.add(connectButton);
        add(connectPanel, BorderLayout.NORTH);
    }

    // ActionListener interface implementation
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == sendButton) {
            // User clicked "Send" button
            String message = messageBox.getText();
            chatBox.append("Client: " + message + "\n");
            out.println(message);
            out.flush();
            messageBox.setText("");
        } else if (e.getSource() == connectButton) {
            // User clicked "Connect" button
            try {
                String ip = ipBox.getText();
                int port = Integer.parseInt(portBox.getText());
                
                socket = new Socket(ip, port);
                
                in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
                out = new PrintWriter(socket.getOutputStream(), true);
                
                chatBox.append("Connected to server\n");
                new Thread(new MessageThread()).start();
            } catch (NumberFormatException ex) {
                JOptionPane.showMessageDialog(this, "Invalid port number");
            } catch (UnknownHostException ex) {
                JOptionPane.showMessageDialog(this, "Unknown host");
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(this, "Could not connect to server");
            }
        }
    }

    public static void main(String[] args) {
        Client client = new Client();
        client.setVisible(true);
    }

    // Thread for receiving messages from the server
    private class MessageThread implements Runnable {
        public void run() {
            try {
                while (true) {
                    String message = in.readLine();
                    if (message == null) {
                        break;
                    }
                    chatBox.append("Server: " + message + "\n");
                }
            } catch (IOException ex) {
                ex.printStackTrace();
            } finally {
                // Close networking resources
                try {
                    in.close();
                    out.close();
                    socket.close();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }
}
