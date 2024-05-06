package tasks.Tinkoff.tinkoff_cup;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

class FiveLetters {
    public static void main(String[] args) {
        var scanner = new Scanner(System.in);
        var input = scanner.nextLine();
        var words = input.split(", ");
        var first = words[0];
        var second = words[1];

        Set<Character> charSet = new HashSet<>();

        for (int i = 0; i < 5; i++) {
            charSet.add(second.charAt(i));
        }

        var res = new ArrayList<Integer>();
        for (int i = 0; i < 5; i++) {
            if (first.charAt(i) == second.charAt(i)) {
                res.add(1);
            } else {
                if (charSet.contains(first.charAt(i))) {
                    res.add(0);
                    charSet.remove(first.charAt(i));
                }
                else {
                    res.add(-1);
                }
            }

        }

        // здесь решение

        String result = String.join(", ", res.toString().replace("[", "").replace("]", ""));
        System.out.println(result);
    }
}
