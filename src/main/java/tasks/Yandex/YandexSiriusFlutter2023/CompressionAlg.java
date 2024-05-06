package tasks.Yandex.YandexSiriusFlutter2023;

import java.util.Scanner;

public class CompressionAlg {
    static class Node {
        public Node[] arr = {null, null};
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        Node root = new Node();
        Node current = root;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            sb.append(c);

            if (current.arr[c - '0'] == null) {
                current.arr[c - '0'] = new Node();

                System.out.print(sb + " ");
                sb.setLength(0);

                current = root;
            } else {
                current = current.arr[c - '0'];
            }
        }

        if (sb.length() > 0) {
            System.out.print(sb);
        }
    }
}