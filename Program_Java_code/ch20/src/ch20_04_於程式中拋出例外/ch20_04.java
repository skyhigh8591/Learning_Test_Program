package ch20_04_��{�����ߥX�ҥ~;

public class ch20_04 {

	public static void pwdCheck(String pwdStr) {

		if (pwdStr.length() >= 5 && pwdStr.length() <= 8) {
			System.out.println("�K�X�榡���T" + pwdStr);
		} else {
			System.out.println("�K�X�榡���~" + pwdStr);
			throw new StringIndexOutOfBoundsException("�K�X���פ��ŦX");
		}
	}

	public static void main(String[] args) {
		String[] pwd = { "123456", "3456766", "2212434" };
		for (int i = 0; i < pwd.length; i++) {
			try {
				pwdCheck(pwd[i]);
			} catch (StringIndexOutOfBoundsException e) {
				System.out.println("�K�X���פ��ŦX");
			}
		}
	}

}
