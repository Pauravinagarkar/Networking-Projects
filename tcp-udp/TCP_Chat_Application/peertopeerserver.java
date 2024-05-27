import java.net.*;
import java.io.*;
import java.util.Scanner;
public class SimpleServer1
{
     public static void main (String []args) throws Exception
     {  String s1,s2;
    	s1=" ";
 
        ServerSocket ss= new ServerSocket(1226);
	    Socket s=ss.accept();

	    DataOutputStream dos=new DataOutputStream(s.getOutputStream());
	    DataInputStream dis=new DataInputStream(s.getInputStream());
	
        Scanner sc=new Scanner(System.in);
        while(!s1.equals("Bye"))
	    {
			s1=dis.readUTF();                        //recieve data from client
		  	System.out.println("Client says : "+s1); //print message
			   
			s2=sc.nextLine();                        //read message 
			dos.writeUTF(s2);                        //send data to client
	    } 
        dos.close();
    	s.close();
	ss.close(); 
     }
}

//client

