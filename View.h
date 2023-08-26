#pragma once

#include <memory>

#include "graphics.h"
#pragma comment(lib,"graphics.lib")

#include "Figure.h"

class View
{
public:
	View() = default;
	View(const View&) = delete;
	View(View&&) = delete;
	~View() = default;

	View& operator = (const View&) = delete;
	View& operator = (View&&) = delete;

	void drawByTri(const std::unique_ptr<figure::Figure>&) const;
};

