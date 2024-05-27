import java.net.*;
import java.io.*;
import java.nio.charset.*;
 public class s_Datagram
{
     public static void main(String args[]) throws Exception 
	{
		DatagramSocket ss=new DatagramSocket(3000);
		InetAddress myaddress =InetAddress.getLocalHost();	
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in)); 
		String str1=" ", str2=" ";
		while(!str1.equals("Bye"))
		{
		byte[] buffer=new byte[20]; 
		DatagramPacket packet1=new DatagramPacket(buffer,buffer.length);
		ss.receive(packet1);
		int port=packet1.getPort();
		buffer=packet1.getData();
		str2= new String(buffer,StandardCharsets.UTF_8);
		System.out.println("Client Says:-"+str2);
	
		byte[] buffer1 = new byte[20];
		str1= br.readLine();
		buffer1=str1.getBytes();
		DatagramPacket packet=new DatagramPacket(buffer1,buffer1.length,myaddress,port);
		ss.send(packet);
		}

	}
}

//client
