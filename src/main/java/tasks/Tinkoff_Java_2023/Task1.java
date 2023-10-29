package tasks.Tinkoff_Java_2023;

import java.util.HashMap;
import java.util.Scanner;

public class Task1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();

        int count = 0;

        if (s.length() < 9) {
            System.out.println("NO");
            return;
        }

        HashMap<Character, Integer> map = new HashMap<>();
        for (int i = 0; i <= 9; i++) {
            map.put((char) ('0' + i), 0);
        }
        map.put('?', 0);

        for (int i = 0; i < 10; i++) {
            char c = s.charAt(i);
            map.put(c, map.get(c) + 1);

            if (map.get(c) == 1) {
                count++;
            }
            else {
                count--;
            }
        }

        if (count + map.get('?') == 10) {
            System.out.println("YES");
            return;
        }

        for (int i = 10; i < s.length(); i++) {
            char c = s.charAt(i);
            map.put(c, map.get(c) + 1);
            if (map.get(c) == 1) {
                count++;
            }

            c = s.charAt(i - 10);
            map.put(c, map.get(c) - 1);

            if (map.get(c) == 1) {
                count++;
            }
            else {
                count--;
            }

            if (count + map.get('?') == 10) {
                System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }

}
