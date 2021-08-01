#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


namespace FORM
{
	class Label
	{
		sf::Font font;
	protected:
		std::string text;

		float x;
		float y;

		sf::Text outText;

	public:
		Label(float _x = 0, float _y = 0, std::string _text = "text", sf::Font _font = sf::Font())
		{
			font = _font;
			if (font.getInfo().family == "")
				font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

			x = _x;
			y = _y;
			text = _text;
			outText.setFont(font);
			outText.setCharacterSize(20);
			outText.setOutlineColor(sf::Color::White);
			outText.setPosition(x, y);
		}
		sf::Text displayText()
		{
			outText.setString(text);
			return outText;
		}
	};

	class Button : public Label
	{
		sf::Font font;
	protected:
		double width;
		double height;
		sf::RectangleShape box;
	public:
		Button(double _x = 0, double _y = 0, double _width = 150, double _height = 30,
			std::string _text = "button", sf::Font _font = sf::Font())
		{
			font = _font;
			if (font.getInfo().family == "")
				font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

			x = _x;
			y = _y;
			width = _width;
			height = _height;
			text = _text;
			outText.setFont(font);
			outText.setCharacterSize(20);
			outText.setOutlineColor(sf::Color::White);
			outText.setPosition(x, y);

			box.setSize(sf::Vector2f(width, height));
			box.setPosition(x, y);
			box.setFillColor(sf::Color(133, 133, 133));
			box.setOutlineThickness(2);
			box.setOutlineColor(sf::Color(66, 66, 66));
		}
		bool select(sf::Vector2i _mouse)
		{
			if ((_mouse.x > x && _mouse.x < x + width) && (_mouse.y > y && _mouse.y < y + height)) {
				return  true;
			}
			else {
				return false;
			}
		}
		sf::Text displayText()
		{
			outText.setString(text);
			return outText;
		}
		sf::RectangleShape displayButton()
		{
			return box;
		}


	};
}
class MainWindow
{
	sf::Shape* nowShape = nullptr;
public:
	int32_t exec()
	{
		sf::RenderWindow window(sf::VideoMode(606, 500), "SFML example");
		window.setVerticalSyncEnabled(true);

		sf::Font font;
		font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
		FORM::Button buttonCircle(1, 1, 150, 30, "Circle", font);
		FORM::Button buttonTriangle(152, 1, 150, 30, "Triangle", font);
		FORM::Button buttonRectangle(303, 1, 150, 30, "Rectangle", font);
		FORM::Button buttonOctagon(454, 1, 150, 30, "Octagon", font);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				/*
				nowShape = new sf::CircleShape(100);
				nowShape->setFillColor(sf::Color(100, 149, 237));
				nowShape->setPosition(200, 200);
				window.draw(*nowShape);
				*/
				window.clear(sf::Color(250, 220, 100, 0));


				if (event.type == sf::Event::Closed)
					window.close();
				else if (event.type == sf::Event::MouseButtonPressed )
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						sf::Vector2i mousePlace = sf::Mouse::getPosition(window);
						if (buttonCircle.select(mousePlace))
						{
							delete nowShape;
							nowShape = new sf::CircleShape(100);
							nowShape->setFillColor(sf::Color(100, 149, 237));
							nowShape->setPosition(200, 200);
						}
						else if (buttonTriangle.select(mousePlace))
						{
							delete nowShape;
							nowShape = new sf::CircleShape(100, 3);
							nowShape->setFillColor(sf::Color(100, 149, 237));
							nowShape->setPosition(200, 200);
						}
						else if (buttonRectangle.select(mousePlace))
						{

							delete nowShape;
							nowShape = new sf::RectangleShape(sf::Vector2f(100, 200));
							nowShape->setFillColor(sf::Color(100, 149, 237));
							nowShape->setPosition(200, 200);
						}
						else if (buttonOctagon.select(mousePlace))
						{
							delete nowShape;
							nowShape = new sf::CircleShape(100, 8);
							nowShape->setFillColor(sf::Color(100, 149, 237));
							nowShape->setPosition(200, 200);
						}
					}
				}
			}




			window.draw(buttonCircle.displayButton());
			window.draw(buttonCircle.displayText());

			window.draw(buttonTriangle.displayButton());
			window.draw(buttonTriangle.displayText());

			window.draw(buttonRectangle.displayButton());
			window.draw(buttonRectangle.displayText());

			window.draw(buttonOctagon.displayButton());
			window.draw(buttonOctagon.displayText());
			if (nowShape != nullptr)
			{
				window.draw(*nowShape);

			}
			
			window.display();
		}


		return 0;
	}
};

int main()
{
	MainWindow mainWindow;
	return mainWindow.exec();
}