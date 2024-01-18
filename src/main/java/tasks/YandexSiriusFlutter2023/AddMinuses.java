package tasks.YandexSiriusFlutter2023;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.StringJoiner;

public class AddMinuses {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        System.out.println(addMinuses(s));
    }

    public static String addMinuses(String s) {
        StringJoiner stringJoiner = new StringJoiner("-");

        ArrayList<String> res = new ArrayList<>();
        res.add(s);

        HashSet<String> set = new HashSet<>();

        for(int i = 0; i < s.length(); i++) {
            String substring = s.substring(s.length() - 1 - i);
            if (i > 0 && Integer.parseInt(substring) == 0){
                continue;
            }
            set.add(substring);
            ArrayList<String> added = addMinuses(s.substring(0, s.length() - i - 1), set);
            set.remove(substring);

            if (added.isEmpty()) {
                continue;
            }

            if (res.size() <= added.size()) {
                res = added;
                res.add(substring);
            }
        }

        for(String string: res) {
            stringJoiner.add(string);
        }

        return stringJoiner.toString();
    }

    private static ArrayList<String> addMinuses(String s, HashSet<String> set) {
        ArrayList<String> res = new ArrayList<>();

        for(int i = 0; i < s.length(); i++) {
            String substring = s.substring(s.length() - 1 - i);

            if (set.contains(substring)) {
                continue;
            }

            if (i > 0 && Integer.parseInt(substring) == 0){
                continue;
            }

            set.add(substring);
            String substring1 = s.substring(0, s.length() - i - 1);
            ArrayList<String> added = addMinuses(substring1, set);
            set.remove(substring);

            if (added.isEmpty() && !substring1.isEmpty()) {
                continue;
            }

            if (res.size() <= added.size()) {
                res = added;
                res.add(substring);
            }
        }

        return res;
    }
}

