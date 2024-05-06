package tasks.Tinkoff.tinkoff_cup;

import java.util.*;

public class UniqueUsers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Set<String> users = new HashSet<>();

        for (int i = 0; i < n; i++) {
            String address = scanner.next().trim();
            String[] parts = address.split("@");
            String login = parts[0].replace(".", "").split("-")[0];
            String domain = String.join(".", Arrays.copyOfRange(parts[1].split("\\."), 0, parts[1].split("\\.").length - 1));
            String newAddress = login + "@" + domain;
            users.add(newAddress);
            System.gc();
        }

        System.out.println(users.size());
    }
}