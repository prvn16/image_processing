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
    namedWindow(argv[1], WINDOW_AUTOSIZE);
    imshow(argv[1], in_image);

    int rows = in_image.rows;
    int cols = in_image.cols;
    rows = image_sz.height;
    cols = image_sz.width;
    Mat out_image;
    
    for(int r {0}; r < rows; ++r)
    {
        for(int c {0}; c < cols; ++c)
        {
             for(int i {0}; i < 3; ++i)
             {
                 in_image.at<Vec3b>(r,c)[i] = 128;
                 //    saturate_cast<uchar>(in_image.at<Vec3b>(r,c)[i]);
             }
        }
    }

    out_image = in_image;
    namedWindow("Altered Image", WINDOW_AUTOSIZE);
    imshow("Altered Image", in_image);

    cout << "Press any key to exit...\n";
    waitKey();

    return 0;
}
