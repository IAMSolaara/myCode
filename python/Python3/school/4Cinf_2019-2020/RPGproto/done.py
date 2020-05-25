import pygame

from pygame.locals import *
from AnimatedObject import AnimatedObject

pygame.init()

font = pygame.font.SysFont('Arial', 20)

pygame.key.set_repeat(1,10)

screen = pygame.display.set_mode((1024, 768))

player = pygame.image.load('./player.png').convert()
player.set_colorkey((255,0,255))
player = pygame.transform.scale(player, (128,512))

print(player)

playerPos = [100,100]
playerArea = pygame.Rect((0,0), (128,128))
playerPosInc = 16
playerRect = pygame.Rect(playerPos, playerArea.size)

coins = []

clock = pygame.time.Clock()

coinsCnt = 0

running = True
while running:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False
        
        if event.type == MOUSEBUTTONDOWN:
            sprPos = (event.pos[0] - (64), event.pos[1] - (64))
            coins.append(AnimatedObject("./coin_gold.png", (32,32), pos=sprPos, scaledSize=(128,128)))
        
        if event.type == KEYDOWN:
            key = event.key
            if (key == K_UP):
                if (playerPos[1] - playerPosInc >=0):
                    playerPos[1] -= 16
                    playerArea.y = 384
            if (key == K_DOWN):
                if (playerPos[1] + playerRect.height + playerPosInc <= screen.get_rect().height):
                    playerPos[1] += 16
                    playerArea.y = 0
            if (key == K_RIGHT):
                if (playerPos[0] + playerRect.width + playerPosInc <= screen.get_rect().width):
                    playerPos[0] += 16
                    playerArea.y = 256
            if (key == K_LEFT):
                if (playerPos[0] + playerPosInc >= 0):
                    playerPos[0] -= 16
                    playerArea.y = 128
            elif (key == K_KP_PLUS):
                playerArea.width += 16
            elif (key == K_KP_MINUS):
                playerArea.width -= 16

    playerRect = pygame.Rect(playerPos, playerArea.size)
    
    screen.fill((255,255,255))

    for i, coin in enumerate(coins):
        coinSurf = coin.animate()
        coinRect = coin.get_rect()
        if (playerRect.colliderect(coinRect)):
            coinsCnt += 1
            coins.pop(i)
        else:
            screen.blit(coinSurf, coin.pos)

    screen.blit(player, playerPos, playerArea)

    screen.blit(font.render('Coins: %2d' % coinsCnt, True, (0,0,0)), (16, 16))
    pygame.display.flip()
