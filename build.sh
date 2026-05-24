#!/usr/bin/env bash

set -euo pipefail

CC=${CC:-gcc}
ASM=0
OUTPUT=""

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
    -lm
)

INPUTS=()
EXTRA_ARGS=()

is_build_input() {
    case "$1" in
        *.c|*.o|*.a|*.so)
            return 0
            ;;
        *)
            return 1
            ;;
    esac
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        -S|--asm)
            ASM=1
            shift
            ;;

        -o)
            if [[ $# -lt 2 ]]; then
                echo "error: -o requires an output filename" >&2
                exit 1
            fi
            OUTPUT=$2
            shift 2
            ;;

        --output)
            if [[ $# -lt 2 ]]; then
                echo "error: --output requires an output filename" >&2
                exit 1
            fi
            OUTPUT=$2
            shift 2
            ;;

        --output=*)
            OUTPUT=${1#--output=}
            shift
            ;;

        *)
            if is_build_input "$1"; then
                INPUTS+=("$1")
            else
                EXTRA_ARGS+=("$1")
            fi
            shift
            ;;
    esac
done

shopt -s nullglob

# Automatic mode:
# If no explicit input files were given, use files from the current directory.
if [[ ${#INPUTS[@]} -eq 0 ]]; then
    C_SOURCES=(./*.c)
    OBJECTS=()
    STATIC_LIBS=(./*.a)
    SHARED_LIBS=(./*.so)

    # Include .o files, but avoid foo.o when foo.c also exists.
    # Otherwise gcc foo.c foo.o usually causes duplicate symbol errors.
    for obj in ./*.o; do
        matching_c="${obj%.o}.c"

        if [[ -e "$matching_c" ]]; then
            continue
        fi

        OBJECTS+=("$obj")
    done

    INPUTS=(
        "${C_SOURCES[@]}"
        "${OBJECTS[@]}"
        "${STATIC_LIBS[@]}"
        "${SHARED_LIBS[@]}"
    )

    if [[ -z "$OUTPUT" ]]; then
        OUTPUT=$(basename "$PWD")
    fi
fi

if [[ ${#INPUTS[@]} -eq 0 ]]; then
    echo "error: no .c, .o, .a, or .so files found" >&2
    exit 1
fi

# If input files were given explicitly and no output was specified,
# preserve the old behavior: name the binary after the first .c file.
if [[ -z "$OUTPUT" ]]; then
    OUTPUT=$(basename "$PWD")

    for src in "${INPUTS[@]}"; do
        if [[ "$src" == *.c ]]; then
            base=$(basename "$src")
            OUTPUT="${base%.c}"
            break
        fi
    done
fi

$CC "${CFLAGS[@]}" "${EXTRA_ARGS[@]}" "${INPUTS[@]}" -o "$OUTPUT" "${LDFLAGS[@]}"

if [[ $ASM -eq 1 ]]; then
    for src in "${INPUTS[@]}"; do
        if [[ "$src" == *.c ]]; then
            base="${src%.c}"
            $CC "${CFLAGS[@]}" "${EXTRA_ARGS[@]}" -S -fverbose-asm "$src" -o "$base.s"
        fi
    done
fi
