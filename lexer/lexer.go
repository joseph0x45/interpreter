package lexer

import (
	"monkey/token"
)

type Lexer struct {
	input        string
	position     int  //Current position in the input, also points to currentChar
	readPosition int  //Current reading position, after currentChar
	currentChar  byte //Current character under examination
}

func NewLexer(input string) *Lexer {
	lexer := &Lexer{
		input: input,
	}
	lexer.readChar()
	return lexer
}

func isLetter(character byte) bool {
	return 'a' <= character && character <= 'z' || 'A' <= character && character <= 'Z' || character == '_'
}

func isDigit(character byte) bool {
	return '0' <= character && character <= '9'
}

func (lexer *Lexer) readChar() {
	if lexer.readPosition >= len(lexer.input) {
		lexer.currentChar = 0
	} else {
		lexer.currentChar = lexer.input[lexer.readPosition]
	}
	lexer.position = lexer.readPosition
	lexer.readPosition += 1
}

func (lexer *Lexer) readIdentifier() string {
	currentPosition := lexer.position
	for isLetter(lexer.currentChar) {
		lexer.readChar()
	}
	return lexer.input[currentPosition:lexer.position]
}

func (lexer *Lexer) readNumber() string {
	currentPosition := lexer.position
	for isDigit(lexer.currentChar) {
		lexer.readChar()
	}
	return lexer.input[currentPosition:lexer.position]
}

func (lexer *Lexer) peekChar() byte {
	if lexer.position >= len(lexer.input) {
		return 0
	} else {
		return lexer.input[lexer.readPosition]
	}
}

func (lexer *Lexer) skipWhitespace() {
	for lexer.currentChar == ' ' || lexer.currentChar == '\t' || lexer.currentChar == '\n' || lexer.currentChar == '\r' {
		lexer.readChar()
	}
}

func newToken(tokenType token.TokenType, character byte) token.Token {
	return token.Token{
		Type:    tokenType,
		Literal: string(character),
	}
}

func (lexer *Lexer) NextToken() token.Token {
	var t token.Token
	lexer.skipWhitespace()
	switch lexer.currentChar {
	case '=':
		if lexer.peekChar() == '=' {
			char := lexer.currentChar
			lexer.readChar()
			t = token.Token{Type: token.EQUALS, Literal: string(char) + string(lexer.currentChar)}
		} else {
			t = newToken(token.ASSIGN, lexer.currentChar)
		}
	case '+':
		t = newToken(token.PLUS, lexer.currentChar)
	case '-':
		t = newToken(token.MINUS, lexer.currentChar)
	case ',':
		t = newToken(token.COMMA, lexer.currentChar)
	case ';':
		t = newToken(token.SEMICOLON, lexer.currentChar)
	case '(':
		t = newToken(token.LPAREN, lexer.currentChar)
	case ')':
		t = newToken(token.RPAREN, lexer.currentChar)
	case '{':
		t = newToken(token.LBRACE, lexer.currentChar)
	case '}':
		t = newToken(token.RBRACE, lexer.currentChar)
	case '/':
		t = newToken(token.SLASH, lexer.currentChar)
	case '!':
		if lexer.peekChar() == '=' {
			char := lexer.currentChar
			lexer.readChar()
			t = token.Token{Type: token.NOT_EQUALS, Literal: string(char) + string(lexer.currentChar)}
		} else {
			t = newToken(token.BANG, lexer.currentChar)
		}
	case '<':
		t = newToken(token.LESS_THAN, lexer.currentChar)
	case '>':
		t = newToken(token.GREATER_THAN, lexer.currentChar)
	case '*':
		t = newToken(token.ASTERISK, lexer.currentChar)
	case 0:
		t.Type = token.EOF
		t.Literal = ""
	default:
		if isLetter(lexer.currentChar) {
			identifier := lexer.readIdentifier()
			t.Type = token.LookupIdentifier(identifier)
			t.Literal = identifier
			return t
		} else if isDigit(lexer.currentChar) {
			digit := lexer.readNumber()
			t.Type = token.INT
			t.Literal = digit
			return t
		} else {
			t = newToken(token.ILLEGAL, lexer.currentChar)
		}
	}
	lexer.readChar()
	return t
}
