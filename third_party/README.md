# Third-party code

## zlib 1.2.1

`zlib-1.2.1/` is the zlib 1.2.1 core from the official archive (https://zlib.net/fossils/zlib-1.2.1.tar.gz), which the
game links. Its licence is the zlib licence, in `zlib-1.2.1/README` and `zlib-1.2.1/zlib.h`.

One file is altered: `zlib-1.2.1/inflate.c` carries the game's own changes to `inflateInit2_`, `inflate` and
`inflateEnd`, so that it builds to the same bytes as the game. A note at the top of the file says so. The changes are
also given as a diff against the official file, `patches/zlib-1.2.1-fnv-inflate.patch` (`patch -R` on `inflate.c` gives
the official file back). Every other file is unaltered.

`zlib-1.2.1/UPSTREAM.json` records the archive's SHA-256, the SHA-256 of every file kept, and for `inflate.c` both the
official and the altered file's SHA-256 and the patch's. Platform ports, contributed code and prebuilt objects from the
archive were left out.
