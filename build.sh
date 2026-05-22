#!/usr/bin/env bash

set -e

CC=gcc
ASM=0
OUTPUT=""
HAS_OUTPUT=0

# Learning-oriented compiler flags
CFLAGS=(
    -O0
    -g3
    -fno-omit-frame-pointer
    -fno-inline
    -fno-builtin
    -Wall
    -Wextra
    -Wpedantic
    -masm=intel
)

LDFLAGS=(
    -no-pie
)

ARGS=()
SRC_FILES=()

while [[ $# -gt 0 ]]; do
    case "$1" in
        -S|--asm)
            ASM=1
            shift
            ;;
        -o)
            HAS_OUTPUT=1
            OUTPUT="$2"
            ARGS+=("$1" "$2")
            shift 2
            ;;
        *.c)
            SRC_FILES+=("$1")
            ARGS+=("$1")
            shift
            ;;
        *)
            ARGS+=("$1")
            shift
            ;;
    esac
done

# If no -o specified, infer output name
if [[ $HAS_OUTPUT -eq 0 ]]; then
    if [[ ${#SRC_FILES[@]} -eq 1 ]]; then
        base="${SRC_FILES[0]%.c}"
        OUTPUT="$base"
        ARGS+=("-o" "$OUTPUT")
    fi
fi

# Compile normally
$CC "${CFLAGS[@]}" "${ARGS[@]}" "${LDFLAGS[@]}"

# Optionally generate assembly
if [[ $ASM -eq 1 ]]; then
    for src in "${SRC_FILES[@]}"; do
        base="${src%.c}"
        $CC "${CFLAGS[@]}" -S -fverbose-asm "$src" -o "$base.s"
    done
fi
