package tasks.Yandex.YandexSiriusFlutter2023;

import java.util.Scanner;

public class UpgradeHero {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        scanner.nextLine();

        int[] items = new int[n];
        int bp = 1;
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        int maxNeg = Integer.MIN_VALUE;
        int minPos = Integer.MAX_VALUE;
        int negCounter = 0;

        for (int i = 0; i < n; i++) {
            items[i] = scanner.nextInt();
            bp *= items[i];

            if (items[i] < 0) {
                negCounter++;
            }

            min = Math.min(min, items[i]);
            max = Math.max(max, items[i]);
            if (items[i] < 0) {
                maxNeg = maxNeg < 0 ? Math.max(maxNeg, items[i]) : items[i];
            }
            if (items[i] > 0) {
                minPos = minPos > 0 ? Math.min(minPos, items[i]) : items[i];
            }
        }

        int res;
        if (bp == 0) {
            if (negCounter % 2 == 0) {
                res = 0;
            } else {
                res = maxNeg;
            }
        } else {
            if (negCounter % 2 == 0) {
                if (negCounter == n) {
                    res = min;
                } else {
                    res = minPos;
                }
            } else {
                if (negCounter == n) {
                    res = max;
                } else {
                    res = maxNeg;
                }

            }

        }

        System.out.println(res);
    }
}
