package tasks.YandexSiriusFlutter2023;

import java.util.Scanner;

public class LongestChar {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String word = scanner.next();

        int prev = scanner.nextInt();
        int max = prev;
        int lastIndex = 0;

        for (int i = 1; i < n; i++) {
            int actual = scanner.nextInt();
            int value = actual - prev;
            prev = actual;

            if (value >= max) {
                max = value;
                lastIndex = i;
            }
        }

        System.out.println(word.charAt(lastIndex));
    }
}