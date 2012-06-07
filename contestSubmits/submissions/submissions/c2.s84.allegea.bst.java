/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

//package Dic5;
import java.io.*;
import java.util.*;





/**
 *
 * @author allegea
 */
public class BST {
    
   /* public static class nodo{
        
        nodo der = null;
        nodo izq = null;
        int number=-1;
        
        nodo(int x){
            number = x;
        }
    }
    public static  class tree{
        
        nodo raiz;
        int n;
        long count;
        
        tree(){
            n = -1;
            raiz=null;
            count = 0;
        }
        
        void insert(int x, nodo y){
            count++;
            if(y.number>x)
                if(y.izq==null) {
                    y.izq = new nodo(x);
                    System.out.println(count);
                }
                else insert(x,y.izq);
            else
                if(y.der==null) {
                    y.der = new nodo(x);
                    System.out.println(count);
                }
                else insert(x,y.der);
                    
                
            
            
        }
        
    }


    public static void main(String[] args) throws IOException{
        

        
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
         
         tree prueba = new tree();
         
         int cases = Integer.parseInt(in.readLine());
         
         prueba.raiz= new nodo(Integer.parseInt(in.readLine()));
         System.out.println(prueba.count);
         
         for(int i=1;i<cases;i++){
             prueba.insert(Integer.parseInt(in.readLine()), prueba.raiz);
             
         }
         
         /*for(int i=1;i<=300000;i++)
        System.out.println(i);*/
    
     public static void main(String[] args) throws IOException{
        
       
         BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

         SortedMap<Integer,Integer> numbers = new TreeMap<Integer,Integer>();
         SortedMap<Integer,Integer> upper;
         SortedMap<Integer,Integer> lower;
         int n= Integer.parseInt(in.readLine());
         
         int count = 0;
         
         for(int i = 0; i<n;i++){
             int x = Integer.parseInt(in.readLine());
             upper = numbers.headMap(x);
             lower = numbers.tailMap(x);
             int posU=-1;
             int posL=-1;
             if(!upper.isEmpty()) posU = upper.get(upper.lastKey()); 
             if(!lower.isEmpty()) posL = lower.get(lower.firstKey());
             
             int max = Math.max(posU, posL);
              numbers.put(x, max+1);
              count+=max+1;
              System.out.println(count);
             
         }

        in.close();
        System.exit(0);
        
        
        
    }
}
