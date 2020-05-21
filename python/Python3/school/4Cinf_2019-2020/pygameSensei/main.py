import pygame

from pygame.locals import *

pygame.init()
pygame.font.init()

screen = pygame.display.set_mode((800, 600))

pygame.key.set_repeat()

image = pygame.image.load('./image.png').convert()
image.set_colorkey((0,0,0))

image2 = pygame.image.load('./image2.jpg').convert()
image2.set_colorkey((0,0,0))
image2 = pygame.transform.scale(image2, screen.get_rect().size)

saveus = pygame.image.load('./saveus.jpg').convert()
saveus.set_colorkey((0,0,0))
saveus = pygame.transform.scale(saveus, (250,150))
saveus = pygame.transform.rotate(saveus, 15)

fontSize = 15

myfont = pygame.font.SysFont('Arial', fontSize)


running = True

rectPos = (100,100)

angle = 0
angleInc = 1

while running:

    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
        elif event.type == MOUSEMOTION:
            rectPos = event.pos
        elif event.type == MOUSEBUTTONDOWN:
            angleInc *= -1
        elif event.type == KEYDOWN:
            if event.key == K_UP:
                fontSize += 1
                myfont = pygame.font.SysFont('Arial', fontSize)
            elif event.key == K_DOWN:
                fontSize -= 1
                myfont = pygame.font.SysFont('Arial', fontSize)
            
        
    screen.fill( (255,255,255) )

    screen.blit(image2, (0,0))

    pygame.draw.rect( screen, (255,0,0), (rectPos[0] - (10 / 2), rectPos[1] - (50 / 2), 10, 50) )

    text = myfont.render('Test', True, (255,0,255))

    screen.blit(text, rectPos )

    image_copy = pygame.transform.scale(image, (300, 300))
    image_copy = pygame.transform.rotate(image_copy, angle)
    image_copy = pygame.transform.flip(image_copy, False, True)

    screen.blit(image_copy, (250 - image_copy.get_rect().width / 2, 250 - image_copy.get_rect().height / 2))
    screen.blit(saveus, (730 - saveus.get_rect().width / 2, 550 - saveus.get_rect().height / 2))

    angle += angleInc

    pygame.display.flip()