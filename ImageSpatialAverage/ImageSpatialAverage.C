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

    namedWindow(argv[1], WINDOW_AUTOSIZE);
    imshow(argv[1], in_image);

    Mat out_image;
    int kernel_size = atoi(argv[2]);
    blur(in_image, out_image, Size(kernel_size, kernel_size));

    namedWindow("Altered Image", WINDOW_AUTOSIZE);
    imshow("Altered Image", out_image);

    cout << "Press any key to exit...\n";
    waitKey();

    return 0;
}
