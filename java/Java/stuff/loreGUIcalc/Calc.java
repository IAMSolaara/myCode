package com.mentalabs;

/**
 * @author lorecast162
 * @version 1.0
 */

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
    public double getX() {
	return this.x;
    }
    public double getY() {
	return this.y;
    }
    public String getOp() {
	return this.op;
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
    
