import java.util.Scanner;


public class MAGIJA {

  /**
   * @param args
   */
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		String v[]=s.nextLine().split("\\s+");
		int r=Integer.parseInt(v[0]),c=Integer.parseInt(v[1]),a,b;
		String mat[][]=new String[r*2][c*2],cad;
		for (int i = 0; i < r; i++) {
			cad=s.nextLine();
			for (int j = 0; j < c; j++) {
			//.out.println(i+" "+j);
				mat[i][j]=cad.substring(j, j+1);
				mat[r*2-1-i][j]=cad.substring(j, j+1);
				mat[i][c*2-1-j]=cad.substring(j, j+1);
				mat[r*2-1-i][c*2-1-j]=cad.substring(j, j+1);
				
			}
		}
		a=s.nextInt()-1;b=s.nextInt()-1;
		if(mat[a][b].equals(".")){
		//	System.out.println("si");
			mat[a][b]="#";
			//System.out.println("-->"+mat[a][b]);
		}else {
			mat[a][b]=".";
			//System.out.println("si");
		}
		
		for (int i = 0; i < r*2; i++) {
			for (int j = 0; j < c*2; j++) {
				System.out.print(mat[i][j]+"");
			}
			System.out.println();
		}
	}
}
