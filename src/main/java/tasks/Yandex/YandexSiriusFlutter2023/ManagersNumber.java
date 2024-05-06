package tasks.Yandex.YandexSiriusFlutter2023;

import java.util.ArrayList;
import java.util.Scanner;

public class ManagersNumber {
    static class Node {
        public int number;
        public int managersNumber = 0;
        public ArrayList<Node> employees = new ArrayList<>();

        public Node(int number) {
            this.number = number;
        }

        public void setManagersNumber() {
            for (Node emp: employees) {
                emp.managersNumber = this.managersNumber + 1;
                emp.setManagersNumber();
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        ArrayList<Node> employees = new ArrayList<>(n + 1);

        for (int i = 0; i <= n; i++) {
            employees.add(new Node(i));
        }

        for (int employeeInd = 1; employeeInd <= n; employeeInd++) {
            int managerInd = sc.nextInt();

            employees.get(managerInd).employees.add(employees.get(employeeInd));
        }

        //from director
        employees.get(0).employees.get(0).setManagersNumber();

        for (int i = 1; i < n + 1; i++) {
            System.out.print(employees.get(i).managersNumber + " ");
        }
    }
}
