package tasks.Yandex.YandexSiriusFlutter2023;

import java.util.Scanner;

public class Task1_plane {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Ввод времени отправления
        String departureTimeStr = scanner.nextLine();
        String[] departureTimeArr = departureTimeStr.split(":");
        int departureHour = Integer.parseInt(departureTimeArr[0]);
        int departureMinute = Integer.parseInt(departureTimeArr[1]);

        // Ввод времени прибытия
        String arrivalTimeStr = scanner.nextLine();
        String[] arrivalTimeArr = arrivalTimeStr.split(":");
        int arrivalHour = Integer.parseInt(arrivalTimeArr[0]);
        int arrivalMinute = Integer.parseInt(arrivalTimeArr[1]);

        // Ввод разницы в часовых поясах
        int timeZoneDifference = scanner.nextInt();

        arrivalHour -= timeZoneDifference;

        int arrivalTime = arrivalHour * 60 + arrivalMinute;
        int departureTime = departureHour * 60 + departureMinute;

        if (arrivalTime <= departureTime) {
            arrivalTime += 24 * 60;
        }
        if (arrivalTime <= departureTime) {
            arrivalTime += 24 * 60;
        }
        if (arrivalTime <= departureTime) {
            arrivalTime += 24 * 60;
        }

        // Вычисление продолжительности полета
        int flightDuration = arrivalTime - departureTime;

        // Вывод результата
        int hours = flightDuration / 60;
        int mins = flightDuration % 60;

        System.out.println(hours + ":" + String.format("%02d", mins));
    }
}

