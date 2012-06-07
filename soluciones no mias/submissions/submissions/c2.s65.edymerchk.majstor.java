import java.util.Arrays;
import java.util.Scanner;


public class MAJSTOR {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
	
		String x = s.nextLine();
		char v [] = s.nextLine().toCharArray();
		int n = Integer.parseInt(s.nextLine());
		char m[][]= new char [n][v.length];
		for (int i = 0; i < n; i++) 
			m[i]= s.nextLine().toCharArray();
		
		int max =0;
		for (int i = 0; i < m.length; i++) {
			int c = evaln(v,m[i]);
			max =c + max;
		}
		System.out.println(max);
		
		//optimo
		
		int opt = 0;
		
			
			char w[]=formar(m);
			int acum =0;
			//System.out.print(Arrays.toString(w));
			
			for (int j = 0; j < m.length; j++) {
				int c = evaln(w,m[j]);
				
				acum= acum+c;
				
			}
		//	System.out.println(" = "+acum);
		
//			opt = Math.max(acum, opt);
		
		System.out.println(acum);
		
		
		
			
		
		

	}

	private static char[] formar(char[][] m) {
		char res [] = new char [m[0].length];
		
		
		for (int i = 0; i < m[0].length; i++) {
			int s=0;int r=0;int p=0;
			char act [] = new char [m[0].length];
			for (int j = 0; j < m.length; j++) {
				act[j]=m[j][i];
				
				if(m[j][i]=='S')
					r++;
				else
					if(m[j][i]=='P')
						s++;
					else
						if(m[j][i]=='R')
							p++;
						
				
			}
			
			int vc [] = new int[3];
			
			
			int cr=0 ;int cs=0; int cp=0;
			int max = 0;
			for (int j = 0; j < act.length; j++) {
				char temp [] = new char [act.length];
				Arrays.fill(temp, 'R');
				cr = evaln(temp, act);
				Arrays.fill(temp, 'S');
				cs = evaln(temp, act);
				Arrays.fill(temp, 'P');
				cp = evaln(temp, act);
					
			}
			vc [0]=cr;
			vc [1]=cp;
			vc [2]=cs;
			
			Arrays.sort(vc);
			
			if(vc[2]==cr)
				res[i]='R';
			else
			if(vc[2]==cp)
				res[i]='P';
			else
			if(vc[2]==cs)
				res[i]='S';
			
			
		}
		
		
		
		return res;
	}

	private static int evaln(char[] v, char[] m) {
		
		int t =0;
		for (int i = 0; i < m.length; i++) {
			if(v[i]==m[i])
				t=t+1;
			else
			if(v[i]=='P'&&m[i]=='R')
				t=t+2;
			else
			if(v[i]=='S'&&m[i]=='P')
				t=t+2;
			else
				if(v[i]=='R'&&m[i]=='S')
					t=t+2;
		
				
			
		}
		return t;
	}
	


}
