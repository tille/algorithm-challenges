/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

//package Dic5;
import java.io.*;




/**
 *
 * @author allegea
 */
public class NOP {

    /**
     * @param args the command line arguments
     */
        public static void main(String[] args) throws IOException{
        

        
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
         
         char[] letters = in.readLine().toCharArray();
         int n=letters.length;
         
         int count = 0;
         int miss = 1;
         for(int i=0;i<n;i++){
             
             if(Character.isUpperCase(letters[i])){
                 i++;
                 while(i<n && Character.isLowerCase(letters[i])){
                     i++;
                     miss++;
                     
                 }
             }
            
             if(i!=n)
             {  
                 if(miss%4!=0)
                 count+=Math.abs(((miss)%4)-4);
                miss=1;
              i--;}
             
         }
         
           System.out.println(count);
           
        in.close();
        System.exit(0);
        
    }
}
