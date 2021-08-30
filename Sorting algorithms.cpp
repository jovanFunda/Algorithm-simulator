#define Print(x) std::cout << x << std::endl

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>

void bubbleSort();
void swap(int& x, int& y);

int main()
{
		Print("Welcome to Sorting Algortihm application!" << std::endl);

		int option = -1;
		while (option != 0)
		{
			Print("1) Bubble sort");
			Print("0) Exit app" << std::endl);

			std::cin >> option;

			switch (option) {
			case 1:
				bubbleSort();
				break;
			case 3:
				break;
		}
	}
}

void bubbleSort()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Bubble sorting", sf::Style::Titlebar | sf::Style::Close);

	int rects[200];
	int rect[200] = { 0 };
	srand((unsigned)time(0));

	for (int i = 0; i < 200; i++)
	{
		int randomNumber = (rand() % 200);

		while (rect[randomNumber] != 0)
		{
			randomNumber = (rand() % 200);
		}

		rects[i] = randomNumber + 1;
		rect[randomNumber] = 1;
	}

	sf::Clock clock;
	sf::Time time;

	while (window.isOpen())
	{
		time += clock.restart();

		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		for (int i = 0; i < 200 - 1; i++)
		{
			if (time.asMilliseconds() > 100)
			{
				for (int j = 0; j < 200 - i - 1; j++)
				{
					if (rects[j] > rects[j + 1])
					{
						swap(rects[j], rects[j + 1]);
					}
				}

				time -= time;
				for (int k = 0; k < 200; k++)
				{
					sf::RectangleShape rectangle(sf::Vector2f(4, rects[k] * 4));
					rectangle.setPosition(sf::Vector2f(k * 4, window.getSize().y - rects[k] * 4));
					window.draw(rectangle);
				}
				window.display();
			}
		}
	}
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}