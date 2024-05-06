package tasks.Tinkoff.tinkoff_cup;

import java.lang.reflect.InvocationTargetException;
import java.util.List;
import java.util.*;

public class Filter {
    public static List<Integer> filterOneCollectionByAnother(List<Integer> firstCollection, List<Integer> secondCollection) throws NoSuchMethodException, InvocationTargetException, InstantiationException, IllegalAccessException {
        @SuppressWarnings("unchecked")
        List<Integer> res = firstCollection.getClass().getConstructor().newInstance();
        res.addAll(firstCollection);
        res.retainAll(secondCollection);
        return res;
    }

    public static void main(String[] args) throws InvocationTargetException, NoSuchMethodException, InstantiationException, IllegalAccessException {
        ArrayList<Integer> list1 = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5, 6));
        ArrayList<Integer> list2 = new ArrayList<>(Arrays.asList(6, 7, 8, 9, 10));

        LinkedList<Integer> list3 = new LinkedList<>(Arrays.asList(1, 2, 3, 4, 5, 6));
        LinkedList<Integer> list4 = new LinkedList<>(Arrays.asList(6, 7, 8, 9, 10));

        System.out.println(filterOneCollectionByAnother(list1, list2));
        System.out.println(filterOneCollectionByAnother(list1, list4));
        System.out.println(filterOneCollectionByAnother(list3, list2));
        System.out.println(filterOneCollectionByAnother(list3, list4));
    }
}

