import java.util.*;
import java.io.*;
import java.math.*;

// remember change the name to Main in spoj
public class JULKA {
	public static void main(String[] args) throws IOException {
          Scanner in = new Scanner(System.in);
		
          String k,n;
          
          for( int i = 0; i < 10; ++i ){
            k = in.next();
            BigInteger K = new BigInteger(k);
            n = in.next();
            BigInteger N = new BigInteger(n);
            BigInteger natalia = K.subtract(N).divide(new BigInteger("2"));
            BigInteger klaudia = natalia.add(N);
            System.out.println(klaudia);
            System.out.println(natalia);
          }
          
          in.close();
          System.exit(0);
	}
}

