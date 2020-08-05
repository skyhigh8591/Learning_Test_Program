package ch08_03_屬性的設定與清除;



class MyClass{
	
	public String text="ABC";
	public void clear() 
	{
		text = " ";
	}
}



public class ch08_03 {

	public static void main(String[] args) {
		MyClass A = new MyClass();
//				MyClass A;
//				A = new Myclass();
		
		//取值
		System.out.println("text=" + A.text);
		
		//設定
		A.text = "DEF";
		System.out.println("text=" + A.text);
		
		//使用方法
		A.clear();
		System.out.println("text=" + A.text);
	}

}

		
	
	

