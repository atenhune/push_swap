#!/usr/bin/env python3

import sys
import os.path
import os
from os import path
import random
import subprocess

randomNumbers = []

def	main():
	nbrCount = int(sys.argv[1])
	randomNumbers = (random.sample(range(nbrCount * 10), nbrCount))
	arguments = ""
	for nbr in randomNumbers:
		arguments += (str(nbr)) + " "
	# os.system("./push_swap %s" % (arguments))
	# output = ""
	output = str(subprocess.check_output(["./push_swap", arguments]))
	output = output.replace("\\n", " ")
	output = output.replace("b'", "")
	output = output.replace("'", "")
	output = output.split(" "
	for cmd in output:
		print(cmd)
	# print(output)


if __name__ == "__main__":
	main()