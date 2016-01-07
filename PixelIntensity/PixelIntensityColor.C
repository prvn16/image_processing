#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat in_image = imread(argv[1], IMREAD_UNCHANGED);
    if (in_image.empty())
    {

        cout << "Error! Input image cannot be read...\n";
        return -1;
    }

    Size image_sz = in_image.size();
    Mat out_image = Mat::zeros(image_sz, in_image.type());

    double contrast = strtod(argv[2], NULL);
    double brightness = atoi(argv[3]);

    int rows = in_image.rows;
    int cols = in_image.cols;
    rows = image_sz.height;
    cols = image_sz.width;
    
    for(int r {0}; r < rows; ++r)
    {
        for(int c {0}; c < cols; ++c)
        {
         // blue
         out_image.at<Vec3b>(r,c)[0] =
         saturate_cast<uchar>(contrast*(in_image.at<Vec3b>(r,c)[0]) + brightness );

         // green
         out_image.at<Vec3b>(r,c)[0] =
         saturate_cast<uchar>(contrast*(in_image.at<Vec3b>(r,c)[1]) + brightness );

         // red
         out_image.at<Vec3b>(r,c)[0] =
         saturate_cast<uchar>(contrast*(in_image.at<Vec3b>(r,c)[2]) + brightness );
        }
    }

    namedWindow(argv[1], WINDOW_AUTOSIZE);
    namedWindow("Altered Image", WINDOW_AUTOSIZE);
    imshow(argv[1], in_image);
    imshow("Altered Image", out_image);

    cout << "Press any key to exit...\n";
    waitKey();

    return 0;
}
