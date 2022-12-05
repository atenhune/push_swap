#!/usr/bin/env python3

from inspect import stack
import sys
import os.path
import os
from os import path
import random
import subprocess
import pygame

YELLOW = "\033[38;5;220m"
EOC = "\033[0m"


WIDTH, HEIGHT = 1200, 800
WIN = pygame.display.set_mode((WIDTH, HEIGHT))
FPS = 20
RED3 = (120, 0, 0)
RED2 = (175, 0, 0)
RED1 = (255, 0, 0)
GREEN1 = (0, 120, 0)
GREEN2 = (0, 175, 0)
GREEN3 = (0, 255, 0)
BLUE1 = (255, 175, 0)
BLUE2 = (255, 100, 0)
BLUE3 = (255, 50, 0)
pygame.display.set_caption("Push_Swap Visualizer")


stack_a = []
stack_b = []
output = []
moveNbr = 0
if len(sys.argv) > 1:
	nbrCount = int(sys.argv[1])
else:
	print("\n" + YELLOW +"Usage:"+ EOC +"\n\tpython3 visualizer.py <amount of numbers> (50-700)\n")
	quit()
y = (HEIGHT - 50) / nbrCount


def set_color(nbr):
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

def draw_a(nbr, i):
	pygame.draw.rect(WIN, set_color(nbr), (0, i*y, calc_x(nbr), y))

def draw_b(nbr, i):
	pygame.draw.rect(WIN, set_color(nbr), (601, i*y, calc_x(nbr), y))

def drawStacks():
	i = 0
	for val in stack_a:
		draw_a(val, i)
		i += 1
	i = 0
	for val in stack_b:
		draw_b(val, i)
		i += 1

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
	moveNbr += 1
	
def pauseGame():
	paused = True
	while paused:
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				pygame.quit()
				quit()
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_SPACE:
					paused = False


def vis():
	clock = pygame.time.Clock()
	speed = 3
	run = True
	i = 0
	pygame.font.init()
	textfont = pygame.font.SysFont("monospace", 25)
	pausefont = pygame.font.SysFont("monospace", 45)
	while run:
		clock.tick(speed * FPS)
		for event in pygame.event.get():
			if event.type == pygame.QUIT:
				run = False
			if event.type == pygame.KEYDOWN:
				if event.key == pygame.K_UP and speed < 10:
					speed += 1
				if event.key == pygame.K_DOWN and speed > 1:
					speed -= 1
				if event.key == pygame.K_SPACE:
					text = pausefont.render("PAUSED", 1, (255, 255, 255))
					WIN.blit(text, (1030, 750))
					pygame.display.update()
					pauseGame()
		WIN.fill((0, 0, 0))
		pygame.draw.line(WIN, (255, 255, 255), (600, 0), (600, 800))
		drawStacks()
		doMoves()
		text = textfont.render("Speed: %s" % speed, 1, (255, 255, 255))
		WIN.blit(text, (5, 775))
		text = textfont.render("Moves: %s" % moveNbr, 1, (255, 255, 255))
		WIN.blit(text, (150, 775))
		text = textfont.render("Sorted: " , 1, (255, 255, 255))
		WIN.blit(text, (350, 775))
		checkList = stack_a[:]
		checkList.sort()
		if stack_a == checkList and len(stack_b) == 0:
			text = textfont.render("YES" , 1, (0, 255, 0))
			WIN.blit(text, (457, 775))
		else:
			text = textfont.render("NO" , 1, (255, 0, 0))
			WIN.blit(text, (457, 775))

		pygame.display.update()

	pygame.quit()


def	main():
	global stack_a
	global stack_b
	global output
	if nbrCount > 700 or nbrCount < 50:
		print("\n" + YELLOW +"Usage:"+ EOC +"\n\tpython3 visualizer.py <amount of numbers> (50-700)\n")
		quit()
	arguments = ""
	stack_a = (random.sample(range(nbrCount), nbrCount))
	for nbr in stack_a:
		arguments += (str(nbr)) + " "
	output = str(subprocess.check_output(["./push_swap", arguments]))
	output = output.replace("\\n", " ")
	output = output.replace("b'", "")
	output = output.replace("'", "")
	output = output.split(" ")
	vis()

if __name__ == "__main__":
	main()