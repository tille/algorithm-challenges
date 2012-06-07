import java.util.*;
import java.io.*;

public class Granica {
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(in.readLine());
		int[] numbers = new int[N];
		
		int max = 0;
		for (int i = 0; i < N; ++i) {
			numbers[i] = Integer.parseInt(in.readLine());
			max = Math.max(max, numbers[i]);
		}
		
		List<Integer> M = new ArrayList<Integer>();
		for (int m = 2; m * m <= max; ++m) {
			int mod = numbers[0] % m;
			boolean ok = true;
			for (int j = 1; j < N && ok; ++j)
				if (numbers[j] % m != mod)
					ok = false;
			if (ok)
				M.add(m);
		}
		System.out.print(M.get(0));
		for (int i = 1; i < M.size(); ++i)
			System.out.print(" " + M.get(i));
		
		in.close();
		System.exit(0);
	}
}
