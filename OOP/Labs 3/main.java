import java.util.Vector;
public class main {
    public static void method11(double mass[]) {
        double min = mass[0];
        for (int i = 0; i < mass.length; i++) {
            if (min > mass[i]) {
                min = mass[i];
            }
        }
        System.out.println(min);
    }
    public static void method12(double mass[]) {
        int first = 0, last = 0;
        boolean firsti = true;
        double sum = 0;
        for (int i = 0; i < mass.length; i++) {
            if (mass[i] > 0) {
                if (firsti) {
                    first = i;
                    firsti = false;
                }
                last = i;
            }
        }
        for (int i = first; i <= last; i++) {
            sum += mass[i];
        }
        System.out.println(sum);
    }
    public static void method21(int mass[][]) {
        int sum = 0;
        boolean temp = false;
        Vector<Integer> vecsum = new Vector<Integer>();
        Vector<Integer> vecstr = new Vector<Integer>();
        for (int i = 0; i < mass.length; i++) {
            for (int j = 0; j < mass[i].length; j++) {
                if (mass[i][j] < 0) {
                    temp = true;
                    vecstr.add(i);
                }
                sum += mass[i][j];
            }
            if (temp) {
                vecsum.add(sum);
            }
            sum = 0;
            temp = false;
        }
        for (int i = 0; i < vecsum.size(); i++) {
            System.out.printf("str: %d sum: %d \n", vecstr.get(i), vecsum.get(i));
        }
    }
    public static void method22(int mass[][]) {
        int min = mass[0][0];
        Vector<Integer> vec = new Vector<Integer>();
        for (int i = 0; i < mass.length; i++) {
            for (int j = 0; j < mass[i].length; j++) {
                if (min > mass[i][j]) {
                    min = mass[i][j];
                }
            }
        }
        for (int i = 0; i < mass.length; i++) {
            for (int j = 0; j < mass[i].length; j++) {
                if (mass[i][j] == min) {
                    vec.add(j);
                }
            }
        }
        for (int i = 0; i < vec.size(); i++) {
            System.out.println(vec.get(i));
        }
    }
    public static void main(String[] args) {
        double mass[] = { -5.0, -15.0, 4.0, -1.0, 32.0, 1.0, 2.0, 7.0 };
        double mass1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int array[][] = { { 1, 2, 3 }, { 1, 2, -5, 1, 5 }, { 1, 2, 3, 4, 5, 6, -5, 8, 1 } };
        System.out.println("Task11");
        method11(mass);
        System.out.println("Task11");
        method11(mass1);
        System.out.println("Task12");
        method12(mass);
        System.out.println("Task12");
        method12(mass1);
        System.out.println("Task21");
        method21(array);
        System.out.println("Task22");
        method22(array);
    }
}
