import java.io.*;
import java.net.*;

public class server
{
    public static void main(String[] args) throws Exception
    {
        ServerSocket ss = new ServerSocket(5000);
        System.out.println("Server is waiting for client...");

        Socket s = ss.accept();
        System.out.println("Client connected....");

        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());

        String str = dis.readUTF();

        int length = str.length();
        String upper = str.toUpperCase();

        String result = "Length :- " + length  + "UpperCase :- " + upper;

        dos.writeUTF(result);

        dos.close();
        dis.close();
        s.close();
        ss.close();
    }
}