/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication16;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Camilo
 */
public class JavaApplication16 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            BufferedReader br = null;
            String ln1 = "";
            br = new BufferedReader(new InputStreamReader(System.in));
            while (!br.readLine().equals("*")) {
                ln1 = br.readLine();
                if (!ln1.isEmpty()) {
                }
                StringTokenizer tokenizer = new StringTokenizer(ln1);
                ArrayList<Integer> nums = new ArrayList<Integer>(3);
                while (tokenizer.hasMoreElements()) {
                    nums.add(Integer.parseInt(tokenizer.nextToken()));
                    Collections.sort(nums);
                }
                ln1 = br.readLine();

                int i = 0;
                while (i < 3) {
                    char key = ln1.charAt(i);
                    if (key == 'A') {
                        System.out.print(nums.get(0));
                    } else {
                        if (key == 'B') {
                            System.out.print(nums.get(1));
                        } else {
                            System.out.print(nums.get(2));
                        }
                    }
                    if (i < 2) {
                        System.out.print(" ");
                    }
                    i++;
                }
                System.out.print("\n");
            }
        } catch (IOException ex) {
            Logger.getLogger(JavaApplication16.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
