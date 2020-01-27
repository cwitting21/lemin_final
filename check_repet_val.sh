#!/bin/sh

./lem-in < "$1" |  awk '{ print $3 }' > repet_val.txt
sort repet_val.txt | uniq -c > sort.txt
cat sort.txt | awk '{ if ($1 != "1") print}'
