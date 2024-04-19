# avxtest

```bash
gcc -O2 avx.c -o avx
./avx
## OR to launch multiple threads:
for i in $(seq 1 5); do ./avx & done
## Kill with:
killall avx
```
