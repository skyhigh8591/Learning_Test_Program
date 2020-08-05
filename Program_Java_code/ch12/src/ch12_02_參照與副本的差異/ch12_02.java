package ch12_02_參照與副本的差異;

public class ch12_02 {

	public static void main(String[] args) {
		char[] ch1 = {'A','P','P','L','E'};
		String str1 = new String();
		String str2 = new String(ch1);
		String str3 = new String(str2);
		str1 = str2;
		
		System.out.println("str1 " + str1);
		System.out.println("str2 " + str2);
		System.out.println("str3 " + str3);
		
		System.out.println("str1 vs str2: " + (str1==str2));
		System.out.println("str2 vs str3: " + (str2==str3));
		

	}

}
