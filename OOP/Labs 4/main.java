import java.util.Scanner;

public class main {

    static String[] method24(String str) {
        String delimitr = " ";
        String[] subStr = str.split(delimitr);
        return subStr;
    }
    
    public static void method1() {
        Scanner in = new Scanner(System.in);
        System.out.print("Input a string: ");
        String str = in.nextLine();
        String[] subStr = method24(str);
        for (int i = 0; i < subStr.length; i++) {
            if (subStr[i].length() == 4) {
                System.out.println(subStr[i]);
            }
        }
        in.close();
    }


    public static void main(String[] args) {
        method1();
        
    }
}
