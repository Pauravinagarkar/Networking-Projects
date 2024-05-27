import java.net.*;
import java.io.*;
import java.util.Scanner;
public class SimpleClient1
{
     public static void main (String []args) throws Exception
     {  String s1,s2;
	    s2="  ";
    	Socket ss = new Socket("Localhost",1226);

	    DataOutputStream dos=new DataOutputStream(ss.getOutputStream());
    	DataInputStream dis=new DataInputStream(ss.getInputStream());

        Scanner sc=new Scanner(System.in);
        while(!s2.equals("Bye"))
        {       
	     	s2=sc.nextLine();         //read data
		    dos.writeUTF(s2);         //send message to server

		    s1=dis.readUTF();         //read message from server
	      	System.out.println("Server says   : "+s1);
        }
        dos.close();
	    ss.close();
     }
}
