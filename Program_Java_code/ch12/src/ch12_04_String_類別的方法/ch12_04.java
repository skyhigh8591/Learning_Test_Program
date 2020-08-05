package ch12_04_String_類別的方法;

public class ch12_04 {

	public static void main(String[] args) {
		
		//長度
		System.out.println("..........1............");
		String str1 = new String("aaaaaaaaaa");
		String str2 = new String();
		System.out.println("str1長度: " + str1.length());
		System.out.println("str2長度: " + str2.length());
		System.out.println("str1空字串判斷: " + str1.isEmpty());
		System.out.println("str2空字串判斷: " + str2.isEmpty());
		
		//大小寫轉換
		System.out.println(".........2.............");
		String str3 = new String("BBBBBBBB");
		
		//小寫變大寫
		System.out.println("str1: " + str1.toUpperCase());
		
		//大寫變小寫
		System.out.println("str3: " + str3.toLowerCase());
		
		//字元搜尋
		System.out.println(".........3.............");
		String str4 = new String("abcdefghijklmnopq");
		System.out.println("索引的字元= " + str4.charAt(0));
		System.out.println("索引的字元= " + str4.charAt(str4.length()-1));
		
		System.out.println("5-11新字串= " + str4.substring(5));
		System.out.println("5-11新字串= " + str4.substring(5,8));
		System.out.println("去頭尾= " + str4.substring(1,16));
		System.out.println("去頭尾= " + str4.substring(1,str4.length()-1));
		
		System.out.println(".........4.............");
		char [] ch = str4.toCharArray();
		System.out.println(ch);
		System.out.println("內容" + ch[0] + ch[1] + ch[2] + ch[3]);
		
		//字串取代
		System.out.println("...........5.........");
		String str5 = str4.replace("abc", "12345");
		System.out.println(str5);
		
		String str6 = new String("      www.yahoo.tw");
		System.out.println(str6);
		System.out.println(str6.trim());
		
		
		
}

}
