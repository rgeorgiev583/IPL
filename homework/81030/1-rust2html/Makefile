PROGRAM_NAME := rust2html

LEX := flex

.PHONY: all clean

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): lex.yy.c
	$(CC) -o $@ $<

lex.yy.c: $(PROGRAM_NAME).l
	$(LEX) $<

clean:
	$(RM) $(PROGRAM_NAME) lex.yy.c example.html
