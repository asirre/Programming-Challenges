import java.math.BigInteger;
import java.util.LinkedList;
import java.util.Scanner;

public class HowManyFibs {
    static LinkedList<BigInteger> longs = new LinkedList<>();

    static void Fibon(BigInteger n1, BigInteger n2,BigInteger b) {
        while (true) {
            BigInteger c = n1.add(n2);
            n1 = n2;
            n2 = c;
            if (c.compareTo(b) <=0) {
                longs.add(c);
            } else {
                break;
            }

        }
    }


public static void main(String[] args) {


    Scanner sc = new Scanner(System.in);
    BigInteger a,b;
    BigInteger n1 = new BigInteger("0");
    BigInteger n2 = new BigInteger("1");

    while(sc.hasNext()){
        a = sc.nextBigInteger();
        b = sc.nextBigInteger();
        if(a.compareTo(new BigInteger("0")) == 0 && b.compareTo(new BigInteger("0")) == 0)
            break;
        Fibon(n1, n2,b);
        int count = 0;
        for (BigInteger aLong : longs) {

            if (aLong.compareTo(a) >= 0)
            {
                count++;
            }
        }

        System.out.println(count);
        longs.clear();
        count = 0;

    }

}
}
