package ch12_07_¦r¦ê¤Á³Î;

public class ch12_07 {

	public static void main(String[] args) {
		String str = "I love Java";
		String [] words = str.split("\\s");
		System.out.println("str¥y¤l¦³" + words.length + "­Ó¦r\n");
		
		for (String w:words) {
			System.out.println(w);
		}
		
		String str2 = "I, love, Java, aaa, bb";
		String[] words2 = str2.split(",");
		
		for (String w:words2) {
			System.out.print(w);
		}
		System.out.println(" ");
		System.out.println("...............");
		
		for (String w:words2) {
			System.out.print(w.trim());
		}
	}
}
