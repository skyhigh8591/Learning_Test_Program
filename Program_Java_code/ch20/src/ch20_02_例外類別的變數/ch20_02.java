package ch20_02_�ҥ~���O���ܼ�;

public class ch20_02 {

	public static void main(String[] args) {
		try {
			int [] arr = new int[5];
			arr[10]=7;
			
			}catch(ArrayIndexOutOfBoundsException e) {
				System.out.println("index out of boind");
				System.out.println("exception= " + e);
			}
			
			System.out.println("end of main() method");
		}


	}


