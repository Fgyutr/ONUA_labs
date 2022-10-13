
class main {

    static int method1(int mass[]) {
        if (mass.length < 2) {
            return 2;
        }
        for (int i = 1; i < mass.length; i++) {
            if (mass[i] >= mass[i - 1]) {
                continue;
            } else {
                return 0;
            }
        }
        return 1;
    }

    static void method2() {
        for (int i = 1; i < 101; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                System.out.printf("FizzBuzz ", i);
            } else if (i % 3 == 0) {
                System.out.printf("Fizz ", i);
            } else if (i % 5 == 0) {
                System.out.printf("Buzz ", i);
            } else {
                System.out.printf("%d ", i);
            }
        }

    }

    static int method3(int mass[]) {
        if (mass.length < 2 || mass.length % 2 != 0) {
            return 2;
        }
        int sumStart = 0, sumFinish = 0;
        for (int i = 1; i < mass.length / 2; i++) {
            sumStart += mass[i];
            sumFinish += mass[mass.length - i];
        }
        if (sumStart == sumFinish) {
            return 1;
        }
        return 0;
    }

    public static void main(String[] args) {
        int mass1[] = { 0 };
        int mass2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        int mass3[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
        int result = method1(mass1);
        System.out.println("Task1");
        if (result == 2) {
            System.out.println("позаботьтесь про ввод большего количества данных!");
        } else if (result == 1) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
        result = method1(mass2);
        if (result == 2) {
            System.out.println("позаботьтесь про ввод большего количества данных!");
        } else if (result == 1) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
        result = method1(mass3);
        if (result == 2) {
            System.out.println("позаботьтесь про ввод большего количества данных!");
        } else if (result == 1) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
        System.out.println("Task2");
        method2();
        System.out.println("");
        System.out.println("Task3");
        result = method3(mass1);
        if (result == 2) {
            System.out.println("исправте ввод!");
        } else if (result == 1) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
        result = method3(mass2);
        if (result == 2) {
            System.out.println("исправте ввод!");
        } else if (result == 1) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
        result = method3(mass3);
        if (result == 2) {
            System.out.println("исправте ввод!");
        } else if (result == 1) {
            System.out.println(true);
        } else {
            System.out.println(false);
        }
    }
}