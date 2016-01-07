#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void rotate(Mat& src, double angle, Mat& dst)
{
    int len = std::max(src.cols, src.rows);
    Point2f pt(len/2., len/2.);
    Mat r = getRotationMatrix2D(pt, angle, 1.0);

    warpAffine(src, dst, r, Size(len, len));
}

int main(int argc, char **argv)
{
    Mat in_image = imread(argv[1], IMREAD_UNCHANGED);
    if (in_image.empty())
    {

        cout << "Error! Input image cannot be read...\n";
        return -1;
    }

    namedWindow("Input Image", WINDOW_AUTOSIZE);
    imshow("Input Image", in_image);

    Mat out_image;
    double rotation = strtod(argv[2], NULL);
    rotate(in_image, rotation, out_image);

    namedWindow("Altered Image", WINDOW_AUTOSIZE);
    imshow("Altered Image", out_image);

    cout << "Press any key to exit...\n";
    waitKey();

    return 0;
}
