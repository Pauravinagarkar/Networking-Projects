import java.net.*;
import java.io.*;
import java.nio.charset.*;
 public class c_Datagram
{
     public static void main(String args[]) throws Exception 
	{
		DatagramSocket s=new DatagramSocket(2000);
		InetAddress myaddress =InetAddress.getLocalHost();	
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in)); 
		byte[] buffer=new byte[20]; 
		String str1=" ", str2=" ";
		while(!str2.equals("Bye"))
		{
		//System.out.println("Enter the Message to the Server:");
		str1= br.readLine();
		buffer=str1.getBytes();
		DatagramPacket packet=new DatagramPacket(buffer,buffer.length,myaddress,3000);
		s.send(packet);

		byte[] buffer1=new byte[20];
		DatagramPacket packet1=new DatagramPacket(buffer1,buffer1.length);
		s.receive(packet1);
		buffer1=packet1.getData();
		str2= new String(buffer1,StandardCharsets.UTF_8);
		System.out.println("Server Says:-"+str2);
		}		
	}
}