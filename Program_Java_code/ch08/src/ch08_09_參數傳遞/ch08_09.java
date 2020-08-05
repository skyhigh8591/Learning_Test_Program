package ch08_09_參數傳遞;

class DataBank
{
	int x,y;
}
public class ch08_09 {

	public static void main(String[] args) {
		DataBank A = new DataBank();
		A.x = 10;
		A.y = 20;
		System.out.println("............1.............");
		System.out.printf("x= %d,y=%d\n",A.x,A.y);
		seap(A);
		System.out.printf("\n");
		System.out.println("............2.............");
		System.out.printf("x= %d,y=%d\n",A.x,A.y);		
	}
	
	public static void seap(DataBank B)
	{
		int tmp = B.x;
		B.x = B.y;
		B.y = tmp;
		System.out.printf("swap方法內容 x= %d y= %d",B.x,B.y);
	}
	
	

}
