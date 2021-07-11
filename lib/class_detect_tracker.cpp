#include "class_detect_tracker.h"
#include "class_detect_tracker_.h"

class DetectTracker::Impl
{
public:
    _DetectTracker _detect_tracker;
};

DetectTracker::DetectTracker() : _impl(new DetectTracker::Impl())
{
}

DetectTracker::~DetectTracker()
{
    delete _impl;
    _impl = NULL;
}

bool DetectTracker::init(const std::string &engine_path_)
{
    return _impl->_detect_tracker.init(engine_path_);
}

bool DetectTracker::run(const cv::Mat &img_, 
             std::vector<TrackedBox> &rects_tracked_)
{
    return _impl->_detect_tracker.run(img_, rects_tracked_);
}

