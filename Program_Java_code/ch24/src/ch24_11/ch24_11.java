package ch24_11;

import java.util.HashSet;

public class ch24_11 {

	public static void main(String[] args) {
		HashSet<String> set = new HashSet<String>();
//		set.add("cc");
//		set.add("aa");
//		set.add("bb");
//		set.add("ee");
//		set.add("ff");
//		set.add("aa");
//		set.add("ff");
		set.add("d");
		set.add("c");
		set.add("b");
		set.add("a");
		set.add("a");
		
		
		System.out.println("........1.......");
		System.out.println(set);
		
		//�ק� ������ �A�s�W
		set.remove("b");
		set.add("e");
		System.out.println("........2.......");
		System.out.println(set);
		
		
		//�R��
		set.remove("c");
		System.out.println("........3.......");
		System.out.println(set);
		
		
		//���X
		System.out.println("........4.......");
			for(String value:set) {
				System.out.println(value);
			}
			
			
		//��L
		System.out.println("........5.......");
		System.out.println("size " + set.size());
		System.out.println("isEmpty : " + set.isEmpty());
		System.out.println("search a : " + set.contains("a"));
		set.clear();
		System.out.println("isEmpty : " + set.isEmpty());
			
	}

}
