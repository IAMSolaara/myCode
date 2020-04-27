package main

import "fmt"
import "math"
import "./testpkg"

func add(x, y int) int {
	return x+y;
}

func main() {
	fmt.Println(math.Pi);
	fmt.Println(Sqrt(2));
}
