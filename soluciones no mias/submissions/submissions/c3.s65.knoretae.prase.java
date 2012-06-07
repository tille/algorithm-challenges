import java.io.InputStreamReader;
import java.io.IOException;

import java.util.Scanner;
import java.util.Hashtable;

class PRASE{

	public static void main(String args[]){
	
	PRASE instance = new PRASE();
	
	Scanner scanner = new Scanner(System.in);
	int n=scanner.nextInt();
	
	Hashtable hashTable = new Hashtable();
	
	String name = "";
	Integer value = 0;
	Integer overall = 0;
	Integer warnings = 0;
	
	scanner.nextLine();
	
	for(int i=0;i<n;i++){
		name = scanner.nextLine();
		System.out.println("Leí: "+name);
		if(hashTable.containsKey(name)){
			value = (Integer)hashTable.get(name);
			
			if(value>overall-value)
				warnings++;
			
			hashTable.put(name, value+1);
		}
		else{
			value=1;
			hashTable.put(name, value);
		}
		overall++;
	}
	System.out.println(warnings);
	}
}

