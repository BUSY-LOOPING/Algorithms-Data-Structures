import java.util.HashMap;
import java.util.Locale;
import java.util.Map;

class roman2integer {

    public static void main(String[] args) {
        String s = "MCMXCIV";
        System.out.println(romanToInt(s));
    }

    public static int romanToInt(String s) {
        if (s.length() == 0) {
            return 0;
        }
        Map<String, Integer> map = new HashMap<>();
        map.put("I", 1);
        map.put("V",5);
        map.put("X", 10);
        map.put("L", 50);
        map.put("C", 100);
        map.put("D", 500);
        map.put("M", 1000);
        s = s.toUpperCase(Locale.getDefault());
        int res = 0;
        boolean flag = false;
        
        for (int i = 0 ; i < s.length() ; i++) {
            flag = false;
            if (s.substring(i, i+1) == "I") {
                if (i + 1 < s.length() && (s.substring(i + 1, i + 2) == "V" || s.substring(i + 1, i + 2) == "X")) {
                    res+= (map.get(s.substring(i + 1, i + 2)) - map.get(s.substring(i, i + 1)));
                    flag = true;
                }
            } 
            else if (s.substring(i, i+1) == "X") {
                if (i + 1 < s.length() && (s.substring(i + 1, i + 2) == "L"  || s.substring(i + 1, i + 2) == "C")) {
                    res+= (map.get(s.substring(i + 1, i + 2)) - map.get(s.substring(i, i + 1)));
                    flag = true;
                }
            }
            else if (s.substring(i, i+1) == "C") {
                if (i + 1 < s.length() && (s.substring(i + 1, i + 2) == "D"  || s.substring(i + 1, i + 2) == "M")) {
                    res+= (map.get(s.substring(i + 1, i + 2)) - map.get(s.substring(i, i + 1)));
                    flag = true;
                    
                }
            }

            if (!flag) {
                res += map.get(s.substring(i, i+1));
            } else {
                i = i+2;
            }
        }
        return res;
        
    }
}