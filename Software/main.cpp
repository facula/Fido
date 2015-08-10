#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

#include "Neuron.h"
#include "NeuralNet.h"
#include "GeneticAlgo.h"
#include "TicTacToe.h"

int main() {
    srand(time(NULL));
	std::cout << "Start\n";
	TicTacToe game;

	net::NeuralNet *bestPlayer = game.getBestPlayer(12);
	bestPlayer->storeNet("TTT_2by9_30_123.txt");

	clock_t begin = clock();
	std::cout << "Outcome: " << TicTacToe::getWinsAgainstRandomPlayers(bestPlayer, 1000) << "\n";
	clock_t end = clock();
	double elapsedSecs = double(end - begin) / CLOCKS_PER_SEC;
	std::cout << "Time: " << elapsedSecs << "\n";

	TicTacToe::playAgainstHuman(bestPlayer);
}