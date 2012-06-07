import java.util.Scanner;


public class A {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int aux=0,res=0,l=0,lres=0;
		for (int i = 0; i < 5; i++) {
			aux=0;l=i+1;
			for (int j = 0; j < 4; j++) {
				aux+=s.nextInt();
				
			}
			if(aux>res){
				res=aux;
				lres=l;
			}
		}
		System.out.println(lres+" "+res);
	}
}
