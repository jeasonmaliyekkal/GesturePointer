#include <opencv2/opencv.hpp>
#include<unistd.h>


using namespace cv;

void detectHands(Mat *frame);
void setCursor(int x, int y);

int main() {
    // Create a VideoCapture object for the default camera
    VideoCapture cap(0);

    //setting resolution
    cap.set(CAP_PROP_FRAME_WIDTH, 640);
    cap.set(CAP_PROP_FRAME_HEIGHT, 360);

    // Check if the camera is opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error opening camera" << std::endl;
        return -1;
    }

    // Create a window to display the video
    namedWindow("WaveGuide", WINDOW_AUTOSIZE);

    while (true) {
        // Capture a frame from the camera
        Mat frame;
        
        cap.read(frame);

        // Check if the frame was successfully captured
        if (frame.empty()) {
            std::cerr << "Error capturing frame" << std::endl;
            break;
        }

        //calling detectframes 
        detectHands(&frame);
        // Display the frame in the window
        imshow("WaveGuide", frame);

        // Wait for 10 milliseconds for a key event
        if (waitKey(10) == 27) {
            std::cout << "Esc key is pressed by user" << std::endl;
            break;
        }
    }

    // Release the VideoCapture object and close the window
    cap.release();
    destroyAllWindows();



    return 0;
}
