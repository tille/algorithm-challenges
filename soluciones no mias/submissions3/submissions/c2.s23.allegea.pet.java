/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.util.StringTokenizer;



/**
 *
 * @author allegea
 */
public class Plantilla {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        

        
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
         

           int sum=0;
           int j=-1;
           for(int i=0;i<5;i++)
           {
               int sumP = 0;
               StringTokenizer leer = new StringTokenizer(in.readLine());
               while(leer.hasMoreTokens())
                   sumP+=Integer.parseInt(leer.nextToken());
               if(sumP>sum){
                   sum=sumP;
                   j=i;
               }
               
           }
            System.out.print((j+1)+" "+sum);
        in.close();
        System.exit(0);
        
    }
}
