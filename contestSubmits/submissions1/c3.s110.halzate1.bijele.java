/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Camilo
 */
public class Bijele{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int[] correctValues = {1, 1, 2, 2, 2, 8};
        try {
            BufferedReader br = null;
            String ln1 = "";
            br = new BufferedReader(new InputStreamReader(System.in));
            ln1 = br.readLine();
            StringTokenizer tokenizer = new StringTokenizer(ln1);
            ArrayList<Integer> nums = new ArrayList<Integer>(3);
            while (tokenizer.hasMoreElements()) {
                nums.add(Integer.parseInt(tokenizer.nextToken()));
            }
            
            for (int i = 0; i < nums.size(); i++) {
                nums.set(i, correctValues[i]-nums.get(i));
                System.out.print(nums.get(i));
                if(i < correctValues.length - 1){
                    System.out.print(" ");
                }
            }
            System.out.println();
          
        } catch (IOException ex) {
            Logger.getLogger(Bijele.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
