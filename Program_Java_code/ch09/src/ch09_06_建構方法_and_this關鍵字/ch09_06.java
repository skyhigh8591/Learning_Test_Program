package ch09_06_�غc��k_and_this����r;

class NBAPlayers {
	int age = 28;
	String name;


	NBAPlayers(String name) {
		this.name = name;
	}

	NBAPlayers(String name ,int age){
		this(name);
		this.age = age;
	}

	void printInfo() {
		System.out.println((name));
		System.out.println((age));
	}
}
public class ch09_06 {
	public static void main(String[] args) {		
		NBAPlayers A = new NBAPlayers("LeBron James" , 30);	
		A.printInfo();
	}
}
