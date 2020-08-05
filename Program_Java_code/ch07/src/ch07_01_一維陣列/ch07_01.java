package ch07_01_一維陣列;

public class ch07_01 {

	public static void main(String[] args) {

		double deg1 = 25, deg2 = 22, deg3 = 24, deg4 = 20;
		double average1;
		average1 = (deg1 + deg2 + deg3 + deg4) / 4;
		System.out.println("平均溫度" + average1);

		// array
		// 三種宣告

		// 第一種
//		double[] degree2;
//		degree2 = new double[4];

		// 第二種
		double[] degree2 = new double[4];

		degree2[0] = 25;
		degree2[1] = 22;
		degree2[2] = 24;
		degree2[3] = 20;

		// 修改
		// degree2[3]=100;

		double total2 = 0;
		double average2 = 0;

		// 走訪使用for
		for (int i = 0; i < 4; i++) {
			System.out.println(degree2[i]);// degree2[0] degree2[1] degree2[2] degree2[3]
			total2 += degree2[i];// total2 = total2 + degree2[i];
		}

		average2 = total2 / degree2.length;// total2/4
		System.out.println("平均溫度" + average2);

		// 第三種
		double[] degree3 = { 25, 22, 24, 20 };

		// 修改
		degree3[0] = 0;

		// 走訪for
		for (int i = 0; i < 4; i++) {
			System.out.println(degree3[i]);
		}

		double total3 = 0;
		double average3 = 0;
		// 走訪foreach
		for (double element : degree3) {
			System.out.println(element);
			total3 += element; // total3 = total3 + element;
		}

		average3 = total3 / degree3.length;// total3/4
		System.out.println("平均溫度" + average3);
		
///////////////////////////////////////////////
	}
}