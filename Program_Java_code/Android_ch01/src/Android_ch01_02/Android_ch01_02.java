package Android_ch01_02;

interface House {
	public void houseStyle();
}

class HouseClass implements House {
	public void houseStyle() {
		System.out.println("The current houseStyle is old.");
	}
}

abstract class CShape {
	protected String color;

	public CShape() {
		color = "black";
	}

	public void setColor(String color) {
		this.color = color;
	}

	public void show() {

	}
}

class HouseType extends CShape implements House {
	private String houseType;

	public HouseType() {
		houseType = "apartment";
	}

	public HouseType(String type) {
		houseType = type;
	}

	@Override
	public void houseStyle() {
		System.out.println("This house type is : " + houseType);
	}

	@Override
	public void show() {

		System.out.println("House type color = " + super.color);
		houseStyle();
		System.out.println(" ");
	}

	public void show(House style) {
		style.houseStyle();
		System.out.println(" ");
	}

}

public class Android_ch01_02 {

	public static void main(String[] args) {
		HouseClass typel = new HouseClass();
		typel.houseStyle();

		System.out.println(" ");
		HouseClass type2 = new HouseClass() {
			@Override
			public void houseStyle() {
				System.out.println("The house Style is a new design.");
				System.out.println(" ");
			}

		};
		type2.houseStyle();

		HouseType house1 = new HouseType();
		house1.show();
		house1.setColor("White");
		house1.show();

		house1 = new HouseType() {

			@Override
			public void show() {

				System.out.println("House color = Blue");
				System.out.println("This house type is : villa");
			}

			@Override
			public void houseStyle() {

				System.out.println("This house type is masion");
				System.out.println(" ");
			}

		};
		house1.show();
		house1.houseStyle();

		CShape house2 = new HouseType("h2 - house");
		house2.setColor("green");
		house2.show();

		House house3 = new HouseType("h3 - building");
		house3.houseStyle();
		System.out.println(" ");

		HouseType house4 = new HouseType("h4 - mansion");
		house4.show();
		house4.show(house3);

		house4.show(typel);
		house4.show(type2);

		house4.show(new House() {

			@Override
			public void houseStyle() {
				System.out.println("This is a new House style.");
			}
		});
		
		house4.show(new MyClass());
		
	}
	
	private static class MyClass implements House{
		
		
		public MyClass() {
			
		}
		
		@Override
		public void houseStyle() {
			System.out.println("MyClass House type.");
			
		}
		
	}

}
