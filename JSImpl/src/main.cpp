#include "Lexer.h"
#include "Parser.h"
#include "ASTPrinter.h"
#include <iostream>
#define LOG(msg) std::cout << msg << std::endl
#define EXECUTE_TEST(test) std::cout << #test << " "; test();
#define CHECK(cond)	if (cond) {LOG("PASS");} else {LOG(#cond " FAIL");}

// Lexer Tests
void TestLess()
{
	auto tokens = Tokenize("<");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::Less);
}

void TestNumber()
{
	auto tokens = Tokenize("213434.24");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::Number && tokens[0].Number == 213434.24);
}

void TestNumberStartWithNine()
{
	auto tokens = Tokenize("999");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::Number && tokens[0].Number == 999);
}

void TestNumberStartWithZero()
{
	auto tokens = Tokenize("0999");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::Number && tokens[0].Number == 999);
}

void TestSpaceNewLineSpace()
{
	auto tokens = Tokenize(" \n var a = 4;");
	CHECK(tokens.size() == 6 && tokens[0].Type == TokenType::Var &&
		tokens[1].Type == TokenType::Identifier &&
		tokens[2].Type == TokenType::Equal &&
		tokens[3].Type == TokenType::Number &&
		tokens[4].Type == TokenType::Semicolon);
}

void TestString()
{
	auto tokens = Tokenize("\"alabala\"");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::String && tokens[0].Lexeme == "\"alabala\"");
}

void TestStringSingleQuotedStrings()
{
	auto tokens = Tokenize("'alabala'");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::String && tokens[0].Lexeme == "'alabala'");
}

void TestKeyWord()
{
	auto tokens = Tokenize("for");
	CHECK(tokens.size() == 2 && tokens[0].Type == TokenType::For);
}

void TestVariableDeclaration()
{
	auto tokens = Tokenize("var pesho = 10");
	CHECK(tokens.size() == 5 && tokens[0].Type == TokenType::Var
		&& tokens[1].Type == TokenType::Identifier
		&& tokens[2].Type == TokenType::Equal
		&& tokens[3].Type == TokenType::Number
		&& tokens[4].Type == TokenType::Eof);
}
// Parser Tests
void TestParseUnaryExpr()
{
	// TODO make actual test :D
	auto expr = Parse(Tokenize("function pesho(v1) { var a = 0; return a; }"));
	ASTPrinter p(std::cout);
	expr->Accept(p);
}

int main()
{
	//EXECUTE_TEST(TestLess);
	//EXECUTE_TEST(TestNumber);
	//EXECUTE_TEST(TestNumberStartWithNine);
	//EXECUTE_TEST(TestNumberStartWithZero);
	//EXECUTE_TEST(TestString);
	//EXECUTE_TEST(TestSpaceNewLineSpace);
	//EXECUTE_TEST(TestStringSingleQuotedStrings);
	//EXECUTE_TEST(TestKeyWord);
	//EXECUTE_TEST(TestVariableDeclaration);


	TestParseUnaryExpr();
#if defined(_WIN32)
	//std::system("pause");
#endif
	return 0;
}