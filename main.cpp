#include "class_detect_tracker.h"
#include <sstream>

#define CNUM (20)
int main()
{
	//
	cv::RNG rng(0xFFFFFFFF);
	cv::Scalar_<int> randColor[CNUM];
	for (int i = 0; i < CNUM; i++)
		rng.fill(randColor[i], cv::RNG::UNIFORM, 0, 256);
	
	//
	DetectTracker detect_tracker;

	std::string engine_path = "../lib/extra/detector/lib/yolov5s_fp16_b1.engine";
	detect_tracker.init(engine_path);

	for (int i = 0; i < 205; i++)
	{
		std::stringstream ss;
		ss << "../data/pics1/" << i * 15 << ".jpg";
		cv::Mat img = cv::imread(ss.str());
		std::vector<TrackedBox> rects_tracked;
		detect_tracker.run(img, rects_tracked);

		for (int j = 0; j < rects_tracked.size(); j++)
        {
            cv::rectangle(img, rects_tracked[j].rect, randColor[rects_tracked[j].id % CNUM], 2);
            cv::putText(img, std::to_string((int)rects_tracked[j].id), 
			            cv::Point(rects_tracked[j].rect.x, rects_tracked[j].rect.y - 1), 
						cv::FONT_HERSHEY_PLAIN, 1.2, randColor[rects_tracked[j].id % CNUM], 2);
        }

		{
			std::stringstream ss;
			// ss << "../data/output/" << i * 15 << ".jpg";
			ss << "../data/output/0.jpg";
			cv::imwrite(ss.str(), img);
			std::cout << i * 15 << std::endl;
			std::cin.get();
		}
	}
	
	return 0;
}