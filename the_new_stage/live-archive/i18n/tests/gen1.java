import java.io.*;
import java.util.Scanner;
import java.util.Map;
import java.util.HashMap;

/**
 * i18n_pm to be documented :TODO:.
 *
 * @author Pavel Mavrin
 * @version $Id$
 */
public class gen1 implements Runnable {

    Map<String, String> abbrs = new HashMap<String, String>();
    Map<String, String> ext = new HashMap<String, String>();

    String inputFileName;
    String outputFileName;

    public gen1(String inputFileName, String outputFileName) {
        this.inputFileName = inputFileName;
        this.outputFileName = outputFileName;
    }

    private void solve() throws FileNotFoundException {
        Scanner in = new Scanner(new File(inputFileName));
        PrintWriter out = new PrintWriter(outputFileName);
        while (in.hasNextLine()) {
            String line = in.nextLine();
            int c = 0;
            int wc = 0;
            StringBuilder sb = new StringBuilder();
            while (line.length() > 0) {
                int i = 0;
                while (i < line.length() && isWordPart(line.charAt(i))) i++;
                if (i == 0) {
                    if (c + 1 > 80) {
                        if (wc > 0)
	                    out.println(rtrim(sb));
                        sb.setLength(0);
                        c = 0;
                        wc = 0;
                    }
                    c++;
                    if (" .,-\"():;!?".indexOf(line.charAt(0)) >= 0) {
                        sb.append(line.charAt(0));
                    } else {
                        sb.append(' ');
                    }
                    line = line.substring(1);
                } else {
                    String s = getWord(line.substring(0, i));
                    if (c + s.length() >= 80) {
                        if (wc > 0)
	                    out.println(rtrim(sb));
                        sb.setLength(0);
                        c = 0;
                        wc = 0;
                    }
                    c += s.length();
                    wc++;
                    sb.append(s);
                    line = line.substring(i);
                }
            }
            if (wc > 0)
            	out.println(rtrim(sb));
        }
        in.close();
        out.close();
    }

    private static String rtrim(StringBuilder sb) {
    	int i = sb.length() - 1;
    	while (i > 0 && sb.charAt(i) == ' ')
    		i--;
	return sb.substring(0, i + 1);
    }

    private String getWord(String s) {
        if (!isWord(s)) {
           s = s.toLowerCase();
        }
        if (s.length() <= 3) return s;
        String ss = s.toLowerCase();
        String abbr = ext.get(ss);
        registerWord(s);
        if (abbr == null) {            
            return s;
        } else {
            if (ext.get(ss).equals(ss)) {
                return s;
            } else {
                return "" + s.charAt(0) + (s.length() - 2) + s.charAt(s.length() - 1);
            }
            
        }
    }

    private String extend(String abbr) {
        String s = abbrs.get(abbr.toLowerCase());
        if (s == null) {
            return abbr;
        } else {
            if (Character.isUpperCase(abbr.charAt(0))) {
                if (Character.isUpperCase(abbr.charAt(abbr.length() - 1))) {
                    return s.toUpperCase();
                } else {
                    return "" + Character.toUpperCase(s.charAt(0)) + s.substring(1);
                }
            } else {
                return s;
            }
        }
    }

    private boolean isWord(String s) {
        if (s.matches("[a-z]+")) return true;
        if (s.matches("[A-Z]+")) return true;
        if (s.matches("[A-Z][a-z]+")) return true;
        return false;
    }


    private void registerWord(String s) {
        s = s.toLowerCase();
        String abbr = "" + s.charAt(0) + (s.length() - 2) + s.charAt(s.length() - 1);
        String q = abbrs.get(abbr);
        if (q == null) {
            abbrs.put(abbr, s);
            ext.put(s, abbr);
        } else if (!q.equals(s)) {
            abbrs.put(abbr, abbr);
            ext.put(s, s);
        }
    }

    private boolean isWordPart(char c) {
        return Character.isLetter(c);
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
        new Thread(new gen1(args[0], args[1])).start();
    }
}
