package ch17_16_一個類別中有方法需將介面傳入_當new時_可以使用三種方法;



interface House{
	void houseStyle();
}

abstract class CShape{
	protected String color;
	public CShape() {
		color = "Black";
	}
	public void setColor(String color) {
		this.color = color;
	}
	public abstract void show();
}

class HouseClass implements House{

	@Override
	public void houseStyle() {
		System.out.println("Myclass houseStyle is old");
		
	}
	
}


class MyClass implements House{

	@Override
	public void houseStyle() {
		System.out.println("Myclass house type");
		
	}
}	
class HouseType extends CShape implements House{
	public int price = 100;
	private String houseType;
	
	public HouseType() {
		houseType = "This is a new house";
	}
	
	public HouseType(String type) {
		houseType = type;
	}

	@Override
	public void houseStyle() {
		System.out.println("This house type is :" + houseType);
		
	}

	@Override
	public void show() {
		System.out.println(" ");
		System.out.println("house type : color =" + color);
		
	}
	
	public void show(House style) {
		
		style.houseStyle();
		
	}
	
}

public class ch17_16 {

	public static void main(String[] args) {
		
		System.out.println("................1..................");
		HouseType house = new HouseType();
		house.show();
		house.setColor("white");
		house.show();
		
		System.out.println("................2..................");
		house = new HouseType() {
			public void show() {
				System.out.println("This is a new show()");
			}
		};
		house.show();
		
		////////////////////////////////////////////////////
		
		// 第一種
		System.out.println("................3..................");
		
		HouseType house1 = new HouseType();
		house1.show(new MyClass());
		
		//第二種
		System.out.println("................4..................");
		HouseType house2 = new HouseType();
		House newHouse = new MyClass();
		house2.show(newHouse);
		
		//第三種
		System.out.println("................5..................");
		HouseType house3 = new HouseType();
		house3.show(new House() {

			@Override
			public void houseStyle() {
				System.out.println("finally the house style");
				
			}
			
		});
		house3.show(new House() {

			@Override
			public void houseStyle() {
				System.out.println("finally the house style1");
				
			}
			
		});

	}

}
