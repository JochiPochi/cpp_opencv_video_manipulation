#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    // Load input video
    cv::VideoCapture input_cap(argv[1]);
    if (!input_cap.isOpened())
    {
        std::cout << "!!! Input video could not be opened" << std::endl;
        return -1;
    }

    // Setup output video
    cv::VideoWriter output_cap("output.avi",  
                               input_cap.get(cv::CAP_PROP_FOURCC),
                               input_cap.get(cv::CAP_PROP_FPS), 
                               cv::Size(input_cap.get(cv::CAP_PROP_FRAME_WIDTH), input_cap.get(cv::CAP_PROP_FRAME_HEIGHT)));

    if (!output_cap.isOpened())
    {
        std::cout << "!!! Output video could not be opened" << std::endl;
        return -1;
    }

    // Loop to read frames from the input capture and write it to the output capture
    cv::Mat frame;
    while (true)
    {       
        if (!input_cap.read(frame))             
            break;

        output_cap.write(frame);
    }

    // Release capture interfaces   
    input_cap.release();
    output_cap.release();

    return 0;
}
