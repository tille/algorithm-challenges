import java.util.Scanner;


public class Kemija {
	public static void main(String[] args) {
		Scanner s=new Scanner (System.in);
		String cad=s.nextLine();
		char c,ca,cd;
		for (int i = 0; i < cad.length(); i++) {
			try {
				//System.out.println("asda");
				c=cad.charAt(i);
				if(c=='p'){
					
					ca=cad.charAt(i-1);
					cd=cad.charAt(i+1);
					if(ca==cd&&(ca=='a'||ca=='e'||ca=='i'||ca=='o'||ca=='u')){
						cad=cad.substring(0,i)+cad.substring(i+2,cad.length());
					}
				}
				
			} catch (Exception e) {
				// TODO: handle exception
			}
			
		}
		System.out.println(cad);
	}
}
