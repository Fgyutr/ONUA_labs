
public class main {

    static boolean method1(String str) {
        int size = str.length();
        if (str.charAt(size - 2) != 'e' || str.charAt(size - 1) != 'd') {
            return false;
        }
        return true;
    }

    static int method2(String str) {
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) >= '0' && str.charAt(i) <= '9') {
                sum += str.charAt(i) - 48;
            }
        }
        return sum;
    }

    static int method3(String str) {
        char c = str.charAt(0);
        int max = 0;
        int len = 1;
        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i) == c)
                len++;
            else {
                c = str.charAt(i);
                len = 1;
            }
            if (len > max)
                max = len;
        }
        return max;
    }

    static void method4(String str) {
        String delimitr = " ";
        String[] subStr = str.split(delimitr);
        for (int i = 0; i < subStr.length; i++) {
            System.out.println(subStr[i]);
        }
    }

    static String method5(String A, String B) {
        String result = "";
        int len = Math.min(A.length(), B.length());
        for (int i = 0; i < len; i++) {
            result = result + A.charAt(i) + B.charAt(i);
        }
        result = result + A.substring(len) + B.substring(len);
        return result;
    }

    public static void main(String[] args) {
        System.out.println(method1("fored"));
        System.out.println(method2("qwerty1"));
        System.out.println(method3("qqwwweeeerty1"));
        method4("Мозговой Максим Викторович");
        System.out.println(method5("Вася", "123456789"));
    }
}
