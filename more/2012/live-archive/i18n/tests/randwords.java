import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.TreeSet;
import java.util.Random;

public class randwords {
	public static void main(String[] args) throws IOException {
		int n = Integer.parseInt(args[0]);
		Random r = new Random(n);
		TreeSet<String> words = new TreeSet<String>();
		while (words.size() < n) {
			int len = r.nextInt(32) + 1;
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < len; i++) {
				sb.append((char)('a' + r.nextInt(26)));
			}
			words.add(sb.toString());
		}

		PrintWriter out = new PrintWriter(new FileWriter(args[1]));
		for (String w : words)
			out.println(w);
		out.close();
	}
}