import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
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
	
	static int[] factores = new int[100];
	static int[] nveces = new int[100];
	static int nFactores;
	static ArrayList <Integer> posibles = new ArrayList <Integer> ();
	
	private static void generar(int i, int acum) 
	{
		if(i == nFactores)
		{
			if(acum == 1)
				return;
			posibles.add(acum);
		}
		else
		{
			int cuenta = 1;
			for(int j = 0; j <= nveces[i]; j++)
			{
				generar(i + 1, cuenta * acum);
				cuenta *= factores[i];
			}
		}
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		int[] numeros = new int[n];
		for(int i = 0; i < n; i++)
			numeros[i] = sc.nextInt();
		int sumatoria = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				sumatoria = Math.min(sumatoria, Math.abs(numeros[i] - numeros[j]));
		int raiz = (int) (Math.sqrt(sumatoria) + 10);
		for(int i = 2; sumatoria != 1 && i <= raiz; i++)
		{
			int cuenta = 0;
			while(sumatoria % i == 0)
			{
				cuenta++;
				sumatoria /= i;
				raiz = (int) (Math.sqrt(sumatoria) + 10);
			}
			if(cuenta > 0)
			{
				factores[nFactores] = i;
				nveces[nFactores++] = cuenta;
			}
		}
		if(sumatoria != 1)
		{
			factores[nFactores] = sumatoria;
			nveces[nFactores++] = 1;
		}
		generar(0, 1);
		boolean empezo = false;
		for(int i : posibles)
		{
			int mod = numeros[0] % i;
			boolean bien = true;
			for(int j : numeros)
				if(j % i != mod)
					bien = false;
			if(bien)
			{
				if(empezo)
					System.out.print(" " + i);
				else
				{
					empezo = true;
					System.out.print(i);
				}
			}
		}
		System.out.println();
	}
}
