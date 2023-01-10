public class analyze {

    private static String str="Hello";

    public static void main(String[] args) {

        boolean isHere=true;

        int count=isHere ? 10:10;  //issue?

        if(!str.equals("Hello")&& !str.equals("Hello")) //issue?
        {

            str="hi";
        }
        int i=6;



        System.out.println(i>0.5); //issue?


        System.out.println(count);
        System.out.println("");  //issue?



    }
}






