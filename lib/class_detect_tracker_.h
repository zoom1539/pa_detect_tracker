#pragma once

// std
#include <opencv2/opencv.hpp>
#include "class_tracker.h"
#include "class_detector.h"

class _DetectTracker
{
public:
    _DetectTracker();
    ~_DetectTracker();

public:
    bool init(const std::string &engine_path_);
    bool run(const cv::Mat &img_, 
             std::vector<TrackedBox> &rects_tracked_);
    

private:
    Detector _detector;
    Tracker _tracker;

};
