#!/bin/bash

set -e

docker run --rm -it -v $(pwd):/srv/ --workdir /srv/ gcc bash -c 'gcc --version ; gcc -o main main.c malloc_intercept.c -Wl,--wrap,malloc,--wrap,realloc,--wrap,free && ./main'
