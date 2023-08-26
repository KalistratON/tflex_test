#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <chrono>
#include <thread>

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Ellipse.h"
#include "View.h"

using Shape = std::unique_ptr<figure::Figure>;

int main(int argc, char* argv[])
{
	try {
		const int windowWidth = 1440;
		const int windowHeight = 1080;
		initwindow(windowWidth, windowHeight);

		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		const size_t N = 20;
		std::vector<Shape> figures;
		View view;


		const figure::Point globalCenter(	static_cast<double>(windowWidth / 2), 
											static_cast<double>(windowHeight / 3));
		const figure::Rotate globalRotate(figure::phi / 4);
		const figure::Rotate globalRotateTemp(.0);

		const double radius = 250.0;

		const double x_axis = 350.0;
		const double y_axis = 200.0;

		const double height = 300.0;
		const double width = 200.0;

		const double a = 300.0;
		const double b = 400.0;
		const double c = 500.0;

		auto generateType = [&]() -> Shape
		{
			switch (std::rand() % 8)
			{
			case 0:
				return std::make_unique<figure::Circle>(globalCenter, globalRotate, radius);
				break;
			case 1:
				return std::make_unique<figure::Ellipse>(globalCenter, globalRotate, x_axis, y_axis);
				break;
			case 2:
				return std::make_unique<figure::Rectangle>(globalCenter, globalRotate, height, width);
				break;
			case 3:
				return std::make_unique<figure::Triangle>(globalCenter, globalRotate, a, b, c);
			case 4:
				return std::make_unique<figure::Circle>(globalCenter, globalRotateTemp, radius);
				break;
			case 5:
				return std::make_unique<figure::Ellipse>(globalCenter, globalRotateTemp, x_axis, y_axis);
				break;
			case 6:
				return std::make_unique<figure::Rectangle>(globalCenter, globalRotateTemp, height, width);
				break;
			default:
				return std::make_unique<figure::Triangle>(globalCenter, globalRotateTemp, a, b, c);
			}
		};

		auto iter = std::back_inserter(figures);
		std::generate_n(iter, N, generateType);

		std::for_each(figures.begin(), figures.end(), [&view](const Shape& shape) {
			view.drawByTri(shape);
			shape->printIntoStream(std::cout);
			std::cout << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1ll));
			cleardevice();
		});
		
		closegraph();

	}
	catch (const std::invalid_argument& exc) {

		std::cerr << exc.what() << std::endl;
	}
	catch (const std::exception&)
	{
		std::cerr << "Standart exception" << std::endl;
	}
	catch (...)
	{
		std::cerr << "Non - standart exception" << std::endl;
	}
	return 0;
}