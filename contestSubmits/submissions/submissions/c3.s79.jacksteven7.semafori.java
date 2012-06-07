import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),l=s.nextInt(),ac=0,d=0,r,g,res=0,aux;
		for (int i = 0; i < n; i++) {
			d=s.nextInt();
			r=s.nextInt();
			g=s.nextInt();
			res=res+d-ac;
			aux=res;
			ac=d;
			if(!green(aux,r,g)){
				res=res+(r-res%(r+g));
			}
			//System.out.println("res "+res);
		}
		res=res+l-d;
		System.out.println(res);
	}

	private static boolean green(int aux, int r, int g) {
		if(aux<=r)
			return false;
		else{
			while (true) {
				aux=aux-r;
				if(aux<=g){
					return true;
				}
				aux=aux-g;
				if(aux<=r){
					return false;
				}
				
			}
			
		}
		
		
	}

}
