package ch24_07_面試考題;

import java.util.*;

public class ch24_07 {

	public static void main(String[] args) {
		List<String> list = new ArrayList<String>();
		List<String> alist = new ArrayList<String>();
		List<String> blist = new ArrayList<String>();
		List<String> jlist = new ArrayList<String>();
		
		list.add("Abc");
		list.add("Benjamin");
		list.add("Jake");
		list.add("Jerome");
		
		System.out.println(".........1........");
		System.out.println(list);
		
		for(int i=0 ; i<list.size();i++)
		{
			//System.out.println(list.get(i).charAt(0));
			if(list.get(i).charAt(0)=='A') {
				alist.add(list.get(i));
				list.remove(i);
				i--;
			}
			else if (list.get(i).charAt(0)=='B') {
				blist.add(list.get(i));
				list.remove(i);
				i--;
			}
			else if (list.get(i).charAt(0)=='J') {
				jlist.add(list.get(i));
				list.remove(i);
				i--;		
			}
		}
		System.out.println("..........2...........");
		System.out.println(list);
		System.out.println(alist);
		System.out.println(blist);
		System.out.println(jlist);

	
	}

}
