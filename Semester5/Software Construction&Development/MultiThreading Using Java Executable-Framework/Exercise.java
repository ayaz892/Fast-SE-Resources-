import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Exercise {

    public static void main(String args[]) {


     

    

     



        System.out.println("-----Equation1 with threads------");

        ExecutorService executor = Executors.newFixedThreadPool(6);

        Equation one = new Equation(32,20,25,15,4);
        Equation two = new Equation(32,20,25,15,4);
       Equation three = new Equation(32,20,25,15,4);
       Equation four = new Equation(32,20,25,15,4);
       Equation five = new Equation(32,20,25,15,4);
       Equation six = new Equation(32,20,25,15,4);






        executor.execute(one);
        
        executor.execute(two);
        executor.execute(three);
        executor.execute(four);
        executor.execute(five);
        executor.execute(six);



        executor.shutdown();

    
        System.out.println("velocity is:"+one.getsolve1());
        System.out.println("mass is:"+two.getsolve2());
        System.out.println("Kinetic Energy is:"+three.finalsolve());
        
        System.out.println("\n-----Equation2 with threads------");

        System.out.println("Charge on object q is:"+four.getcal1());
        System.out.println("Distance b/w   object r is:"+five.getcal2());
        System.out.println("Electric Potential Energy is:"+six.finalcal());

        
    }
}