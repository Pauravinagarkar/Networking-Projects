// client

import java.io.*;
import java.net.*;
public  class NetClient 
{ 
     public static void main(String args[]) throws IOException
     {
             InetAddress address=InetAddress.getLocalHost(); //this class represents an IP address using the method getLocalHost,           getByName, or getAllByName to create a new InetAddress instance
    Socket s1=null;
    String line=" ";								
    String liner=null;
    BufferedReader br=null;
    BufferedReader br1=null;
    DataOutputStream dos=null;
    DataInputStream dis=null;	
    
    try {
        s1=new Socket("Localhost", 4445); 
        br= new BufferedReader(new InputStreamReader(System.in));
        br1=new BufferedReader(new InputStreamReader(s1.getInputStream()));
        dos= new DataOutputStream(s1.getOutputStream());
        dis= new DataInputStream(s1.getInputStream());
    }
   catch (IOException e){
        e.printStackTrace();
        System.err.print("IO Exception");
    }

    
    System.out.println("Enter Data to echo Server ( Enter QUIT to end):");
    System.out.println("Client Address : "+address);
    String response="";
    try{
        while(!line.equals("stop"))
	{
                line=br.readLine();	  
                dos.writeUTF(line);  
		dos.flush();
       		liner=""; 
       		liner=dis.readUTF();  
		System.out.println("Server says: "+liner); 
		dos.flush();  
 
		System.out.println("Enter Data to echo Server ( Enter QUIT to end):");
        }
    }
    catch(IOException e){
        e.printStackTrace();
    System.out.println("Socket read Error");
    }
    finally
    {
        br1.close();
	dos.close();
	br.close();
	s1.close();
        System.out.println("Connection Closed");
    }
}
}