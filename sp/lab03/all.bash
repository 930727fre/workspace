# dd if=/dev/zero of=1mb_file_for_buffSize100 bs=100 count=10485
# dd if=/dev/zero of=50mb_file_for_buffSize100 bs=100 count=524288
# dd if=/dev/zero of=500mb_file_for_buffSize100 bs=100 count=5242880
# dd if=/dev/zero of=1mb_file_for_buffSize4096 bs=4096 count=256
# dd if=/dev/zero of=50mb_file_for_buffSize4096 bs=4096 count=12800
# dd if=/dev/zero of=500mb_file_for_buffSize4096 bs=4096 count=128000
# dd if=/dev/zero of=1mb_file_for_buffSize8192 bs=8192 count=128
# dd if=/dev/zero of=50mb_file_for_buffSize8192 bs=8192 count=6400
# dd if=/dev/zero of=500mb_file_for_buffSize8192 bs=8192 count=64000
# dd if=/dev/zero of=1mb_file_for_buffSize16384 bs=16384 count=64
# dd if=/dev/zero of=50mb_file_for_buffSize16384 bs=16384 count=3200
# dd if=/dev/zero of=500mb_file_for_buffSize16384 bs=16384 count=32000

# dd if=/dev/zero of=512mb_file1 bs=4096 count=131072
# dd if=/dev/zero of=512mb_file2 bs=4096 count=131072
# dd if=/dev/zero of=512mb_file3 bs=4096 count=131072
dd if=/dev/zero of=512mb_file4 bs=4096 count=131072

