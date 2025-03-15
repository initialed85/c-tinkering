#!/bin/bash

set -e

docker run --rm -it -v "$(pwd):/srv/" --workdir /srv/ silkeh/clang bash -c 'clang --version ; clang -o main main.c malloc_intercept.c -Wl,--wrap,malloc,--wrap,realloc,--wrap,free && ./main'
