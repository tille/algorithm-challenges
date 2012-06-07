import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class E 
{
	static class Scanner
	{
		BufferedReader br;
		StringTokenizer st;
		
		public Scanner()
		{
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
	
	static boolean collinear(long x1, long y1, long x2, long y2, long x3, long y3) 
	{
		  return (y1 - y2) * (x1 - x3) == (y1 - y3) * (x1 - x2);
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		int n = sc.nextInt();
		long[][] puntos = new long[n][2];
		for(int i = 0; i < n; i++)
		{
			puntos[i][0] = sc.nextInt();
			puntos[i][1] = sc.nextInt();
		}
		int cuenta = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				for(int k = j + 1; k < n; k++)
				{
					long[] a = puntos[i];
					long[] b = puntos[j];
					long[] c = puntos[k];
					if(collinear(a[0], a[1], b[0], b[1], c[0], c[1]))
						continue;
					long side1 = (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
					long side2 = (a[0] - c[0]) * (a[0] - c[0]) + (a[1] - c[1]) * (a[1] - c[1]);
					long side3 = (b[0] - c[0]) * (b[0] - c[0]) + (b[1] - c[1]) * (b[1] - c[1]);
					if(((side1) == ((side2) + (side3))) || ((side2) == ((side1) + (side3))) || ((side3) == ((side1) + (side2))))
						 cuenta++;
				}
		System.out.println(cuenta);
	}
}
