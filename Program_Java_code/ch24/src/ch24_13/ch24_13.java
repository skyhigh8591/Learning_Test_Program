package ch24_13;

import java.util.HashMap;
import java.util.Map;

public class ch24_13 {

	public static void main(String[] args) {
		//HashMap<Integer,String>map = new HashMap<Integer,String>();
		HashMap<String,String>map = new HashMap<String,String>();
		
		//add
		map.put("a101", "Marry");
		map.put("a102", "Bill");
		map.put("a103", "Joe");
		map.put("a104", "Natasha");
		
		System.out.println("..........1............");
		System.out.println(map);
		
		//�ק�
		map.put("a103", "�p��");
		System.out.println(map);
		
		//�R��
		map.remove("a102");
		System.out.println(".......3......");
		
		//�j�M,����
		System.out.println("...............4................");
		System.out.println(map.get("a104"));
		
		//���X
		System.out.println("............5.............");	
		for(Map.Entry<String,String> entry:map.entrySet() )
		{
			String key = entry.getKey();
			String value = entry.getValue();
			System.out.println(key + " " + value);
			//System.out.println(entry.getKey() + " " + entry.getValue());
		}
		HashMap<Integer,String>map2 = new HashMap<Integer,String>();
		
		map2.put(111, "marry");
		map2.put(112, "bill");
		map2.put(113, "joe");
		System.out.println("............6.............");	
		for(Map.Entry<Integer,String> entry:map2.entrySet() )
		{
			Integer key = entry.getKey();
			String value = entry.getValue();
			System.out.println(key + " " + value);
			//System.out.println(entry.getKey() + " " + entry.getValue());
		}
		
	}

}
