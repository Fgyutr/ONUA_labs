import java.util.Scanner;

public class main {

    static String[] method24(String str) {
        String delimitr = " ";
        String[] subStr = str.split(delimitr);
        return subStr;
    }

    public static void method1(String str) {
        String[] subStr = method24(str);
        for (int i = 0; i < subStr.length; i++) {
            if (subStr[i].length() == 4) {
                System.out.println(subStr[i]);
            }
        }
    }

    public static void method2(String str) {
        for (int i = 0; i < str.length(); i++) {
            if ((str.charAt(i) >= 65 && str.charAt(i) <= 90) || (str.charAt(i) >= 97 && str.charAt(i) <= 122)) {
                int temp = str.charAt(i) + 127;
                str.replace(str.charAt(i), (char) temp);
            }
        }
        System.out.println(str);
    }

    public static void method3(String str) {
        boolean temp = false;
        String[] subStr = method24(str);
        for (int i = 0; i < subStr.length; i++) {
            for (int j = 0; j < subStr[i].length(); j++) {
                if ((subStr[i].charAt(i) >= 65 && subStr[i].charAt(i) <= 90) || (subStr[i].charAt(i) >= 97 && subStr[i].charAt(i) <= 122)) {
                    temp = true;
                } else {
                    temp = false;
                }
            }
            if (temp) {
                System.out.println(subStr[i]);
            }
        }
    }

    public static void method4(String str) {
        boolean temp = false;
        String[] subStr = method24(str);
        for (int i = 0; i < subStr.length; i++) {
            for (int j = 0; j < subStr[i].length(); j++) {
                if (subStr[i].charAt(i) >= 48 && subStr[i].charAt(i) <= 57) {
                    temp = true;
                } else {
                    temp = false;
                }
            }
            if (temp) {
                System.out.println(subStr[i]);
            }
        }
    }

    public static void method5(String str) {
        boolean temp = false;
        String[] subStr = method24(str);
        for (int i = 0; i < subStr.length; i++) {
            for (int j = 0; j < subStr[i].length(); j++) {
                if (subStr[i].charAt(j) >= 48 && subStr[i].charAt(j) <= 57) {
                    for (int k = subStr[i].length()-1; k >= 0; k--) {
                        if (subStr[i].charAt(j) == subStr[i].charAt(k)) {
                            temp = true;
                        }
                    }
                } else {
                    temp = false;
                    break;
                }
            }
            if (temp) {
                System.out.println(subStr[i]);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("Input a string: ");
        String str = in.nextLine();
        in.close();
        System.out.println("1");
        method1(str);
        System.out.println("2");
        method2("abcdefgааббвв");
        System.out.println("3");
        method3(str);
        System.out.println("4");
        method4(str);
        System.out.println("5");
        method5(str);
    }
}