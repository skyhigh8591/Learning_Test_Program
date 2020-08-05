package ch04_05_簡潔的運算式;

public class ch04_05 {

	public static void main(String[] args) {
		int num = 1;
		System.out.println("第一次" + num);

		num = num + 1;
		System.out.println("第二次" + num);

		num++;// num = num + 1;
		System.out.println("第三次" + num);

		System.out.println("第四次" + ++num);

		System.out.println("第五次" + num++);

		System.out.println("第六次" + num);

		num--;// num = num - 1;
		System.out.println("第七次" + num);
		
		System.out.println("第八次" + --num);
		
		num += 12; // num = num + 12
		System.out.println("第九次" + num);
		
		num /=14; // num = num / 14 ;
		System.out.println("第十次" + num);

	}

}
