package ch08_fun_03_函數的認識02;

public class ch08_fun_03 {

	public static void main(String[] args) {
		int x,y;
		x=10;
		y=20;
		System.out.printf("原始 x=%d,y=%d\n",x,y);
		swap(x,y);
		System.out.printf("呼叫swap方法內部x=%d,y=%d\n",x,y);
	}
	public static void swap(int x, int y)
	{
		int tmp = x;
		x = y;
		y = tmp;
		System.out.printf("swap方法內部x=%d,y=%d\n",x,y);
	}

}
