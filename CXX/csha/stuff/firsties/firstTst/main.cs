using System;
namespace printHello {
    public class TEST {
	int inttst;
	double doubletst;
	string strtst;
	
	public TEST (int x, double y, string z){
	    inttst = x;
	    doubletst = y;
	    strtst = z;	
	}
	
	class printHello {
	    public static void Main(string[] args) {
		TEST classTest = new TEST(1, 4.56849650458698564, "TUAMAMMA");
		Console.WriteLine("Hello world!");
		Console.WriteLine(classTest.inttst + " " + " " + classTest.doubletst + " " + classTest.strtst);
	    }
	}
    }
}
