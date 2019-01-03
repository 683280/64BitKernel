include ../makehead

SRC		=	.

C_SRCS	=	$(wildcard $(SRC)/*.c) $(wildcard $(SRC)/*/*.c) $(wildcard $(SRC)/*/*/*.c)
A_SRCS	=	$(wildcard $(SRC)/*.asm) $(wildcard $(SRC)/*/*.asm)

C_OBJ	=	$(patsubst %.c,%.o,$(C_SRCS))
A_OBJ	=	$(patsubst %.asm,%.ao,$(A_SRCS))

OBJS	=	$(foreach file,$(notdir $(C_OBJ)),build/$(file)) $(foreach file,$(notdir $(A_OBJ)),build/$(file))

CFLAGS	=	-I../inc -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -O2 -mno-sse -mno-sse2 -s -std=c99 -fno-stack-protector

all:link

link: $(ARCH)_arch.o
	@echo -e "\033[32m  \033[1mLD\033[21m    \033[34mx86_arch.o\033[0m"
	@echo $(LD) -m elf_x86_64 -r -o x86_arch.o $(OBJS)
	@$(LD) -m elf_x86_64 -r -o x86_arch.o $(OBJS)

$(ARCH)_arch.o: $(C_OBJ) $(A_OBJ)

$(C_OBJ): %.o: %.c
	@echo -e "\033[32m  \033[1mCC\033[21m    \033[34m$<\033[0m"
	@echo $(CC) $(CFLAGS) -c -o $@ $<
	@$(CC) $(CFLAGS) -c -o build/$(notdir $@) $<

$(A_OBJ): %.ao: %.asm
	@echo -e "\033[32m  \033[1mCC\033[21m    \033[34m$<\033[0m"
	@echo $(CC) $(CFLAGS) -c -o $@ $<
	@$(NASM) -f elf64 -o build/$(notdir $@) $<

clean:
	@rm -f $(C_OBJ)
	@rm -f $(A_OBJ)