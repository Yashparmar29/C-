import java.io.*;
import java.util.*;
import java.net.*;

public class client 
{
    public static void main(String[] args) throws Exception
    {
        Socket s = new Socket("localhost",5000);

        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter String :- ");
        String data = sc.next();

        dos.writeUTF(data);

        String response = dis.readUTF();
        System.out.println("server send answer :- ");

        System.out.println(response);

        dos.close();
        dis.close();
        s.close();
    }    
}
