package Server;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
import javax.swing.*;

public class Server extends JFrame implements ActionListener {
    private JTextArea chatBox; // a text area to display the chat messages
    private JTextField messageBox; // a text field to enter the message to be sent
    private JButton sendButton; // a button to send the message
    private JLabel statusLabel; // a label to display the current status of the server
    private JButton startButton; // a button to start or stop listening for incoming connections
    private ServerSocket serverSocket; // a server socket to listen for incoming connections
    private Socket clientSocket; // a client socket to communicate with the connected client
    private BufferedReader in; // a buffered reader to read messages from the client
    private PrintWriter out; // a print writer to send messages to the client
    private boolean isListening = false; // a boolean to keep track of whether the server is listening for incoming connections

    public Server() {
        super("Server"); // set the title of the server window
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); // set the default close operation of the server window to exit the application
        setSize(400, 400); // set the size of the server window to 400x400 pixels
        setLayout(new BorderLayout()); // set the layout of the server window to border layout

        // create a new text area to display the chat messages
        chatBox = new JTextArea();
        chatBox.setEditable(false); // make the chat box read-only
        JScrollPane scrollPane = new JScrollPane(chatBox); // add a scroll pane to the chat box to allow scrolling
        add(scrollPane, BorderLayout.CENTER); // add the chat box to the center of the server window

        // create a new panel to hold the message box and send button
        JPanel inputPanel = new JPanel(new BorderLayout());
        messageBox = new JTextField(); // create a new text field to enter the message to be sent
        sendButton = new JButton("Send"); // create a new button to send the message
        sendButton.addActionListener(this); // add an action listener to the send button
        inputPanel.add(messageBox, BorderLayout.CENTER); // add the message box to the center of the input panel
        inputPanel.setSize(400, 200); // set the size of the input panel to 400x200 pixels
        inputPanel.add(sendButton, BorderLayout.EAST); // add the send button to the right of the message box
        add(inputPanel, BorderLayout.SOUTH); // add the input panel to the bottom of the server window

        // create a new panel to hold the status label and start button
        JPanel statusPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        statusLabel = new JLabel(""); // create a new label to display the current status of the server
        startButton = new JButton("Start Listening"); // create a new button to start or stop listening for incoming connections
        startButton.addActionListener(this); // add an action listener to the start button
        statusPanel.add(statusLabel); // add the status label to the left of the status panel
        statusPanel.add(startButton); // add the start button to the right of the status label
        add(statusPanel, BorderLayout.NORTH); // add the status panel to the top of the server window
    }

    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == sendButton) {
            // Get the message from the text field
            String message = messageBox.getText();
            // Append the message to the chat box with the "Server" prefix
            chatBox.append("Server: " + message + "\n");
            // Send the message to the client
            out.println(message);
            out.flush();
            // Clear the message box
            messageBox.setText("");
        } else if (e.getSource() == startButton) {
            if (!isListening) {
                try {
                    // Get the port number from the user
                    int port = Integer.parseInt(JOptionPane.showInputDialog("Port Number:"));
                    // Create a new server socket and start listening on the specified port
                    serverSocket = new ServerSocket(port);
                    statusLabel.setText("Listening on port " + port);
                    isListening = true;
                    startButton.setText("Stop listening");
                    // Start a new thread to handle client connections
                    new Thread(new ConnectionThread()).start();
                } catch (NumberFormatException ex) {
                    JOptionPane.showMessageDialog(this, "Invalid port number");
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(this, "Could not listen on port");
                }
            } else {
                // Stop listening for new connections and close the current connection
                try {
                    serverSocket.close();
                    clientSocket.close();
                    isListening = false;
                    startButton.setText("Start listening");
                    statusLabel.setText("Not listening");
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        // Create a new instance of the server
        Server server = new Server();
        // Make the server window visible
        server.setVisible(true);
    }

    private class ConnectionThread implements Runnable {
        public void run() {
            try {
                // Accept a new client connection
                clientSocket = serverSocket.accept();
                // Create input and output streams for the client connection
                
                in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
                out = new PrintWriter(clientSocket.getOutputStream(), true);
                statusLabel.setText("Connected to client");
                
                // Listen for messages from the client and display them in the chat box
                while (true) {
                    String message = in.readLine();
                    if (message == null) {
                        break;
                    }
                    chatBox.append("Client: " + message + "\n");
                }
            } catch (IOException ex) {
                if (isListening) {
                    ex.printStackTrace();
                }
            } finally {
                // Close the input and output streams and the client socket
                try {
                    in.close();
                    out.close();
                    clientSocket.close();
                    isListening = false;
                    startButton.setText("Start listening");
                    statusLabel.setText("Not listening");
                } catch (IOException ex) {
                    ex.printStackTrace();
                }
            }
        }
    }
}

