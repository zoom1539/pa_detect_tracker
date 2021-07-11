#pragma once

#include "opencv2/opencv.hpp"
#include "class_tracker.h"

class DetectTracker
{
public:
    explicit DetectTracker();
    ~DetectTracker();

public:
    bool init(const std::string &engine_path_);
    bool run(const cv::Mat &img_, 
             std::vector<TrackedBox> &rects_tracked_);
    

private:
    DetectTracker(const DetectTracker &);
    const DetectTracker &operator=(const DetectTracker &);

    class Impl;
    Impl *_impl;
};
