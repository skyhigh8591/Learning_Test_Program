package ch24_08;

import java.util.LinkedList;



public class ch24_08 {

	public static void main(String[] args) {
		LinkedList<String> list = new LinkedList<String>();
		list.add("aaaaaaa");
		list.add("bbbbbbb");
		list.add("cccccccccc");
		System.out.println("...........1...........");
		System.out.println(list);
		
		list.addFirst("dddddddddd");
		list.addLast("eeeeeeeeeeeee");
		System.out.println("...............2................");
		System.out.println(list);
		
		//取得資料
		System.out.println("...............3.............");
		System.out.println("first data " + list.getFirst());
		System.out.println("last data " + list.getLast());
		
		//刪除
		list.removeFirst();
		System.out.println("...............4................");
		System.out.println(list);
		list.removeLast();
		System.out.println("...............5................");
		System.out.println(list);
		
		//走訪
		for (int i=0;i<list.size();i++) {
			System.out.println(list.get(i));
		}

	}

}
