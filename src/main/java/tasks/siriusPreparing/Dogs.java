package tasks.siriusPreparing;

import java.util.Scanner;

public class Dogs {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }

        for (int i = 0; i < n; i++) {
            b[i] = scanner.nextInt();
        }

        int res = 0;
        long minNegatives = Long.MAX_VALUE;
        for (int start = 0; start < n; start++) {
            int negatives = 0;
            for (int collarInd = 0; collarInd < n; collarInd++) {
                int dogInd = (start + collarInd) % n;
                int dogR = b[dogInd];
                int collarR = a[collarInd];

                if (dogR > collarR) {
                    continue;
                } else if (collarR - dogR <= 100) {
                    negatives += (collarR - dogR) / 2;
                } else {
                    negatives += 30;
                }
            }
            if (negatives < minNegatives) {
                res = start + 1;
                minNegatives = negatives;
            }
        }
        System.out.println(res + " " + minNegatives);
    }
}

