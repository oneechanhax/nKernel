#!/bin/bash

if grub-file --is-x86-multiboot ./nkernel-poc; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi
