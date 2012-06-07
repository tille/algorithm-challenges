import java.util.Scanner;


public class MARATON {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		
		int n= Integer.parseInt(s.nextLine());
		char m[][] = new char[n][n];
		
		for (int i = 0; i < n; i++) {
			String l = s.nextLine();
			m[i]= l.toCharArray();
			
		}
		
		
		boolean win = false;
		String res = "ongoing";
		
		
			
			for (int i = 0; i < m.length && win==false; i++) {
				for (int j = 0; j < m[0].length && win==false; j++) {
					
					if(m[i][j]!='.'){
						win = check_left(m,i,j);
						if(win==true){res=m[i][j]+"";break;}
						win = check_down(m,i,j);
						if(win==true){res=m[i][j]+"";break;}
						win = check_diag1(m,i,j);
						if(win==true){res=m[i][j]+"";break;}
						win = check_diag2(m,i,j);
						if(win==true){res=m[i][j]+"";break;}
					}
					
					
				}
				
			}
			
	//		System.out.println(win);
			
			System.out.println(res);
			
		

	}

	private static boolean check_diag2(char[][] m, int i, int j) {
		// TODO Auto-generated method stub
		int c = 1;
		if(adentro(m,i-1,j+1)&&m[i-1][j+1]==m[i][j]){
			c++;
		
			//System.out.println("c"+c+" "+m[i-1][j+1]);
		}
		if(adentro(m,i-2,j+2)&&m[i-2][j+2]==m[i][j])
			{c++;
			//System.out.println("c"+c+" "+m[i-2][j+2]);
			}

		
		if(c==3) return true;
		
		return false;
	}

	private static boolean check_diag1(char[][] m, int i, int j) {
		// TODO Auto-generated method stub
		int c = 1;
		if(adentro(m,i+1,j+1)&&m[i+1][j+1]==m[i][j])
			c++;
		if(adentro(m,i+2,j+2)&&m[i+2][j+2]==m[i][j])
			c++;
	
		
		if(c==3) return true;
		
		return false;
	}

	public static boolean check_down(char[][] m, int i, int j) {
		// TODO Auto-generated method stub
		int c = 1;
		if(adentro(m,i+1,j)&&m[i+1][j]==m[i][j])
			c++;
		
		if(adentro(m,i+2,j)&&m[i+2][j]==m[i][j])
			c++;
		
	
		
		
		if(c==3) return true;
		
		return false;
	}

	public static  boolean check_left(char[][] m, int i, int j) {
		// TODO Auto-generated method stub
		int c = 1;
		if(adentro(m,i,j+1))
				if(m[i][j+1]==m[i][j])
					c++;
		
		
		if(adentro(m,i,j+2))
				if(m[i][j+2]==m[i][j])
					c++;
	
		
		if(c==3) return true;
		
		return false;
	}
	
	public static boolean adentro(char[][] mat, int x, int y) {
		
		
		try {
			
			char w = mat[x][y];
			return true;
			
		} catch (Exception e) {
			// TODO: handle exception
			return false;
		}

			
		}
	
		
	
	

}
