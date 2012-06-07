import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		
		int n,a=s.nextInt(),b=s.nextInt(),c=s.nextInt();
		int v[]=new int[101],ini,fin,inim=Integer.MAX_VALUE,maxm=Integer.MIN_VALUE;
		for (int i = 0; i < 3; i++) {
			ini=s.nextInt();fin=s.nextInt()-1;
			inim=Math.min(inim, ini);
			maxm=Math.max(maxm, fin);
			for (int j =ini ; j <= fin; j++) {
				v[j]=v[j]+1;
			}
		}
		int res=0;
	//	System.out.println(inim+" "+maxm);
		for (int i = inim ; i <=maxm; i++) {
			//System.out.print(v[i]+" ");
			if(v[i]==1){
				res=res+a;
			}else if(v[i]==2){
				res=res+2*b;
			}else if(v[i]==3){
				res=res+3*c;
			}
				
		}
		//System.out.println();
		System.out.println(res);
			
		
	}
}
