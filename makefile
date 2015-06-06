OUT = rpg
CC = g++
SDL2 = -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf

OBJECTS = sprite.o animation.o gameobject.o tile.o character.o player.o baseitem.o dialog.o enviroment.o main.o

all: $(OUT)
$(OUT) : $(OBJECTS)
	$(CC) -o $@ $^ ${SDL2}