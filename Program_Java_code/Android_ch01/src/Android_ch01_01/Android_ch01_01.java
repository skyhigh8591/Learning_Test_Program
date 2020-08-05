package Android_ch01_01;

class CShape
{
	private String color;
	public CShape()
	{
		color = "black";
	}
	
	public CShape(String color)
	{
		this.color = color;
	}
	
	public void show()
	{
		System.out.println("the CShape color = " + color);
	}
	
	public void show(String data , String color) {
		this.color = color;
		System.out.println(data + " = " + color);
	}
	
	public String getCShapeColor() {
		return color;
	}
}

class CCircle extends CShape
{
	private String color , cShapeColor;
	private double radius;
	private double pi = 3.14;
	
	public CCircle()
	{
		radius = 1.0;
		color = "yellow";
		cShapeColor = super.getCShapeColor();
		System.out.println("CCircle color = " + color + ", radius = " + radius);
		System.out.println("CShape color = " + cShapeColor);
		System.out.println(" ");
		
	}
	
	public CCircle(double r)
	{
		radius = r;
	}
	
	public CCircle(String color , double r)
	{
		this.color = color;
		radius = r;
		System.out.println("CCircle color = " + color + ", radius = " + radius);
	}
	
	public void setCircle(String color)
	{
		this.color = color;
		System.out.println("Circle color" + color);
		cShapeColor = super.getCShapeColor();
		System.out.println("Parent 's color = " + cShapeColor);
		
	}
	public void setRadius(double r)
	{
		radius = r;
		System.out.println("Circle radius = " + radius);
		System.out.println(" ");
	}
	
	public void compare(CCircle cir) {
		System.out.println("My radius = " + this.radius);
		System.out.println("Object 's radius = " + cir.radius);
		if(this.radius == cir.radius) {
			System.out.println("Radius is equal.");
			System.out.println(" ");
		}else {
			System.out.println("Radius is not equal.");
			System.out.println(" ");
		}
	}
	
	public double area() {
		return pi*radius*radius;
	}
	
	
}

public class Android_ch01_01 {

	public static void main(String[] args) {
		CShape myShape = new CShape();
		myShape.show();
		
		myShape = new CShape("green");
		myShape.show();
		
		myShape.show("set new color = " , "red");
		myShape.show();
		
		System.out.println(" ");
		
		CCircle cir1 = new CCircle();
		cir1.show();
		
		String colorData = cir1.getCShapeColor();
		System.out.println("colorData = " + colorData);
		
		cir1.show("Set new color" , "white");
		cir1.show();
		
		
		
		colorData = cir1.getCShapeColor();
		System.out.println("colorData = " + colorData);
		
		cir1.setCircle("orange");
		cir1.show();
		
		CCircle cir2 = new CCircle("blue",4.0);
		cir2.show();
		
		cir2.compare(cir1);
		
		cir1 = new CCircle(5.0);
		cir2 = new CCircle(2.0);
		cir1.compare(cir2);
		
		cir1.compare(new CCircle(3.0));
		cir2.compare(new CCircle(2.0));
		
		double value = cir1.area();
		System.out.println("cir 1 area = " + value);
		
		
		value = cir2.area();
		System.out.println("cir 2 area = " + value);
	}

}
