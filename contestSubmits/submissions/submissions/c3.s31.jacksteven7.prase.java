import java.util.Arrays;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt(),res=0;
		String cad="",str;
		for (int i = 0; i < n; i++) {
			str=s.next();
			if(!cad.equals(str)){
				cad=str;
				res++;
			}
		}
		System.out.println(res/2);
		
			
		
	}
}
