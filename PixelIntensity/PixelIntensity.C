#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat in_image, out_image;

    in_image = imread(argv[1], IMREAD_UNCHANGED);
    if (in_image.empty())
    {

        cout << "Error! Input image cannot be read...\n";
        return -1;
    }

    namedWindow(argv[1], WINDOW_AUTOSIZE);
    namedWindow(argv[2], WINDOW_AUTOSIZE);
    namedWindow(argv[3], WINDOW_AUTOSIZE);

    cvtColor(in_image, out_image, COLOR_BGR2GRAY);
    imshow(argv[1], in_image);
    imshow(argv[2], out_image);

    Size image_sz = in_image.size();
    int rows = in_image.rows;
    int cols = in_image.cols;
    rows = image_sz.height;
    cols = image_sz.width;
    
    float intense = atoi(argv[4]);
    for(int r {0}; r < rows; ++r)
    {
        for(int c {0}; c < cols; ++c)
        {
            out_image.at<uchar>(r, c) /= intense;
        }
    }

    imshow(argv[3], out_image);

    cout << "Press any key to exit...\n";
    waitKey();

    return 0;
}
