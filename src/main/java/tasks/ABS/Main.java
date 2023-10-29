package tasks.ABS;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr1 = {3, 5, 6, 14, 23};
        int[] arr2 = {2, 3, 6, 7};

        System.out.println(Arrays.toString(mergeArrays(arr1, arr2)));
    }

    private static int[] mergeArrays(int[] arr1, int[] arr2) {
        int ind1 = 0;
        int ind2 = 0;

        int curInd = 0;
        int[] res = new int[arr1.length + arr2.length];

        while (ind1 < arr1.length || ind2 < arr2.length) {
            if (ind1 < arr1.length && ind2 < arr2.length) {
                if (arr1[ind1] < arr2[ind2]) {
                    res[curInd++] = arr1[ind1++];
                }
                else {
                    res[curInd++] = arr2[ind2++];
                }
            }
            else if (ind1 == arr1.length) {
                res[curInd++] = arr2[ind2++];
            }
            else {
                res[curInd++] = arr1[ind1++];
            }
        }

        return res;
    }
}
