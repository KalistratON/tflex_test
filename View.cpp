#include "View.h"

void View::drawByTri(const std::unique_ptr<figure::Figure>& _fgr) const
{
	auto fgrPoints = _fgr->interpolation();
	const size_t N = fgrPoints.size();

	for (size_t j = 1; j < N; j++)
		line(fgrPoints.at(0).get_x(), fgrPoints.at(0).get_y(),
			fgrPoints.at(j).get_x(), fgrPoints.at(j).get_y());

	for (size_t j = 2; j < N; j++)
		line(fgrPoints.at(j - 1).get_x(), fgrPoints.at(j - 1).get_y(),
			fgrPoints.at(j).get_x(), fgrPoints.at(j).get_y());

	line(fgrPoints.at(N - 1).get_x(), fgrPoints.at(N - 1).get_y(),
		fgrPoints.at(1).get_x(), fgrPoints.at(1).get_y());
}
