package ch24_05_Arraylist_建立_新增_修改_刪除_走訪;

import java.util.ArrayList;
import java.util.Iterator;

public class ch24_05 {

	public static void main(String[] args) {
		ArrayList<String> arraylist = new ArrayList<String>();
		
		
		//add
		arraylist.add("aaa");
		arraylist.add("bbb");
		arraylist.add("ccc");
		arraylist.add(1,"eee");
		System.out.println(arraylist);
		
		//display
		System.out.println(".............1..............");
		System.out.println(arraylist);
		System.out.println(arraylist.size());
		
		//修改
		arraylist.set(0,"dddd");
		System.out.println("........2.........");
		System.out.println(arraylist);
		
		//刪除
		arraylist.remove("bbb");
		System.out.println("........3.........");
		System.out.println(arraylist);
		arraylist.remove(1);
		System.out.println(arraylist);
		
		//走訪
		System.out.println("........4.........");
		for(String obj:arraylist) {
			System.out.println(obj);
		}
		
		//走訪2
		System.out.println("........5.........");
		for(int i = 0 ; i<arraylist.size();i++) {
			System.out.println(arraylist.get(i));
		}
		
		//走訪3
		System.out.println("........6.........");
		Iterator<String> itr = arraylist.iterator();
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		

	}

}
