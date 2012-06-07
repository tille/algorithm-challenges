import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;


public class GRANICA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		
		ArrayList<Integer> v = new ArrayList<Integer>();
		int max = 0;
		for (int i = 0; i < n; i++){
			int num = s.nextInt();
			v.add(num);
			max = Math.max(max, num);
		}
		
		ArrayList<Integer>res = new ArrayList<Integer>();
		int rem =0 ;
		for (int i = 2; i < Math.min(10000, max); i++) {
			boolean first = true;	
			boolean igual = true;
			for(Integer x : v){
				
				
				if(first){
					first=false;
					rem =x % (i);
					
				}
				if( x % i==rem){igual=true;}else{igual=false;}
				if(igual==false){break;}
				
			}
			if(igual)
				res.add(i);
			
		}
		String sol ="";
		for (Integer w : res) {
			sol+=" "+w;
			
		}
		System.out.println(sol.trim());
		
		

	}

}
