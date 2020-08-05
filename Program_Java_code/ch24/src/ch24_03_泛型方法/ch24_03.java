package ch24_03_ªx«¬¤èªk;

public class ch24_03 {

	public static void main(String[] args) {
		Integer [] i = {5,10,30,40,20};
		Character[] c = {'j','a','v','a'};
		Double[] d = {5.2,10.3,30.6,40.0,20.2};
		String[] s = {"aaa","bbb","ccc","ddd"};
		System.out.println("......1....");
		outputArray(i);
		System.out.println("......2....");
		outputArray(c);
		System.out.println("......3....");
		outputArray(d);
		System.out.println("......4....");
		outputArray(s);

	}
	
	public static <E> void outputArray(E[] elements) {
		for (E e:elements) {
			System.out.println(e);
		}
	}

}
