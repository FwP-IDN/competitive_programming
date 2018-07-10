class A {
	private int k = 12;

	public A() {
		System.out.println("A");
	}

	void k() {
		System.out.println(k);
	}
}

class B extends A {
	public B() {
		System.out.println("B");
	}
}

class C extends B {
	public C() {
		System.out.println("C");
		super.k();
	}
}

public class Main {
	public static void main(String[] args) {
		A s = new C();
		s.k();
	}
}