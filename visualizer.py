#!/usr/bin/env python3

import sys
import os.path
import os
from os import path
import random
import subprocess
import pygame

WIDTH, HEIGHT = 1200, 800
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
FPS = 60
RED1 = (120, 0, 0)
RED2 = (175, 0, 0)
RED3 = (255, 0, 0)
GREEN1 = (0, 120, 0)
GREEN2 = (0, 175, 0)
GREEN3 = (0, 255, 0)
BLUE1 = (0, 0, 120)
BLUE2 = (0, 0, 175)
BLUE3 = (0, 0, 255)
pygame.display.set_caption("Push_Swap Visualizer")


randomNumbers = []
stack_a = []
stack_b = []
nbrCount = int(sys.argv[1])
y = HEIGHT/nbrCount


def set_color(nbr):
	# colorTuple = (0, 0, 0)
	if nbr > nbrCount * 0.89:
		colorTuple = RED3
	elif nbr > nbrCount * 0.78:
		colorTuple = RED2
	elif nbr > nbrCount * 0.67:
		colorTuple = RED1
	elif nbr > nbrCount * 0.56:
		colorTuple = BLUE3
	elif nbr > nbrCount * 0.45:
		colorTuple = BLUE2
	elif nbr > nbrCount * 0.34:
		colorTuple = BLUE1
	elif nbr > nbrCount * 0.23:
		colorTuple = GREEN3
	elif nbr > nbrCount * 0.12:
		colorTuple = GREEN2
	else:
		colorTuple = GREEN1
	return colorTuple

def calc_x(nbr):
	return 500/nbrCount*nbr

def drawRect():
	# color = set_color(120)
	# print(int(color))
	pygame.draw.rect(WIN, (0, 120, 0), (0, 0, 500, 5))
	pygame.draw.rect(WIN, (0, 175, 0), (0, 5, 300, 5))
	pygame.draw.rect(WIN, (0, 255, 0), (0, 10, 300, 5))
	pygame.draw.rect(WIN, (255, 0, 0), (0, 15, 300, 5))
	pygame.draw.rect(WIN, (175, 0, 0), (0, 20, 300, 5))
	pygame.draw.rect(WIN, (120, 0, 0), (0, 25, 300, 5))
	pygame.draw.rect(WIN, (0, 0, 120), (0, 30, 300, 5))
	pygame.draw.rect(WIN, (0, 0, 175), (0, 35, 300, 5))
	pygame.draw.rect(WIN, (0, 0, 255), (0, 40, 300, 5))

def draw_a(nbr, i):
	pygame.draw.rect(WIN, set_color(nbr), (0, i*y, calc_x(nbr), y))

def drawStacks():
	i = 0
	print("WHAT")
	for val in stack_a:
		# draw_a(val, i)
		pygame.draw.rect(WIN, set_color(val), (0, i*y, calc_x(val), y))
		i += 1
		print(i)

def vis():
	clock = pygame.time.Clock()
	run = True
	i = 0
	while run:
		global stack_a
		clock.tick(FPS)
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				run = False
		WIN.fill((0, 0, 0))
		pygame.draw.line(WIN, (255, 255, 255), (600, 0), (600, 800))
		pygame.draw.rect(WIN, set_color(55), (0, i*y, calc_x(55), y))
		print(stack_a)
		# drawStacks()
		# for val in stack_a:
		# 	pygame.draw.rect(WIN, set_color(val), (0, i*y, calc_x(val), y))
		# 	i += 1
		# 	print(i)
		pygame.display.update()
	pygame.quit()


def	main():
	# nbrCount = int(sys.argv[1])
	stack_a = (random.sample(range(nbrCount), nbrCount))
	arguments = ""
	for nbr in stack_a:
		arguments += (str(nbr)) + " "
	output = str(subprocess.check_output(["./push_swap", arguments]))
	output = output.replace("\\n", " ")
	output = output.replace("b'", "")
	output = output.replace("'", "")
	output = output.split(" ")
	# for cmd in output:
	# 	print(cmd)
	# print(output)
	vis()
	# print(stack_a)


if __name__ == "__main__":
	main()