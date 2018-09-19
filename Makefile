include makehead

SRC		=	.

ARCH	= 	x86

CFLAGS	=	-Iinc -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -s -std=c99 -fno-stack-protector

KERNEL_DIR	=	./src/kernel
KERNEL_SRC	=	$(wildcard $(KERNEL_DIR)/*.c) $(wildcard $(KERNEL_DIR)/*/*.c) $(wildcard $(KERNEL_DIR)/*/*/*.c)

LDFLAGS		=	-ffreestanding -mcmodel=large -z max-page-size=0x1000 -nostdlib -T kernel.ld
all:link

link: src/kernel/kernel.o src/arch/$(ARCH)_arch.o $(KERNEL_SRC)

	@echo -e "\033[32m  \033[1mCC\033[21m    \033[34mmultiboot\033[0m"
	@echo $(NASM) -f elf64 -o multiboot.o multiboot/multiboot.asm
	@$(NASM) -f elf64 -o multiboot/multiboot.o multiboot/multiboot.asm

	@echo $(LD) -m elf_x86_64 -T kernel.ld -o kernel_$(ARCH) arch/$(ARCH)_arch.o src/kernel.o
	@$(CC) $(LDFLAGS) -o kernel_$(ARCH) src/kernel.o arch/$(ARCH)_arch.o symbols.o multiboot/multiboot.o

	@echo -e "\033[32m  \033[1mScript\033[21m    \033[34m symbols\033[0m"
	@scripts/symbols > symbols.c
	@echo -e "\033[32m  \033[1mBuild\033[21m    \033[34m symbols\033[0m"
	@$(CC) $(CFLAGS) -c -o symbols.o symbols.c
	#@$(LD) -m elf_x86_64 -T kernel.ld -o kernel_$(ARCH) arch/$(ARCH)_arch.o src/kernel.o symbols.o

	@$(CC) $(LDFLAGS) -o kernel_$(ARCH) src/kernel.o arch/$(ARCH)_arch.o symbols.o multiboot/multiboot.o
	@cp kernel_$(ARCH) run/iso/boot/kernel
	@grub-mkrescue -o run/myos.iso run/iso/

src/kernel/kernel.o:
	@echo -e "\033[32m  \033[1mBUILD\033[21m    \033[34m kernel\033[0m"
	@cd src; make CC=$(CC) ARCH=$(ARCH)

src/arch/$(ARCH)_arch.o:
	@echo -e "\033[32m  \033[1mBUILD\033[21m    \033[34m $(ARCH)\033[0m"
	@cd arch; $(MAKE) CC=$(CC) ARCH=$(ARCH)

run:
	@qemu-system-i386 -cdrom run/myos.iso -m 50m -fda disk.img -boot c

bochs:
	@bochs -q -f run/c

build_run:
	@make -B
	@bochs -q -f run/c
clean:
	@rm -f arch/build/*
	@rm -f arch/*_arch.o
	@rm -f src/build/*
	@rm -f src/kernel.o
