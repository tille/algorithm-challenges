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
				//System.out.println("Espera "+(r-res%(r+g)));
				res=res+(r-res%(r+g));
			}else{
			//	System.out.println("Green");
			}
			//System.out.println("res1 "+res);
		}
		//System.out.println("res2 "+res);
		res=res+l-d;
		System.out.println(res);
	}

	private static boolean green(int aux, int r, int g) {
		if(aux<r)
			return false;
		else{
			while (true) {

			//	System.out.println("aux1 "+aux);
				aux=aux-r;
			//	System.out.println("aux2 "+aux);
				if(aux<g){
			//		System.out.println("Si es verde");
					return true;
				}
			//	System.out.println("aux3 "+aux);
				aux=aux-g;
			//	System.out.println("aux4 "+aux);
				if(aux<r){
			//		System.out.println("aux5 "+aux);	
					return false;
				}
				
			}
			
		}
		
		
	}

}