package ch08_fun_03_��ƪ��{��02;

public class ch08_fun_03 {

	public static void main(String[] args) {
		int x,y;
		x=10;
		y=20;
		System.out.printf("��l x=%d,y=%d\n",x,y);
		swap(x,y);
		System.out.printf("�I�sswap��k����x=%d,y=%d\n",x,y);
	}
	public static void swap(int x, int y)
	{
		int tmp = x;
		x = y;
		y = tmp;
		System.out.printf("swap��k����x=%d,y=%d\n",x,y);
	}

}
