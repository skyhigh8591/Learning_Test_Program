package ch17_14_°Î¦WÃþ§OAnonymous;

interface House{
	public void houseStyle();
}

class HouseCalss implements House{

	@Override
	public void houseStyle() {
		System.out.println("The current houseStyle is old.");		
	}	
}

class Test extends HouseCalss{
	@Override
	public void houseStyle() {
		System.out.println("The current houseStyle is new design.");		
	}	
}
public class ch17_14 {

	public static void main(String[] args) {
		System.out.println(".............1..................");	
		HouseCalss h = new HouseCalss();
		h.houseStyle();
		
		System.out.println(".............2..................");	
		Test t = new Test();
		t.houseStyle();
		System.out.println(".............3..................");	
		HouseCalss type = new HouseCalss() {
			public void houseStyle() {
				System.out.println("The current houseStyle is new design.");	
			}		
		};
		
		type.houseStyle();

	}

}
