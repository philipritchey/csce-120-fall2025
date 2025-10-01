# nothing goes wrong
./a.out censorwords.txt input.txt censored.txt

# cannot open a file
touch locked
chmod u-rw locked
./a.out does_not_exist input.txt censored.txt
./a.out censorwords.txt does_not_exist censored.txt
./a.out locked input.txt censored.txt
./a.out censorwords.txt locked locked
./a.out censorwords.txt input.txt locked

# get input file stream into a fail state (empty line at end of file)
./a.out censorwords.txt empty_line.txt censored.txt