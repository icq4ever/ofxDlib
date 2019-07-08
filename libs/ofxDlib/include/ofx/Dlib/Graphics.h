//
// Copyright (c) 2018 Christopher Baker <https://christopherbaker.net>
//
// SPDX-License-Identifier: MIT
//


#pragma once


#include "ofGraphics.h"
#include "ofx/Dlib/FaceFinder.h"
#include "ofx/Dlib/FaceDetection.h"
#include "ofx/Dlib/ObjectDetection.h"


namespace ofx {
namespace Dlib {


inline void draw(const dlib::rectangle& rectangle)
{
    ofDrawRectangle(rectangle.left(),
                    rectangle.top(),
                    rectangle.width(),
                    rectangle.height());
}


inline void draw(const ofRectangle& rectangle, const std::string& label, float labelFillWidth = 1.0)
{
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(2);
    ofDrawRectangle(rectangle);
    ofFill();
    ofDrawRectangle(rectangle.getLeft(),
                    rectangle.getBottom(),
                    rectangle.getWidth(),
                    20);

    ofNoFill();
    ofDrawRectangle(rectangle.getLeft(),
                    rectangle.getBottom(),
                    rectangle.getWidth(),
                    20);

    // Get an inverted color for the text.
    ofSetColor(ofGetStyle().color.getInverted());
    ofDrawBitmapString(label,
                       rectangle.getLeft() + 6,
                       rectangle.getBottom() + 14);

    ofPopStyle();
}

inline void draw(const ObjectDetection& detection)
{
    draw(detection.rectangle, "Confidence: " + ofToString(detection.confidence, 2));
}


inline void draw(const FaceDetection& detection)
{
    draw(detection.rectangle(), "Confidence: " + ofToString(detection.confidence(), 2));
}


inline void draw(const std::map<std::size_t, ObjectDetection>& tracks)
{
    for (auto&& track: tracks)
    {
        draw(track.second.rectangle, "#:" + ofToString(track.first) + " @ " + ofToString(track.second.confidence, 2));
    }
}


inline void draw(const std::map<std::size_t, FaceDetection>& tracks)
{
    for (auto&& track: tracks)
    {
        draw(track.second.rectangle(), "#:" + ofToString(track.first) + " @ " + ofToString(track.second.confidence(), 2));
    }
}


template <typename Type>
inline void draw(const std::vector<Type>& collection)
{
    for (auto&& item: collection)
        draw(item);
}


} } // namespace ofx::Dlib
