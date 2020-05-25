import pygame

from pygame.locals import *
from AnimatedObject import AnimatedObject

pygame.mixer.pre_init(44100, 16, 2, 4096)
pygame.init()

font = pygame.font.SysFont('Arial', 20)

pygame.key.set_repeat(1,10)

screen = pygame.display.set_mode((1024, 768))

player = pygame.image.load('./player.png').convert()
player.set_colorkey((255,0,255))
player = pygame.transform.scale(player, (128,512))

print(player)

playerPos = [100,100]
playerPosInc = 16
playerArea = pygame.Rect((0,0), (128,128))
playerRect = pygame.Rect(playerPos, playerArea.size)

background = pygame.image.load('./bg.png').convert()
background = pygame.transform.scale(background, screen.get_rect().size)

coins = []
coinsCnt = 0
coinSFX = pygame.mixer.Sound('./coinBling.wav')

pygame.mixer.music.load('./bgMusic.wav')
pygame.mixer.music.set_volume(0.3)
pygame.mixer.music.play(loops=-1)

clock = pygame.time.Clock()

running = True
while running:
    clock.tick(60)
    for event in pygame.event.get():
        if event.type == QUIT:
            running = False

        if event.type == MOUSEBUTTONDOWN:
            coinPos = ( event.pos[0] - 64, event.pos[1] - 64 )
            coins.append(AnimatedObject('./coin_gold.png', (32,32), coinPos, (128,128)))
        
        if event.type == KEYDOWN:
            key = event.key
            if (key == K_UP):
                if (playerPos[1] - playerPosInc >= 0):
                    playerPos[1] -= playerPosInc
                    playerArea.y = 384
            if (key == K_DOWN):
                if (playerPos[1] + playerRect.height + playerPosInc <= screen.get_rect().height):
                    playerPos[1] += playerPosInc
                    playerArea.y = 0
            if (key == K_RIGHT):
                if (playerPos[0] + playerRect.width + playerPosInc <= screen.get_rect().width):
                    playerPos[0] += playerPosInc
                    playerArea.y = 256
            if (key == K_LEFT):
                if (playerPos[0] - playerPosInc >= 0):
                    playerPos[0] -= playerPosInc
                    playerArea.y = 128

    playerRect = pygame.Rect(playerPos, playerArea.size)

    screen.fill((255,255,255))

    screen.blit(background, (0,0))

    for (i, coin) in enumerate(coins):
        coinSurf = coin.animate()
        if (playerRect.colliderect(coin.get_rect())):
            coinsCnt += 1
            coins.pop(i)
            coinSFX.play()
        else:
            screen.blit(coinSurf, coin.pos)
    

    screen.blit(player, playerPos, playerArea)
    
    fontSurf = font.render('Coins: %6d' % coinsCnt, True, (0,0,0))

    pygame.draw.rect(screen, (255,255,255), pygame.Rect(10,10, fontSurf.get_rect().width+10, fontSurf.get_rect().height + 10) )
    screen.blit(fontSurf,  (16,16))

    pygame.display.flip()
