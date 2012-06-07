import java.util.Scanner;


public class NOP {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		String cad = s.nextLine();
		int c =0;
		int x = 0;
		for (int i = 0; i < cad.length(); i++) {
			
			
			char w = cad.charAt(i);
			if(w>=65 && w <=90)
				
				while (!(i%4==0)) {
					
					cad = cad.substring(0,i)+'*'+cad.substring(i,cad.length());
					i++;
					c++;
				}
			
		}
		
		System.out.println(c);
		

	}

}
