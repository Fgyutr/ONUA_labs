
public class main {

	static String[] method24(String s) {
		String delimitr = " ";
		String[] subStr = s.split(delimitr);
		return subStr;
	}

	public static void method1(String s) {
		String[] subStr = method24(s);
		for (int i = 0; i < subStr.length; i++) {
			if (subStr[i].length() == 4) {
				System.out.println(subStr[i]);
			}
		}
	}

	public static void method2(String s) {
		String[] subStr = method24(s);
		for (int i = 0; i < subStr.length; i++) {
			subStr[i] = cyr2lat(subStr[i]);
			System.out.println(subStr[i]);
		}
	}

	public static String cyr2lat(String s) {
		char[] ch = s.toCharArray();
		char[] mass = new char[ch.length];
		for (int i = 0; i < ch.length; i++) {

			mass[i] = (char) (ch[i] + 975);
		}
		String huinia = String.valueOf(mass);
		return huinia;
	}

	public static void method3(String s) {
		int count = 0;
		String[] subStr = method24(s);
		boolean temp = true;
		for (int i = 0; i < subStr.length; i++) {
			for (int j = 0; j < subStr[i].length(); j++) {
				if ((subStr[i].charAt(j) < 65 || subStr[i].charAt(j) > 90)
						&& (subStr[i].charAt(j) < 97 || subStr[i].charAt(j) > 122)) {
					temp = false;
					break;
				}
			}
			if (temp) {
				count += 1;
			}
			temp = true;
		}
		System.out.printf("количество слов, содержащих только символы латинского алфавита: %d\n", count);
	}

	public static void method4(String s) {
		int count = 0;
		String[] subStr = method24(s);
		boolean temp = true;
		for (int i = 0; i < subStr.length; i++) {
			for (int j = 0; j < subStr[i].length(); j++) {
				if (subStr[i].charAt(j) < 48 || subStr[i].charAt(j) > 57) {
					temp = false;
					break;
				}
			}
			if (temp) {
				count += 1;
			}
			temp = true;
		}
		System.out.printf("количество слов, содержащих только цифры: %d\n", count);
	}

	public static void method5(String s) {
		String[] subStr = method24(s);
		boolean temp = true;
		for (int i = 0; i < subStr.length; i++) {
			for (int j = 0; j < subStr[i].length(); j++) {
				if (subStr[i].charAt(j) < 48 || subStr[i].charAt(j) > 57) {
					temp = false;
					break;
				}
				if (subStr[i].charAt(j) != subStr[i].charAt(subStr[i].length() - 1 - j)) {
					temp = false;
					break;
				}
			}
			if (temp) {
				System.out.println(subStr[i]);
			}
			temp = true;
		}
	}

	public static void main(String[] args) {
		System.out.println(
				"Задана строка, состоящая из нескольких слов. Вывести на консоль слова из строки, состоящие из 4 букв.");
		method1("Всем привет как вы поживаете? это же супер слов куда");
		System.out.println(
				"Заменить все символы латинского алфавита в слове на соответствующие символы русского алфавита.");
		method2("ABCDEFGHIKLMNOPQRSTVXYZabcdefghiklmnopqrstvxyz Mama Papa ");
		System.out.println(
				"Ввести n слов с консоли. Найти количество слов, содержащих только символы латинского алфавита.");
		method3("ABCDEFGHIKLMNOPQRSTVXYZ Mama Papa mama papa Всем привет как вы поживаете? это же супер слов куда ");
		System.out.println("Ввести n слов с консоли. Найти количество слов, содержащих только цифры.");
		method4("Mama Papa mama papa 1 2 3 4 5");
		System.out.println("Ввести n слов с консоли. Среди слов, состоящих только из цифр, найти слово-палиндром.");
		method5("123321 12321 Mama Papa mama papa 1 2");

	}
}
