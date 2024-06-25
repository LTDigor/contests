package tasks;

import java.util.*;

/*

Дан текст - "Я люблю программировать на java.Java лучший язык программирования, а так же один из самый популярных [JaVa]"
Необходимо посчитать количество слов в тексте, без учета регистра и разделитерей
(разделителем считается любой символ или последовательность символов кроме букв), и вывести в алфавитном порядке:
{java=3, а=1, же=1, ..... }
 */
public class Main {
    public static void main(String[] args) {
        String text = "Я люблю программировать на java.Java лучший язык программирования, а так же один из самый популярных [JaVa]";
        System.out.println(countWords(text));
    }

    public static Map<String, Integer> countWords(String string) {
        Map<String, Integer> result = new TreeMap<>();

        String[] words = string.split("[^a-zA-ZА-Яа-я]");
        for (String word : words) {
            if (!Objects.equals(word, "")) {
                result.merge(word.toLowerCase(Locale.ROOT), 1, Integer::sum);
            }
        }

        return result;
    }
}
