package ch14_17_檔案分裝_多層次繼承;

public class Animail {
	protected String name;

	Animail(String name) {
		this.name = name;
	}

	public void eat() {
		System.out.println(name + "正在吃");
	}
}
