package testpkg

import (
	"fmt"
	"runtime"
)

func main() {
	os := runtime.GOOS
	fmt.Printf("Go runs on %s.\n", os)
}

