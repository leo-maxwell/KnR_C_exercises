SHELL := /bin/bash

CC ?= gcc
ASM ?= 0

CFLAGS := \
	-O0 \
	-g3 \
	-fno-omit-frame-pointer \
	-fno-inline \
	-fno-builtin \
	-Wall \
	-Wextra \
	-Wpedantic \
	-masm=intel

LDFLAGS := \
	-no-pie

LDLIBS := \
	-lm

.PHONY: usage clean FORCE
.DEFAULT_GOAL := usage

usage:
	@echo "usage:"
	@echo "  make exercise_x-y"
	@echo "  make exercise_x-y ASM=1"
	@echo "  make clean"

exercise_%: FORCE
	@target="$@"; \
	if [[ "$$target" != exercise_[0-9]*-[0-9]* ]]; then \
		echo "error: target must look like exercise_x-y, for example exercise_4-12" >&2; \
		exit 1; \
	fi; \
	if [[ "$(ASM)" != "0" && "$(ASM)" != "1" ]]; then \
		echo "error: ASM must be either 0 or 1" >&2; \
		exit 1; \
	fi; \
	stem="$${target#exercise_}"; \
	chapter="$${stem%%-*}"; \
	chapter_dir="chapter_$$chapter"; \
	single="$$chapter_dir/$$target.c"; \
	multi="$$chapter_dir/$$target"; \
	out="$$target.out"; \
	if [[ -f "$$single" && -d "$$multi" ]]; then \
		echo "error: ambiguous exercise '$$target'" >&2; \
		echo "both '$$single' and '$$multi/' exist" >&2; \
		exit 1; \
	elif [[ -f "$$single" ]]; then \
		echo "building $$single -> $$out"; \
		$(CC) $(CFLAGS) "$$single" -o "$$out" $(LDFLAGS) $(LDLIBS); \
		if [[ "$(ASM)" == "1" ]]; then \
			asm="$$target.s"; \
			echo "generating $$asm"; \
			$(CC) $(CFLAGS) -S -fverbose-asm "$$single" -o "$$asm"; \
		fi; \
	elif [[ -d "$$multi" ]]; then \
		shopt -s nullglob; \
		sources=( "$$multi"/*.c ); \
		if (( $${#sources[@]} == 0 )); then \
			echo "error: no .c files found under '$$multi/'" >&2; \
			exit 1; \
		fi; \
		echo "building $$multi/*.c -> $$out"; \
		$(CC) $(CFLAGS) "$${sources[@]}" -o "$$out" $(LDFLAGS) $(LDLIBS); \
		if [[ "$(ASM)" == "1" ]]; then \
			for src in "$${sources[@]}"; do \
				base="$${src##*/}"; \
				base="$${base%.c}"; \
				asm="$$target__$$base.s"; \
				echo "generating $$asm"; \
				$(CC) $(CFLAGS) -S -fverbose-asm "$$src" -o "$$asm"; \
			done; \
		fi; \
	else \
		echo "error: cannot find '$$single' or '$$multi/'" >&2; \
		exit 1; \
	fi

clean:
	rm -f -- exercise_*.out exercise_*.s

FORCE:
