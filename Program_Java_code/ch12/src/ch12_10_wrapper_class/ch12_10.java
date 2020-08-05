package ch12_10_wrapper_class;

public class ch12_10 {

	public static void main(String[] args) {
		System.out.println(".........1..........");
		int data1 = 10;
		int data2 = 20;
		
		Integer w1 = new Integer(data1);
		Integer w2 = new Integer(20);
		
		System.out.println(w1.getClass());
		System.out.println(w2.getClass());
		System.out.println((double)data1/3);
		
		w1 = w1 + 50;
		System.out.println(w1.doubleValue()/3);
		System.out.println(w1==w2);
		System.out.println(w1.compareTo(w2));
		
		
		/////////////////////////////////////////
		System.out.println("........2..........");
		double d1 = 3.0;
		Double d2 = new Double(3.0);
		Double d3 = new Double(3.0);
		
		System.out.println(d2==d3);
		System.out.println(d1==d3);
		
		System.out.println(d2.getClass());
		
		System.out.println("........3..........");
		
		int i1 = 3;
		Integer i2 = new Integer(3);
		Integer i3 = new Integer(3);
		
		System.out.println(i2==i3);
		System.out.println(i1==i3);
		
		System.out.println(i2.getClass());
		
		System.out.println(i2.equals(i3));
		System.out.println(i2.equals(i1));

	}

}
