import java.io.*;
import java.util.*;

/**
 * i18n_pm to be documented :TODO:.
 *
 * @author Pavel Mavrin
 * @version $Id$
 */
public class gen3 implements Runnable {

    String inputFileName;
    String outputFileName;

    public gen3(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
    }

    private void solve() throws FileNotFoundException {        
        Scanner in = new Scanner(new File(inputFileName));
        PrintWriter out = new PrintWriter(outputFileName);

        Set<String> abbrSet = new HashSet<String>();
        List<String> words = new ArrayList<String>();

        while (in.hasNext()) {
            String s = in.next();
            words.add(s);
        }

        Random r = new Random(125345);
        List<String> abbrs = new ArrayList<String>(abbrSet);
        Collections.shuffle(words, r);
        Collections.shuffle(abbrs, r);

        Set<String> z = new HashSet<String>();

        int c = 0;
        int l = 0;
        while (true) {
            String word = words.get(r.nextInt(words.size()));
            if (word.length() <= 3 || !z.contains(word)) {
                z.add(word);
            } else {
                if (r.nextInt(10) == 0) {
                } else {
                    word = abbrivate(word);
                }
            }
            if (r.nextInt(3) == 0) {
                word = word.substring(0, 1).toUpperCase() + word.substring(1);
            } else if (r.nextInt(2) == 0) {
                word = word.toUpperCase();
            }

            if (c + word.length() >= 80) {
                out.println();
                c = 0;
                l++;
            }
            if (l >= 1000)
            	break; 
            out.print(" " + word);
            c += word.length() + 1;
        }

        in.close();
        out.close();
    }


    private String abbrivate(String s) {
        return "" + s.charAt(0) + (s.length() - 2) + s.charAt(s.length() - 1);
    }

    public void run() {
        try {
            solve();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    public static void main(String[] args) {
        new Thread(new gen3(args[0], args[1])).start();
    }
}
