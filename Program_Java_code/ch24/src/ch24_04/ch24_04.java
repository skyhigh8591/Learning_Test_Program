package ch24_04;

import java.util.ArrayList;

abstract class Shapes {								// 抽象類別Shapes
	abstract void demo();							// 抽象方法demo 
}
class Square extends Shapes {						// Square繼承Shapes
	void demo() {
		System.out.println("我是正方形");
	}
}
class Circle extends Shapes {						// Circle繼承Shapes
	void demo() {
		System.out.println("我是圓形");
	}
}

public class ch24_04 {
	public static void main(String[] args) {
		ArrayList<Square> alist1 = new ArrayList<Square>();
		alist1.add(new Square());					// alist1物件元素是Square類別物件
		ArrayList<Circle> alist2 = new ArrayList<Circle>();
		alist2.add(new Circle());					// alist2物件元素是Circle類別物件
		demoShapes(alist1);
		demoShapes(alist2);
	}
	
	//此類別要繼承Shapes且是ArrayList的資料型態
	public static void demoShapes(ArrayList<? extends Shapes> lists) {
		for(Shapes list:lists)
			list.demo();							// 執行demo
	}

}
