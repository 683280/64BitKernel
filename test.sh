if grub-file --is-x86-multiboot kernel_x86; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
