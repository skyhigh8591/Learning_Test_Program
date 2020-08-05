package ch24_06_Java的List在刪除元素_容易觸碰陷阱;

import java.util.ArrayList;

public class ch24_06 {

	public static void main(String[] args) {
		ArrayList<String> arraylist = new ArrayList<String>();
		
		
		//add
		arraylist.add("a");
		arraylist.add("b");
		arraylist.add("c");
		arraylist.add("d");
		arraylist.add("c");
		arraylist.add("c");

		System.out.println(".............1..............");
		System.out.println(arraylist);
		
//		for(String obj:arraylist) {
//			if(obj=="cccc") {
//				arraylist.remove("cccc");
//			}
//		}
		
		System.out.println(".....2.....");
		for(int i=0;i<arraylist.size();i++) {
			if(arraylist.get(i)=="c") {
				arraylist.remove(i);
				i--;
				//arraylist.remove("cccc");
			}
		}
		System.out.println(arraylist);

	}

}
