package ch08_03_�ݩʪ��]�w�P�M��;



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
		
		//����
		System.out.println("text=" + A.text);
		
		//�]�w
		A.text = "DEF";
		System.out.println("text=" + A.text);
		
		//�ϥΤ�k
		A.clear();
		System.out.println("text=" + A.text);
	}

}

		
	
	

