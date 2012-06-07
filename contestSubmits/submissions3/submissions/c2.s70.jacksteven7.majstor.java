import java.util.Scanner;


public class Majstor {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int r=Integer.parseInt(s.nextLine());
		char v[]=s.nextLine().toCharArray();
		char mat[][]=new char[50][50];
		int n=Integer.parseInt(s.nextLine());
		for (int i = 0; i < n; i++) {
			mat[i]=s.nextLine().toCharArray();
		}
		int res=0;

		for (int i = 0; i < n; i++) {
			res+=normal(v,mat[i],r);
		}
		System.out.println(res);
		System.out.println(optimo(v,mat,r,n));
		
	}

	private static int optimo(char[] v, char[][] mat, int r,int n) {
		int res=0,resmax=0;
		int R,S,P;	
			for (int i = 0; i < r; i++) {
				R=S=P=0;
				res=0;
				for (int j = 0; j <n; j++) {
					if(mat[j][i]=='R'){
						R++;
					}else if(mat[j][i]=='P'){
						P++;
					}else if(mat[j][i]=='S'){
						S++;
					}
						
				}
				res=Math.max(res,R+2*S);
				res=Math.max(res,S+2*P);
				res=Math.max(res,P+2*R);
				//System.out.println(res);
				resmax+=res;
			}
			
			return resmax;
	}

	private static int normal(char[] v, char[] c, int n) {
		int res=0;
		
		for (int i = 0; i <c.length; i++) {
			if(v[i]==c[i]){
				res=res+1;
			}else if((v[i]=='P'&&c[i]=='R')||(v[i]=='R'&&c[i]=='S')||(v[i]=='S'&&c[i]=='P')){
				res+=2;
			}
		}
		
		return res;
	}
//	for (int i = 0; i < n; i++) {
//	for (int j = 0; j < r; j++) {
//		System.out.print(mat[i][j]);
//	}
//	System.out.println();
//}

}

