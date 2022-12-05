#!/usr/bin/env python3

import sys
import os
import random
import subprocess

EOC = "\033[0m"
GREEN = "\033[38;5;70m"
RED  = "\033[38;5;124m"
YELLOW = "\033[38;5;220m"

if len(sys.argv) < 3:
	print(YELLOW + "\nUsage:" + EOC + "\n\t python3 validate_results.py <set_size>  <set_count>\n")
	quit()

numbers = []
stack_a = []
stack_b = []
output = []
nbrCount = int(sys.argv[1])
setCount = int(sys.argv[2])
moveNbr = 0

if nbrCount == 0 or setCount == 0:
	print(YELLOW + "\nUsage:" + EOC + "\n\t python3 validate_results.py <set_size>  <set_count>\n")
	quit()

def doMoves():
	global moveNbr
	global stack_a
	global stack_b
	if moveNbr == len(output):
		return
	if output[moveNbr] == "sa" and len(stack_a) >= 2:
		stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
	if output[moveNbr] == "sb" and len(stack_b) >= 2:
		stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
	if output[moveNbr] == "ss":
		if len(stack_a) >= 2:
			stack_a[0], stack_a[1] = stack_a[1], stack_a[0]
		if len(stack_b) >= 2:
			stack_b[0], stack_b[1] = stack_b[1], stack_b[0]
	if output[moveNbr] == "ra" and len(stack_a) >= 2:
		stack_a.append(stack_a[0])
		del stack_a[0]
	if output[moveNbr] == "rb" and len(stack_b) >= 2:
		stack_b.append(stack_b[0])
		del stack_b[0]
	if output[moveNbr] == "rr":
		if len(stack_a) >= 2:
			stack_a.append(stack_a[0])
			del stack_a[0]
		if len(stack_b) >= 2:
			stack_b.append(stack_b[0])
			del stack_b[0]
	if output[moveNbr] == "rra" and len(stack_a) >= 2:
		stack_a =[stack_a[-1]] + stack_a
		del stack_a[-1]
	if output[moveNbr] == "rrb" and len(stack_b) >= 2:
		stack_b =[stack_b[-1]] + stack_b
		del stack_b[-1]
	if output[moveNbr] == "rrr":
		if len(stack_a) >= 2:
			stack_a =[stack_a[-1]] + stack_a
			del stack_a[-1]
		if len(stack_b) >= 2:
			stack_b =[stack_b[-1]] + stack_b
			del stack_b[-1]
	if output[moveNbr] == "pa" and len(stack_b) >= 1:
		stack_a = [stack_b[0]] + stack_a
		del stack_b[0]
	if output[moveNbr] == "pb" and len(stack_a) >= 1:
		stack_b = [stack_a[0]] + stack_b
		del stack_a[0]

def main():
	# global numbers
	global stack_a
	global stack_b
	global output
	global moveNbr
	testNbr = 0
	results = []
	errors = 0
	while testNbr < setCount:
		moveNbr = 0
		arguments = ""
		numbers = (random.sample(range(nbrCount * 10), nbrCount))
		stack_a = numbers
		for nbr in stack_a:
			arguments += (str(nbr)) + " "
		output = str(subprocess.check_output(["./push_swap", arguments]))
		output = output.replace("\\n", " ")
		output = output.replace("b'", "")
		output = output.replace("'", "")
		output = output.split(" ")
		while moveNbr != len(output):
			doMoves()
			moveNbr += 1
		checkList = stack_a[:]
		checkList.sort()
		print(YELLOW + "Test " +  str(testNbr + 1) + ":" + EOC)
		print("  Moves: %s" % moveNbr)
		if stack_a ==  checkList and len(stack_b) == 0:
			print("  Result: " + GREEN + "OK" + EOC)
		else:
			print(RED + "KO" + EOC)
			errors += 1
			print(numbers)
		testNbr += 1
		results.append(moveNbr)
	print(YELLOW + "\nSUMMARY:\n" + EOC)
	print("  " + str(setCount - errors).rjust(len(str(setCount)), ' ') + "/" + str(setCount) + GREEN + "  PASSED" + EOC)
	print("  " + str(errors).rjust(len(str(setCount)), ' ') + "/" + str(setCount) + RED + "  FAILED" + EOC)
	results.sort()
	print("  Best  Case: %s" % results[0])
	print("  Worst Case: %s" % results[-1])


if __name__ == "__main__":
	main()