import java.util.HashMap;
import java.util.Scanner;


public class PRASE {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		int n= Integer.parseInt(s.nextLine());
	
		int total=0; int res =0;
		HashMap<String, Integer> h = new HashMap();
		for (int i = 0; i < n; i++) {
			
			String child = s.nextLine();
			total++;
			
			if(!h.containsKey(child)){
				h.put(child, 1);
			}else{
				h.put(child, h.get(child)+1);
			}
			
		//	System.out.println("child"+h.get(child));
			if(h.get(child)-1>total-h.get(child)){
				
				res++;
			}
			
			
		}
	//	System.out.println(h);
		
	//	System.out.println("total"+total);
		
		System.out.println(res);
	}

}
