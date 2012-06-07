import java.util.Scanner;


public class KEMIJA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner s = new Scanner(System.in);
		
		String l = s.nextLine();
		
		for (int i = 0; i < l.length(); i++) {
			
			try {
				
				char w = l.charAt(i);
				char wa = l.charAt(i-1);
				char wd = l.charAt(i+1);
				if(w=='p'&&wa==wd&&(wa=='a'||wa=='e'||wa=='i'||wa=='o'||wa=='u')){
					l = l.substring(0,i) + l.substring(i+2,l.length());
				}
				
				
			} catch (Exception e) {
				// TODO: handle exception
				
			}
			
			
		}
		
		System.out.println(l);

	}

}
