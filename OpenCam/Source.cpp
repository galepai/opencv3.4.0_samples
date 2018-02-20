#include <opencv2/opencv.hpp>

using namespace cv;

int main()
{
	VideoCapture cam(0);
	if (!cam.isOpened())
		return -1;
	double width = cam.get(CAP_PROP_FRAME_WIDTH);
	double height = cam.get(CAP_PROP_FRAME_HEIGHT);
	double fps = cam.get(CAP_PROP_FPS);
	double exposure = cam.get(CAP_PROP_EXPOSURE);

	cam.set(CAP_PROP_FRAME_WIDTH, 960);
	cam.set(CAP_PROP_FRAME_HEIGHT, 720);
	cam.set(CAP_PROP_EXPOSURE,-4);
	
	while (true)
	{
		Mat frame;
		cam >> frame; // get a new frame from camera/video or read image

		if (frame.empty())
		{
			waitKey();
			//break;
		}
		imshow("YOLO: Detections", frame);
		if (waitKey(1) >= 0) break;
		//waitKey(0);
	}
	
}