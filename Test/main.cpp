#include <SFML/Graphics.hpp>
#include <iostream>


bool isColliding(sf::RectangleShape &target, sf::CircleShape &othertarget)
{
	sf::FloatRect collision = target.getGlobalBounds();
	sf::FloatRect othercollision = othertarget.getGlobalBounds();

	if (collision.intersects(othercollision))
	{
		return true;
	}

	return false;
}


sf::Font LoadFont(std::string path)
{
	sf::Font font;

	font.loadFromFile(path);

	if (!font.loadFromFile(path))
	{
		std::cout << "Error unable to open font." << std::endl;
	}

	return font;
}


int main() {

	sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works");
	sf::RectangleShape player(sf::Vector2f(30, 95));
	sf::RectangleShape enemy(sf::Vector2f(30, 95));
	sf::CircleShape ball(15);
	sf::Clock Time;
	sf::Text text;
	sf::Font font;

	int enemyScore = 0;
	int playerScore = 0;
	float dt;
	float ballX = window.getSize().x / 2;
	float ballY = window.getSize().y / 2;
	int ballSpeedX = 150;
	int maxSpeed = 250;
	int delay = 93;
	int ballSpeedY = 0;
	float upperHalfOfTheRect = player.getSize().y / 2;

	//font.loadFromFile("E:/Downloads/open-sans/OpenSans-Bold.ttf");

	/*
	if (!font.loadFromFile("E:/Downloads/open-sans/OpenSans-Bold.ttf"))
	{
		std::cout << "Error unable to open font." << std::endl;
	}
	*/
	font = LoadFont("E:/Downloads/open-sans/OpenSans-Bold.ttf");

	text.setFont(font);
	text.setString(std::to_string(playerScore) + " - " + std::to_string(enemyScore));
	text.setCharacterSize(48);
	text.setPosition(sf::Vector2f(window.getSize().x / 2 - 40, 20));
	text.setFillColor(sf::Color::White);

	player.setPosition(sf::Vector2f(20.0f, window.getSize().y / 2.0f));
	enemy.setPosition(sf::Vector2f(590.0f, window.getSize().y / 2.0f));
	ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

	while (window.isOpen())
	{
		text.setString(std::to_string(playerScore) + " - " + std::to_string(enemyScore));

		dt = Time.restart().asSeconds();

		ballX -= ballSpeedX * dt;
		ballY += ballSpeedY * dt;
		
		ball.setPosition(ballX , ballY);

		/*
		if (ball.getPosition().x > 240)
		{
			delay =	90;
		}
		if (ball.getPosition().x < 240)
		{
			delay = 70;
		}
		*/

		int mousePosY = sf::Mouse::getPosition(window).y;
		//std::cout << "the position of y is " << mousePosY << std::endl;
		//std::cout << "ball position is " << ball.getPosition().x << std::endl;

		player.setPosition(sf::Vector2f(player.getPosition().x, mousePosY));
		enemy.setPosition(sf::Vector2f(590.0f, ball.getPosition().y - delay));

		if (player.getPosition().y <= 0)
		{
			player.setPosition(sf::Vector2f(player.getPosition().x, 0));
		}

		if (player.getPosition().y >= 384)
		{
			player.setPosition(sf::Vector2f(player.getPosition().x, 384));
		}

		if (enemy.getPosition().y <= 0)
		{
			enemy.setPosition(sf::Vector2f(enemy.getPosition().x, 0));
		}

		if (enemy.getPosition().y >= 384)
		{
			enemy.setPosition(sf::Vector2f(enemy.getPosition().x, 384));
		}

		
		
		if (ball.getPosition().x < 0)
		{
			enemyScore++;
			//std::to_string(++enemyScore);

			//ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

			ballX = window.getSize().x / 2;
			ballY = window.getSize().y / 2;

			ballSpeedY = 0;
			/*
			ballX -= ballSpeedX * dt;
			ballY = window.getSize().y / 2;
			*/
		}

		if (ball.getPosition().x > window.getSize().x)
		{
			playerScore++;

			//ball.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
			ballX = window.getSize().x / 2;
			ballY = window.getSize().y / 2;

			ballSpeedY = 0;
			/*
			ballX += ballSpeedX * dt;
			ballY = window.getSize().y / 2;
			*/
		}
		
		

		sf::Event event;

		
		if (ballSpeedY > 250)
		{
			ballSpeedY = 250;
		}
		

		if (isColliding(player, ball))
		{
			//std::cout << "is Colliding" << std::endl;

			if (ball.getPosition().y < player.getPosition().y + (player.getSize().y / 2) )
			{
				//std::cout << "upper" << std::endl;
				ballSpeedY -= 150;
			}
			else
			{
				//std::cout << "down" << std::endl;
				ballSpeedY += 150;
			}
			ballSpeedX *= -1;

			
			//ball.setPosition(ball.getPosition().x, ballY);
			//ball.setPosition(-ballX, ball.getPosition().y);
		}

		if (isColliding(enemy, ball))
		{

			if (ball.getPosition().y < enemy.getPosition().y + (enemy.getSize().y / 2))
			{
				//std::cout << "upper" << std::endl;
				ballSpeedY -= 150;
			}
			else
			{
				//std::cout << "down" << std::endl;
				ballSpeedY += 150;
			}

			//std::cout << "is Colliding (Enemy)" << std::endl;
			ballSpeedX *= -1;
		}

		if (ball.getPosition().y < 0)
		{
			ballSpeedY += 150;
		}

		
		if (ball.getPosition().y > 450)
		{
			ballSpeedY -= 150;
		}
		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//std::cout << "ball position y" << ball.getPosition().y << std::endl;

		window.clear();
		window.draw(player);
		window.draw(text);
		window.draw(enemy);
		window.draw(ball);
		window.display();

	}

}
