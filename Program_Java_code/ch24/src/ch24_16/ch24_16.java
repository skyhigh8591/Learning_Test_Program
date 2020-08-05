package ch24_16;

import java.util.HashMap;
import java.util.Map;

class Phone{
	public String Pname;
	public int Price;
	public Phone(String pname, int price) {
		super();
		this.Pname = pname;
		this.Price = price;
	}
	public String getPname() {
		return Pname;
	}
	public void setPname(String pname) {
		Pname = pname;
	}
	public int getPrice() {
		return Price;
	}
	public void setPrice(int price) {
		Price = price;
	}
	
	
}



public class ch24_16 {

	public static void main(String[] args) {
		HashMap<String,Phone> map = new HashMap<String,Phone>();
		map.put("IPHONE", new Phone("哀鳳",30000));
		map.put("SAMSUNG", new Phone("三星",25000));
		map.put("HTC", new Phone("宏達電",10000));
		
		for(Map.Entry<String,Phone> entry:map.entrySet() )
		{
			String key = entry.getKey();
			
			System.out.println(entry.getKey() + " " + entry.getValue().getPname()+" "+entry.getValue().getPrice());
		}
		
				
	}

}
