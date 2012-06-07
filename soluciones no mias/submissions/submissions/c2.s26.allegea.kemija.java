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
public class Kemija {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        

        
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
         
         char[] letters = in.readLine().toCharArray();
         int n=letters.length;
         
         StringBuffer out = new StringBuffer();
         for(int i=0;i<n;i++){
             out.append(letters[i]);
             if(Character.isLetter(letters[i])){
                 if(i+1<n && letters[i+1]=='p' && i+2<n && letters[i+2]==letters[i])i+=2;
             }
         }
            System.out.print(out);
        in.close();
        System.exit(0);
        
    }
}
