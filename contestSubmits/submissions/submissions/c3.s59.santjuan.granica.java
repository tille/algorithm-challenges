import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.StringTokenizer;


public class Granica 
{
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		
		public Scanner()
		{
	    	System.setOut(new PrintStream(new BufferedOutputStream(System.out), true));
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next()
		{
			while(st == null || !st.hasMoreTokens())
			{
				try { st = new StringTokenizer(br.readLine()); }
				catch(Exception e) { throw new RuntimeException(); }
			}
			return st.nextToken();
		}

		public int nextInt()
		{
			return Integer.parseInt(next());
		}
		
		public double nextDouble()
		{
			return Double.parseDouble(next());
		}
		
		public String nextLine()
		{
			st = null;
			try { return br.readLine(); }
			catch(Exception e) { throw new RuntimeException(); }
		}
		
		public boolean endLine()
		{
			try 
			{
				String next = br.readLine();
				while(next != null && next.trim().isEmpty())
					next = br.readLine();
				if(next == null)
					return true;
				st = new StringTokenizer(next);
				return !st.hasMoreTokens();
			}
			catch(Exception e) { throw new RuntimeException(); }
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int[] numeros = new int[n];
		for(int i = 0; i < n; i++)
			numeros[i] = sc.nextInt();
		boolean empezo = false;
		for(int i = 2; i <= 1000000; i++)
		{
			int mod = numeros[0] % i;
			boolean si = true;
			for(int j = 0; j < n; j++)
				if(numeros[j] % i != mod)
					si = false;
			if(si)
				if(empezo)
					System.out.print(" " + i);
				else
				{
					empezo = true;
					System.out.print(i);
				}
		}
		for(int i = 0; i < n; i++)
		{
			if(numeros[i] == 1)
				continue;
			int mod = numeros[0] % numeros[i];
			boolean si = true;
			for(int j = 0; j < n; j++)
				if(numeros[j] % numeros[i] != mod)
					si = false;
			if(si)
				if(empezo)
					System.out.print(" " + numeros[i]);
				else
				{
					empezo = true;
					System.out.print(numeros[i]);
				}
		}
		System.out.println();
	}
}
