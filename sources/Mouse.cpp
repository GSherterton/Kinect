#include "Mouse.h"

using namespace std;

Mouse::Mouse(){
    fistCascadeName = "cascades/fist.xml";
    leftCascadeName = "cascades/left.xml";
    lpalmCascadeName = "cascades/lpalm.xml";
    rightCascadeName = "cascades/right.xml";
    rpalmCascadeName = "cascades/rpalm.xml";

    if(!fistCascade.load(fistCascadeName)){
        cout << "ERROR: Could not load classifier cascade: " << fistCascadeName << endl;
        return;
    }

    if(!leftCascade.load(leftCascadeName)){
        cout << "ERROR: Could not load classifier cascade: " << leftCascadeName << endl;
        return;
    }

    if(!lpalmCascade.load(lpalmCascadeName)){
        cout << "ERROR: Could not load classifier cascade: " << lpalmCascadeName << endl;
        return;
    }

    if(!rightCascade.load(rightCascadeName)){
        cout << "ERROR: Could not load classifier cascade: " << rightCascadeName << endl;
        return;
    }

    if(!rpalmCascade.load(rpalmCascadeName)){
        cout << "ERROR: Could not load classifier cascade: " << rpalmCascadeName << endl;
        return;
    }
}

void Mouse::detectAndDisplay(Mat frame){
    Mat frameGray;
    cvtColor(frame, frameGray, COLOR_BGR2GRAY);
    equalizeHist(frameGray, frameGray); 

    vector<Rect> fists;
    fistCascade.detectMultiScale(frameGray, fists);

    for(int i = 0; i < fists.size(); i++){
        //rectangle(frame, Point(fists[i].x, fists[i].y), Point(fists[i].x + fists[i].width - 1, fists[i].y + fists[i].height - 1), Scalar(255, 0, 0), 3);
        rectangle(frame, fists[i], Scalar(255, 0, 0), 3);//blue green red
        //blue
    }

    vector<Rect> lefts;
    leftCascade.detectMultiScale(frameGray, lefts);

    for(int i = 0; i < lefts.size(); i++){
        //rectangle(frame, Point(fists[i].x, fists[i].y), Point(fists[i].x + fists[i].width - 1, fists[i].y + fists[i].height - 1), Scalar(255, 0, 0), 3);
        rectangle(frame, lefts[i], Scalar(0, 0, 255), 3);//blue green red
        //red
    }

    vector<Rect> lpalm;
    lpalmCascade.detectMultiScale(frameGray, lpalm);

    for(int i = 0; i < lpalm.size(); i++){
        //rectangle(frame, Point(fists[i].x, fists[i].y), Point(fists[i].x + fists[i].width - 1, fists[i].y + fists[i].height - 1), Scalar(255, 0, 0), 3);
        rectangle(frame, lpalm[i], Scalar(0, 255, 255), 3);//blue green red
        //yellow
    }

    vector<Rect> right;
    rightCascade.detectMultiScale(frameGray, right);

    for(int i = 0; i < right.size(); i++){
        //rectangle(frame, Point(fists[i].x, fists[i].y), Point(fists[i].x + fists[i].width - 1, fists[i].y + fists[i].height - 1), Scalar(255, 0, 0), 3);
        rectangle(frame, right[i], Scalar(0, 255, 0), 3);//blue green red
        //green
    }

    vector<Rect> rpalm;
    rpalmCascade.detectMultiScale(frameGray, rpalm);

    for(int i = 0; i < rpalm.size(); i++){
        //rectangle(frame, Point(fists[i].x, fists[i].y), Point(fists[i].x + fists[i].width - 1, fists[i].y + fists[i].height - 1), Scalar(255, 0, 0), 3);
        rectangle(frame, rpalm[i], Scalar(255, 0, 255), 3);//blue green red
        //pink
    }
}