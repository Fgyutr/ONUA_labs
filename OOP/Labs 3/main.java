
public class main {
    public static void method1(double mass[]) {
        double min = mass[0];
        for (int i = 0; i < mass.length; i++) {
            if (min > mass[i]) {
                min = mass[i];
            }
        }
        System.out.println(min);
    }

    public static void method2(double mass[]) {
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

    public static void main(String[] args) {
        double mass[] = { -5.0, -15.0, 4.0, -1.0, 32.0, 1.0, 2.0, 7.0 };
        method1(mass);
        method2(mass);
        double mass1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        method1(mass1);
        method2(mass1);
    }
}
