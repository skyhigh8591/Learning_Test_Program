package ch20_01_02_例外處理的順序;

public class ch20_01_02 {

	public static void main(String[] args) {
		
		try {
		int [] arr = new int[5];
		arr[10]=7;
		System.out.println("end of main() method");
		}catch(ArrayIndexOutOfBoundsException e) {
			System.out.println("index out of boind");
		}
		finally {
			System.out.println("this line is always executed");
		}
		System.out.println("end of main() method");
	}

}
