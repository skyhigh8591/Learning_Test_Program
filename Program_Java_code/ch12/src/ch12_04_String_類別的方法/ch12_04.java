package ch12_04_String_���O����k;

public class ch12_04 {

	public static void main(String[] args) {
		
		//����
		System.out.println("..........1............");
		String str1 = new String("aaaaaaaaaa");
		String str2 = new String();
		System.out.println("str1����: " + str1.length());
		System.out.println("str2����: " + str2.length());
		System.out.println("str1�Ŧr��P�_: " + str1.isEmpty());
		System.out.println("str2�Ŧr��P�_: " + str2.isEmpty());
		
		//�j�p�g�ഫ
		System.out.println(".........2.............");
		String str3 = new String("BBBBBBBB");
		
		//�p�g�ܤj�g
		System.out.println("str1: " + str1.toUpperCase());
		
		//�j�g�ܤp�g
		System.out.println("str3: " + str3.toLowerCase());
		
		//�r���j�M
		System.out.println(".........3.............");
		String str4 = new String("abcdefghijklmnopq");
		System.out.println("���ު��r��= " + str4.charAt(0));
		System.out.println("���ު��r��= " + str4.charAt(str4.length()-1));
		
		System.out.println("5-11�s�r��= " + str4.substring(5));
		System.out.println("5-11�s�r��= " + str4.substring(5,8));
		System.out.println("�h�Y��= " + str4.substring(1,16));
		System.out.println("�h�Y��= " + str4.substring(1,str4.length()-1));
		
		System.out.println(".........4.............");
		char [] ch = str4.toCharArray();
		System.out.println(ch);
		System.out.println("���e" + ch[0] + ch[1] + ch[2] + ch[3]);
		
		//�r����N
		System.out.println("...........5.........");
		String str5 = str4.replace("abc", "12345");
		System.out.println(str5);
		
		String str6 = new String("      www.yahoo.tw");
		System.out.println(str6);
		System.out.println(str6.trim());
		
		
		
}

}
