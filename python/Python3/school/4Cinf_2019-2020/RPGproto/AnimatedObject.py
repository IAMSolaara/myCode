import pygame

class AnimatedObject():
    def __init__(self, path, sprSize, pos, scaledSize):
        self.sheet = pygame.image.load(path).convert()
        self.sheet.set_colorkey((255,0,255))
        self.sprSize = sprSize
        self.sprArea = pygame.Rect((0,0), self.sprSize)
        self.counter = 0
        self.counterInc = 0.25
        self.frames = self.sheet.get_rect().width / sprSize[0]
        self.pos = pos
        self.sprScaledSize = scaledSize

    def animate(self):
        if (self.counter + self.counterInc >= self.frames):
            self.counter = 0
        else:
            self.counter += self.counterInc

        self.sprArea.x = round(self.counter) * self.sprSize[0]
        surf = pygame.Surface(self.sprSize).convert_alpha()
        surf.fill( (0,0,0,0) )
        surf.blit(self.sheet, (0,0), self.sprArea)
        return pygame.transform.scale(surf, self.sprScaledSize)
    
    def get_rect(self):
        return pygame.Rect(self.pos, self.sprScaledSize)