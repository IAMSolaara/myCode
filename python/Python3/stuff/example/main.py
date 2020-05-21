#!/usr/bin/env python3
# import pygame module
import pygame

from pygame.locals import *


# initialize pygame system
pygame.init()

# set up screen
screen = pygame.display.set_mode([640, 480])

thingPos = (25,25)

cursor = pygame.image.load("./crosshair.png").convert()
cursor.set_colorkey((0,0,0))
cursor_rect = cursor.get_rect()

button = pygame.Rect(100, 100, 100, 25)
buttonColorClicked = (0,255,255)
buttonColor = (0,255,0)

button_color = buttonColor

angle = 0

# run loop
running = True
button_clicked = False
while running:

    angle += 0.05
    
    # event loop
    for event in pygame.event.get():
        # check if close button is pressed
        if event.type == pygame.QUIT:
            # stop run loop
            running = False
        # check if user pressed a key
        elif event.type == KEYDOWN:
            # check if key is escape
            if event.key == K_ESCAPE:
                running = False
            elif event.key == K_UP:
                thingy -= 1
            elif event.key == K_DOWN:
                thingy += 1
            elif event.key == K_LEFT:
                thingx -= 1
            elif event.key == K_RIGHT:
                thingx += 1

        elif event.type == MOUSEMOTION:
            thingPos = event.pos

        elif event.type == MOUSEBUTTONDOWN:
            if button.collidepoint(event.pos):
                button_clicked = not button_clicked

    # fill the screen with white
    screen.fill([255,255,255])
    pygame.draw.rect(screen, (buttonColor, buttonColorClicked)[button_clicked], button)
    cursor_copy = pygame.transform.rotate(cursor, angle)
    
    screen.blit(cursor_copy, (thingPos[0] - (cursor_copy.get_rect().width/2), thingPos[1] - (cursor_copy.get_rect().height/2)))



    # flip (like blit) display
    pygame.display.flip()
    button_color = buttonColor

pygame.quit()
