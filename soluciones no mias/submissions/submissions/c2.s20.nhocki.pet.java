import java.util.*;
import java.io.*;

public class Maraton {
  public static void main(String[] args) throws IOException {
    BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    int max_score = 0, winner = 0;
    
    for(int i=1; i<=5; ++i){
      int sum = 0;
      Scanner src = new Scanner(in.readLine());
      int x;
      for(int j = 0; j<4; ++j){
        x = src.nextInt();
        sum += x;
      }
      if( sum > max_score){
        max_score = sum;
        winner = i;
      }
    }
    
    System.out.println(winner + " " + max_score);
    in.close();
    System.exit(0);
  }
}