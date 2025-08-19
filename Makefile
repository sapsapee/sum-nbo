all: sum-nbo

sum-nbo: sum-nbo.c
	gcc -o sum-nbo sum-nbo.c

clean:
	rm -f sum-nbo

test: sum-nbo
	echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
	echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
	echo -n -e \\x00\\x00\\x00\\xc8 > two-hundred.bin
	./sum-nbo thousand.bin five-hundred.bin two-hundred.bin
	rm -f thousand.bin five-hundred.bin two-hundred.bin
