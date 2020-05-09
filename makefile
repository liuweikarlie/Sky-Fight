skyfight: main.o player.o enemy.o battleground.o funcs.o
	g++ -pedantic -errors -std=c++11 main.o player.o enemy.o battleground.o funcs.o -o skyfight

funcs.o : funcs.cpp funcs.h
	g++ -pedantic -errors -std=c++11 -c  funcs.cpp

enemy.o: enemy.cpp enemy.h battleground.h
	g++ -pedantic -errors -std=c++11 -c  enemy.cpp

player.o: player.cpp player.h battleground.h
	g++ -pedantic -errors -std=c++11 -c  player.cpp

battleground.o :battleground.cpp battleground.h funcs.h enemy.h player.h
	g++ -pedantic -errors -std=c++11 -c  battleground.cpp

main.o: main.cpp battleground.h
	g++ -pedantic -errors -std=c++11 -c  main.cpp

clean:
	rm -f *o skyfight
