package test08_3_03;




class CBox{
	
	public static double length;
	public static double width;
	public static double height;
	 
	 
	 double volume()
	 {
		 return length*width*height;
	 }
	 
	 double surfaceArea()
	 {
		 return length*width;
	 }
	 void showData()
	 {
		 System.out.printf("length=%.2f width=%.2f height=%.2f\n" ,length,width,height);
	 }
	 void showAll()
	 {
		 System.out.printf("體積=%.2f\n",volume());
		 System.out.printf("面積=%.2f\n",surfaceArea());
		 showData();
	 }
}

public class test08_3_03 {

	public static void main(String[] args) {
		CBox box = new CBox();
		
		
		box.length = 3;
		box.width = 4;
		box.height = 5;
		System.out.printf("體積%.2f\n",box.volume());
		System.out.println("..................................");
		System.out.printf("面積%.2f\n",box.surfaceArea());
		System.out.println("..................................");
		box.showData();
		System.out.println("..................................");
		box.showAll();
		System.out.println("..................................");
	}

}
