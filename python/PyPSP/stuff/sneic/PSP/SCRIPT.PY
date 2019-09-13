import psp2d, pspos
pspos.setclocks(333,166) # To set both CPU and Bus clock
screen = psp2d.Screen()
BLANK = psp2d.Color(0,0,0)
state=x=y=0
image = psp2d.Image(480, 272)
image.clear(BLANK)
screen.blit(image); screen.swap()
snake="pg.png"
def draw(pgName):                       
	image = psp2d.Image(480, 272)
	image.clear(BLANK)
	screen.blit(image); screen.swap()
	image = psp2d.Image(pgName)
	screen.blit(image, dx=x, dy=y); screen.swap()
while state==0:
	pad = psp2d.Controller()
	if pad.right:
		x = x + 5
		draw(snake)
	elif pad.left:
		x = x - 5
		draw(snake)
	elif pad.up:
		y = y - 5
		draw(snake)
	elif pad.down:
		y = y + 5
		draw(snake)
	elif pad.circle:
		state=1

