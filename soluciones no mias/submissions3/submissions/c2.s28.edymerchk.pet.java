import java.util.Scanner;


public class PET {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);
		 int max =0; int w = 0;
		for (int i = 0; i < 5; i++) {
			int ac = s.nextInt()+s.nextInt()+s.nextInt()+s.nextInt();
			max = Math.max(ac, max);
			if(ac==max){
				w=i;
			}
			
				
		}
		System.out.println((w+1)+" "+max);

	}

}
