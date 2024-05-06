package tasks.Tinkoff.tinkoff_cup;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class CalculateSum
{
    public static void main(String[] args)
    {
//        BufferedReader inputDataBR = new BufferedReader(new InputStreamReader(System.in));

        List<Double> persents = new ArrayList<>(Arrays.asList(0.1, 0.02));
        List<Double> purchases = new ArrayList<>(Arrays.asList(100.0, 300.0));

        double sum = 0;
        for (int i = 0; i < purchases.size(); i++) {
            sum += purchases.get(i) * persents.get(i);
        }
        System.out.println(sum);
    }
}