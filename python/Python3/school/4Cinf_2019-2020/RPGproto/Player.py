import pygame

class PlayerClass():
    def __init__(self, path, sheetSize, sprSize):
        self.sheet = pygame.image.load(path).convert()
        self.sheetSize = sheetSize
        self.sprSize = sprSize