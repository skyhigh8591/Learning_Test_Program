package ch09_12_static¤èªk;

class PrintSample{
	public static void output()
	{
	System.out.println("test");
	}
	public static void output2()
	{
		System.out.println("test2");
	}
	
}



public class ch09_12 {

	public static void main(String[] args) {
		PrintSample.output();
		//PrintSample.output2():false
		PrintSample.output2();
		
		
		PrintSample A = new PrintSample();
		A.output();
		A.output2();
	}

}
