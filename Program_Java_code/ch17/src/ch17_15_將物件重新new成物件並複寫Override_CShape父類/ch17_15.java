package ch17_15_將物件重新new成物件並複寫Override_CShape父類;

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
	
}

public class ch17_15 {

	public static void main(String[] args) {
		System.out.println("...........1................");
		HouseType house1 =new HouseType();
		house1.show();
		
		System.out.println("...........2................");
		house1 =new HouseType() {
			public void show() {
				System.out.println("This is new new show");
			}
		};
		house1.show();

	}

}
