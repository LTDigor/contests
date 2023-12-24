package tasks.Leetcode;

import java.util.Arrays;

public class MaximumProductDifference1913 {
    public static void main(String[] args) {
        System.out.println(maxProductDifference(new int[]{5, 6, 2, 7, 4}));
    }

    public static int maxProductDifference(int[] nums) {
        Arrays.sort(nums);

        int len = nums.length;
        return nums[len - 1] * nums[len - 2] - nums[0] * nums[1];
    }
}
