import java.util.*;

public class granica_wa {
    int n;
    int a[];

    boolean ok( int M ) {
       int ostatak = a[0]%M;
       for( int i = 1; i < n; ++i )
          if( a[i]%M != ostatak )
            return false;
       return true;
    }
    
    public void run() {
        Scanner cin = new Scanner(System.in);
        n = cin.nextInt();
        a = new int[100];
        
        for( int i = 0; i < n; ++i ) a[i] = cin.nextInt();

        int razlika = a[0]-a[1];
        if( razlika < 0 ) razlika = -razlika;

        for( int d = 1; d*d <= razlika; ++d ) {
           if( razlika % d != 0 ) continue;

           int M1 = d, M2 = razlika/d;

           if( ok( M1 ) && M1 != 1  ) System.out.printf( "%d ", M1 + 1 );
           if( ok( M2 ) && M2 != M1 ) System.out.printf( "%d ", M2 );
        }
        System.out.printf( "\n" );
    }

    public static void main(String[] args) {
        (new granica_wa()).run();
    }
}