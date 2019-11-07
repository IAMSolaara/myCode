

public class main {
    public static void main(String[] args){
	class1 test = new class1(123, 54353.345345f);
	System.out.println(test.x);
	System.out.println(test.y);
	System.out.println(test.class1Ret());
	System.out.println(test.class2Ret());
    }
}

public class class1 {
    int x;
    float y;
    public class1(int arg1, float arg2){
	this.x = arg1;
	this.y = arg2;
    }
    public int class1Ret(){
	return x;
    }
    public float class2Ret(){
	return y;
    }
}
