package ch24_05_Arraylist_�إ�_�s�W_�ק�_�R��_���X;

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
		
		//�ק�
		arraylist.set(0,"dddd");
		System.out.println("........2.........");
		System.out.println(arraylist);
		
		//�R��
		arraylist.remove("bbb");
		System.out.println("........3.........");
		System.out.println(arraylist);
		arraylist.remove(1);
		System.out.println(arraylist);
		
		//���X
		System.out.println("........4.........");
		for(String obj:arraylist) {
			System.out.println(obj);
		}
		
		//���X2
		System.out.println("........5.........");
		for(int i = 0 ; i<arraylist.size();i++) {
			System.out.println(arraylist.get(i));
		}
		
		//���X3
		System.out.println("........6.........");
		Iterator<String> itr = arraylist.iterator();
		while(itr.hasNext()) {
			System.out.println(itr.next());
		}
		
		

	}

}
