package repl

import (
	"bufio"
	"fmt"
	"io"
	"monkey/lexer"
	"monkey/token"
)

const PROMPT = ">> "

func Start(in io.Reader, out io.Writer) {
	scanner := bufio.NewScanner(in)
	for {
		fmt.Print(PROMPT)
		scanned := scanner.Scan()
		if !scanned {
			return
		}
		line := scanner.Text()
		lexer := lexer.NewLexer(line)
		for t := lexer.NextToken(); t.Type != token.EOF; t = lexer.NextToken() {
			fmt.Printf("%+v\n", t)
		}
	}
}
