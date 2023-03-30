# time ./buffsize100 < 1mb_file_for_buffSize100
# time ./buffsize100 < 50mb_file_for_buffSize100
# time ./buffsize100 < 500mb_file_for_buffSize100

# time ./buffsize4096 < 1mb_file_for_buffSize4096
# time ./buffsize4096 < 50mb_file_for_buffSize4096
# time ./buffsize4096 < 500mb_file_for_buffSize4096

# time ./buffsize8192 < 1mb_file_for_buffSize8192
# time ./buffsize8192 < 50mb_file_for_buffSize8192
# time ./buffsize8192 < 500mb_file_for_buffSize8192

# time ./buffsize16384 <1mb_file_for_buffSize16384
# time ./buffsize16384 <50mb_file_for_buffSize16384
# time ./buffsize16384 <500mb_file_for_buffSize16384

echo --------------
echo part4
time ./buffsize4096 < 512mb_file1
time ./buffsize4096 < 512mb_file2
time ./buffsize4096 < 512mb_file2

echo --------------
echo part5
time ./buffsize4096 < 512mb_file3
time ./buffsize4096 < 512mb_file4
time ./buffsize4096 < 512mb_file4