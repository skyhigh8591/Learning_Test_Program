package ch12_01_�r�ꪺ�إ�;

public class ch12_01 {

	public static void main(String[] args) {
		char[] ch1 = {'�H','��','�j','��'};
		char[] ch2 = {'M','I','N','G','-','C','H','I'};
		
		String str1 = new String();
		System.out.println("str1 "+str1);
		
		String str2 = new String("�H���j��");
		System.out.println("str2 "+str2);
		
		String str3 = new String(ch1);
		System.out.println("str3 "+str3);
		
		String str4 = new String(ch2);
		System.out.println("str4 "+str4);
		
		String str5 = new String(ch1,1,3);
		System.out.println("str5 "+str5);
		
		String str6 = new String(ch2,2,4);
		System.out.println("str5 "+str6);
	}

}
