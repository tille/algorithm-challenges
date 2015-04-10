import java.io.*;
import java.util.*;

/**
 * i18n_pm to be documented :TODO:.
 *
 * @author Pavel Mavrin
 * @version $Id$
 */
public class gen2 implements Runnable {

    String inputFileName;
    String outputFileName;

    public gen2(String inputFileName, String outputFileName) {
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
            if (s.length() > 3) {
            String ss = abbrivate(s);
            if (!abbrSet.contains(ss)) {
                abbrSet.add(ss);
                words.add(s);
            }
            }
        }

        Random r = new Random(125345);
        List<String> abbrs = new ArrayList<String>(abbrSet);
        Collections.shuffle(words, r);
        Collections.shuffle(abbrs, r);

        int c = 0;
        int l = 1;
        boolean cap = true;
        for (int i = 0; i < words.size(); i++) {
            String word = words.get(i);
            if (c + word.length() >= 80) {
                out.println();
                c = 0;
                l++;
            } else if (i > 0) {
                out.print(" ");
                c++;
            }
            if (cap) {
                word = word.substring(0, 1).toUpperCase() + word.substring(1);
                cap = false;
            }
            out.print(word);
            c += word.length();

            if (c < 80 && r.nextInt(20) == 0) {
                out.print(".");
                c++;
                cap = true;
            } else if (c < 80 && r.nextInt(20) == 0) {
                out.print(",");
                c++;
            }
        }

        while (l <= 1000) {
            String word = abbrs.get(r.nextInt(abbrs.size()));
            if (c + word.length() >= 80) {
                out.println();
                c = 0;
                l++;
            } else {
                out.print(" ");
                c++;
            }
            if (l == 1000) break;
            if (cap) {
                word = word.substring(0, 1).toUpperCase() + word.substring(1);
                cap = false;
            }
            out.print(word);
            c += word.length();

            if (c < 80 && r.nextInt(20) == 0) {
                out.print(".");
                c++;
                cap = true;
            } else if (c < 80 && r.nextInt(20) == 0) {
                out.print(",");
                c++;
            }
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
        new Thread(new gen2(args[0], args[1])).start();
    }
}
