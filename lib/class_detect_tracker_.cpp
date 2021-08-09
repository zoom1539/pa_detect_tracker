#include "class_detect_tracker_.h"

_DetectTracker::_DetectTracker() 
{
	
}
_DetectTracker::~_DetectTracker() 
{
   
}
bool _DetectTracker::init(const std::string &engine_path_)
{
	return _detector.init(engine_path_);
}

bool _DetectTracker::run(const cv::Mat &img_, 
             			std::vector<TrackedBox> &rects_tracked_)
{
	//detect
	std::vector<cv::Mat> imgs;
	imgs.push_back(img_);

	std::vector<std::vector<Detection> > vec_detections;
	bool is_detect = _detector.detect(imgs, vec_detections);
	if (!is_detect || (0 == vec_detections.size()))
	{
		return false;
	}

	// track
	std::vector<Detection> detections = vec_detections[0];

	std::vector<cv::Rect> rects;
	for (int i = 0; i < detections.size(); i++)
	{
		if (detections[i].class_id == 0) // person
		{
			rects.push_back(detections[i].rect);
		}
	}

	return _tracker.run(rects, img_.size(), rects_tracked_);

}