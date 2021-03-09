import java.util.ArrayList;
import java.util.Scanner;

public class Hartals {


    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> hartals = new ArrayList<>();
        int cases;
        int days;
        int parties;
        cases = sc.nextInt();

        for (int i=0;i<cases;i++)
        {
            days = sc.nextInt();
            parties = sc.nextInt();
            while(hartals.size() < parties)
            {
                int hartal = sc.nextInt();
                if((hartal%7) != 0) {
                    hartals.add(hartal);
                }
                else {
                    break;
                }

            }

            int count =0;
            int day = 1;
            for(int d=1;d<=days;d++) {
                if(day == 8)
                    day =1;
                for (int p = 0; p < parties; p++) {

                        if (d%hartals.get(p)==0 && (day!=6 && day !=7))
                        {
                            count++;
                            break;
                        }

                }
                day++;
            }
            hartals.clear();




            System.out.println(count);

        }
    }
}
