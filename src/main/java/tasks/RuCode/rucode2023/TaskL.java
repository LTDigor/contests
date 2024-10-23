package tasks.RuCode.rucode2023;

import java.util.*;
import java.io.*;

public class TaskL {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(reader.readLine().trim());
        int[] p = Arrays.stream(reader.readLine().trim().split(" ")).mapToInt(Integer::parseInt).toArray();
        int T = Integer.parseInt(reader.readLine().trim());

        List<int[]> negHeapSavedList = new ArrayList<>();
        for (int i = 0; i < p.length; i++) {
            if (p[i] > 0) {
                negHeapSavedList.add(new int[]{-p[i], i});
            }
        }
        PriorityQueue<int[]> negHeapSaved = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        negHeapSaved.addAll(negHeapSavedList);

        for (int t = 0; t < T; t++) {
            PriorityQueue<int[]> negHeap = new PriorityQueue<>(negHeapSaved);
            String retestResult = "0";
            while (!negHeap.isEmpty() && retestResult.equals("0")) {
                int ind = negHeap.poll()[1];

                System.out.println("retest " + (ind + 1));
                System.out.flush();
                reader.readLine();
                retestResult = reader.readLine().trim();
            }
            System.out.println("done");
            System.out.flush();
            reader.readLine();
        }
    }
}
