#pragma once

#ifndef MYSLAM_FRAME_H
#define MYSLAM_FRAME_H

#include "myslam/common_include.h"
#include "myslam/camera.h"

namespace myslam {

// forward declare 
struct MapPoint;
struct Feature;

struct Frame {
public:
    typedef std::shared_ptr<Frame> Ptr;

    unsigned long id_ = 0;         // id of this frame
    unsigned long keyframe_id_ = 0;  // id of key frame
    bool is_keyframe_ = false;
    double time_stamp_;        // when it is recorded
    SE3 pose_;                  // Tcw, transform from world to camera
    Mat left_img_, right_img_; // stereo images

    // extracted features in left image
    std::vector<std::shared_ptr<Feature>> features_left_;

    // corresponding features in right image, set to nullptr if no corresponding feature is found
    std::vector<std::shared_ptr<Feature>> features_right_;

public: // data members 
    Frame() {}

    Frame(long id, double time_stamp, const SE3 &pose, const Mat &left, const Mat &right);

    ~Frame();

    // factory function
    static std::shared_ptr<Frame> CreateFrame();
};

}

#endif // MYSLAM_FRAME_H
