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
public class majstor {

    /**
     * @param args the command line arguments
     */
        public static void main(String[] args) throws IOException{
        

        
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
                
         int r=Integer.parseInt(in.readLine());
         char[] Sven = in.readLine().toCharArray();
         
         int n = Integer.parseInt(in.readLine());
         char[][] friends = new char[n][Sven.length];
         
         int[][] count = new int[r][3];
         
         int points = 0;
         
         for(int i=0;i<n;i++)
         {    friends[i] = in.readLine().toCharArray();
              for(int j=0;j<friends[0].length;j++)
              {   if(Sven[j]==friends[i][j]) points++;
                  else {
                      if(Sven[j]=='S' && friends[i][j] == 'P')points+=2;
                      if(Sven[j]=='P' && friends[i][j] == 'R')points+=2;
                      if(Sven[j]=='R' && friends[i][j] == 'S')points+=2;
                  }
                  
                  if(friends[i][j] == 'P')
                      count[j][0]++;
                  if(friends[i][j] == 'R')
                      count[j][1]++;
                  if(friends[i][j] == 'S')
                      count[j][2]++;
              
              }
         }
         
         int max = 0;
         int m = friends[0].length;
         
         
            for (int i = 0; i < m; i++) {

                max+=Math.max(Math.max(count[i][0]+count[i][1]*2,count[i][1]+count[i][2]*2),count[i][2]+count[i][0]*2);
                /*if (count[i][0] == count[i][1] && count[i][1] == count[i][2]) {
                    max += (m * 2 + m);
                } else {
                    if (count[i][0] > count[i][1] && count[i][0] > count[i][2]) {
                        max += count[i][0] * 2 + count[i][2];
                    } else if (count[i][1] > count[i][2] && count[i][1] > count[i][0]) {
                        max += count[i][1] * 2 + count[i][0];
                    } else if (count[i][2] > count[i][0] && count[i][2] > count[i][1]) {
                        max += count[i][2] * 2 + count[i][1];
                    } else if (count[i][0] == count[i][1]) {
                        if (count[i][0] > count[i][2]) {

                            max += count[i][0] * 2 + count[i][0];
                        } else {
                            max += count[i][2] * 2 + count[i][1];
                        }
                    } else if (count[i][2] == count[i][1]) {
                        if (count[i][2] > count[i][0]) {

                            max += count[i][2] * 2 + count[i][2];
                        } else {
                            max += count[i][0] * 2 + count[i][2];
                        }
                    } else if (count[i][0] == count[i][2]) {
                        if (count[i][0] > count[i][1]) {

                            max += count[i][0] * 2 + count[i][0];
                        } else {
                            max += count[i][1] * 2 + count[i][0];
                        }
                    }

                }*/


            }
         

           System.out.println(points+"\n"+max);
           
        in.close();
        System.exit(0);
        
    }
}
