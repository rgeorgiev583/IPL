PROGRAM_SOURCE_FILENAMES := $(PROGRAM_NAMES:%=%.lex.yy.c)

LEX := flex

ifdef DEBUG
LEX_FLAGS := -d
CFLAGS += -D_DEBUG
endif

ifdef USE_CXX
CC := $(CXX)
endif

.PHONY: all clean

all: $(PROGRAM_NAMES)

%: %.lex.yy.c
	$(CC) $(CFLAGS) -o $@ $<

%.lex.yy.c: %.l
	$(LEX) $(LEX_FLAGS) -o $@ $<

clean:
	$(RM) $(PROGRAM_NAMES) $(PROGRAM_SOURCE_FILENAMES) lex.yy.c example.html
