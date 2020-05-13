TARGETS	=	exam

all:	$(TARGETS)

exam:	main.o Control.o Creature.o Hero.o Trainer.o Fighter.o Harold.o Timmy.o random.o Dorc.o Borc.o Porc.o Dragon.o Yoda.o Ladybug.o Rocky.o View.o
	g++ -o exam main.o Control.o Creature.o Hero.o Trainer.o Fighter.o Harold.o Timmy.o random.o Dorc.o Borc.o Porc.o Dragon.o Yoda.o Ladybug.o Rocky.o View.o

main.o:	main.cc Array.h
	g++ -c main.cc

Control.o:	Control.cc Control.h Array.h ./Templates/Creature.h ./Heros/Timmy.h ./Heros/Harold.h ./Fighters/Dorc.h ./Fighters/Borc.h ./Fighters/Porc.h Dragon.h ./Trainers/Yoda.h ./Trainers/Ladybug.h ./Trainers/Rocky.h ./Templates/Hero.h ./Templates/Trainer.h ./Templates/Fighter.h View.h
	g++ -c Control.cc

random.o:	random.cc
	g++ -c random.cc

View.o:	View.cc View.h
	g++ -c View.cc

Creature.o:	./Templates/Creature.cc ./Templates/Creature.h
	g++ -c ./Templates/Creature.cc

Hero.o:	./Templates/Hero.cc ./Templates/Hero.h ./Templates/Creature.h
		g++ -c ./Templates/Hero.cc

Fighter.o:	./Templates/Fighter.cc ./Templates/Fighter.h ./Templates/Creature.h
	g++ -c ./Templates/Fighter.cc

Trainer.o:	./Templates/Trainer.cc ./Templates/Trainer.h ./Templates/Creature.h
	g++ -c ./Templates/Trainer.cc

Timmy.o:	./Heros/Timmy.cc ./Heros/Timmy.h ./Templates/Creature.h
	g++ -c ./Heros/Timmy.cc

Harold.o:	./Heros/Harold.cc ./Heros/Harold.h ./Templates/Creature.h
	g++ -c ./Heros/Harold.cc

Dorc.o:	./Fighters/Dorc.cc ./Fighters/Dorc.h ./Templates/Creature.h ./Templates/Fighter.h
	g++ -c ./Fighters/Dorc.cc

Borc.o:	./Fighters/Borc.cc ./Fighters/Borc.h ./Templates/Creature.h ./Templates/Fighter.h
	g++ -c ./Fighters/Borc.cc

Porc.o:	./Fighters/Porc.cc ./Fighters/Porc.h ./Templates/Creature.h ./Templates/Fighter.h
	g++ -c ./Fighters/Porc.cc

Dragon.o:	Dragon.cc Dragon.h ./Templates/Creature.h
	g++ -c Dragon.cc

Yoda.o:	./Trainers/Yoda.cc ./Trainers/Yoda.h ./Templates/Creature.h
	g++ -c ./Trainers/Yoda.cc

Ladybug.o:	./Trainers/Ladybug.cc ./Trainers/Ladybug.h ./Templates/Creature.h
	g++ -c ./Trainers/Ladybug.cc

Rocky.o:	./Trainers/Rocky.cc ./Trainers/Rocky.h ./Templates/Creature.h
		g++ -c ./Trainers/Rocky.cc

clean:
	rm -f *.o exam
