package token

const (
	ILLEGAL = "ILLEGAL"
	EOF     = "EOF"

	//Identifiers and literals
	IDENTIFIER = "IDENTIFIER"
	INT        = "INT"

	//Operators
	ASSIGN       = "="
	PLUS         = "+"
	MINUS        = "-"
	BANG         = "!"
	ASTERISK     = "*"
	SLASH        = "/"
	LESS_THAN    = "<"
	GREATER_THAN = ">"
	EQUALS       = "=="
	NOT_EQUALS   = "!="

	//Delimiters
	COMMA     = ","
	SEMICOLON = ";"
	RPAREN    = "("
	LPAREN    = ")"
	RBRACE    = "{"
	LBRACE    = "}"

	//Keywords
	FUNCTION = "FUNCTION"
	LET      = "LET"
	IF       = "if"
	ELSE     = "else"
	RETURN   = "return"
	TRUE     = "true"
	FALSE    = "false"
)

var keywords = map[string]TokenType{
	"fn":     FUNCTION,
	"let":    LET,
	"if":     IF,
	"else":   ELSE,
	"return": RETURN,
	"true":   TRUE,
	"false":  FALSE,
}

func LookupIdentifier(identifier string) TokenType {
	if tokenType, ok := keywords[identifier]; ok {
		return tokenType
	}
	return IDENTIFIER
}

type TokenType string

type Token struct {
	Type    TokenType
	Literal string
}
