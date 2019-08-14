package com.mentalabs;

public class Calc {
    private double x;
    private double y;
    private String op;
    private double result;
    public Calc(){
	this.x = 0;
	this.y = 0;
    }
    public void setX(double in) {
	this.x = in;
    }
    public void setY(double in) {
	this.y = in;
    }
    public void setOp(String in) {
	this.op = in;
    }
    public void getX(double in) {
	return x;
    }
    public void getY(double in) {
	return y;
    }
    public void getOp(String in) {
	return op;
    }
    
    public void calcRun() {
	switch (op) {
	case "+":
	    result = x + y;
	    break;
	    
	case "-":
	    result = x - y;
	    break;
	    
	case "*":
	    result = x * y;
	    break;
	    
	case "/":
	    result = x / y;
	    break;
	    
	default:
	    System.out.println("No recognized operand.");
	    break;
	}
    }
    public double getResult() {
	return result;
    }
}
    
