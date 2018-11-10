#! /bin/bash

filename="proc.txt"

while (true)
do
	echo "########" >> $filename
	ps uax >> $filename
	sleep 3
done
exit
