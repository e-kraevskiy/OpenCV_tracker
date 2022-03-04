#include "tracking.h"

const std::string VIDEO_PATH = "../test_data/img/%04d.jpg";
const std::string FISHING_PATH = "../test_data/input.mp4";

int main() {
	Tracking testTracking;
    testTracking.LoadSequence(VIDEO_PATH);
    while (testTracking.LoadNextFrame() == REPLY_OK
           && testTracking.GetFrameNum() < 1000) {
        if (testTracking.GetFrameNum() == 1) {
			testTracking.CreateResultVideo();
		}
		testTracking.ProcessImage();
		testTracking.DetectTarget();
		testTracking.TrackTarget();
		testTracking.DisplayResult(1);
		testTracking.WriteResultVideo();
        if (waitKey(1) == 27) break;
	}

	//testTracking.ReleaseResultVideo();
	
	return 0;
}

