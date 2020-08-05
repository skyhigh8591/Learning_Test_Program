package ch20_05_指定函數拋出例外;

public class ch20_05 {

	public static void myMethod(int x1, int x2) throws ArithmeticException {
		System.out.println("x1/x2=" + x1/x2);

	}
	
	public static void main(String[] args) {
		int[][] x = {{10,20},{10,0},{10,5}};
		for(int i = 0;i<x.length;i++) {
			try {
				myMethod(x[i][0],x[i][1]);
			}catch (ArithmeticException e) {
				System.out.println("除數為0:" + e);
			}
		}
		

	}
	

}
