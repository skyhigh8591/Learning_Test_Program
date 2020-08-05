package ch12_05_¦r¦ê¤ñ¸û;

public class ch12_05 {

	public static void main(String[] args) {
		String st1 = "abcdefg";
		String st2 = new String("ABcdefg");
		String st3 = new String("aabbccdd");
		String st4 = "abcdefg";
		
		System.out.println(st1.compareTo(st2));
		System.out.println(st2.compareTo(st3));
		System.out.println(st1.compareTo(st4));
		
		System.out.println(st1.compareToIgnoreCase(st2));
		System.out.println(st2.compareToIgnoreCase(st3));
		
		System.out.println(st1.equals(st2));
		System.out.println(st2.equalsIgnoreCase(st2));
		
	}

}
