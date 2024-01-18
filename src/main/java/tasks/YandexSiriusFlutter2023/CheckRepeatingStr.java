package tasks.YandexSiriusFlutter2023;

import java.util.Scanner;

public class CheckRepeatingStr {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.nextInt();
        String str = sc.next();

        System.out.println(getRepeatedLen(str));
    }

    public static int getRepeatedLen(String str) {
        int len = str.length();
        for (int templateLen = 1; templateLen <= len; templateLen++) {
            char[] template = str.substring(0, templateLen).toCharArray();

            boolean canRepeat = true;
            for (int startIndex = templateLen; startIndex < len; startIndex += templateLen) {

                char[] substring = str.substring(startIndex, Math.min(len, startIndex + templateLen)).toCharArray();
                for (int i = 0; i < substring.length; i++) {
                    if (template[i] == substring[i] || substring[i] == '#' ) {
                        continue;
                    }

                    if (template[i] == '#') {
                        template[i] = substring[i];
                    } else {
                        canRepeat = false;
                        break;
                    }
                }
            }

            if (canRepeat) {
                return templateLen;
            }
        }
        return len;
    }
}
