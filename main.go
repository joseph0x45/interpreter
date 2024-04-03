package main

import (
	"fmt"
	"monkey/repl"
	"os"
	"os/user"
)

func main() {
	user, err := user.Current()
	if err != nil {
		panic(err)
	}
	fmt.Printf("Hello %s, welcome to the Monkey programming language!\n", user.Username)
	fmt.Println("Feel free to type in Monkey code")
	repl.Start(os.Stdin, os.Stdout)
}
