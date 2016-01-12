#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        cout << "Invalid number of parameters" << endl;
        return 1;
    }

    Mat InImage = imread(argv[1], IMREAD_UNCHANGED);
    if (InImage.empty())
    {

        cout << "Error! Input image cannot be read...\n";
        return -1;
    }

    namedWindow(argv[1], WINDOW_AUTOSIZE);
    namedWindow("Modified Image", WINDOW_AUTOSIZE);
    namedWindow("Tile", WINDOW_AUTOSIZE);

    Mat InImageClone;
    cvtColor(InImage, InImageClone, COLOR_BGR2GRAY);

    Size ImageSz = InImageClone.size();
    int rows = ImageSz.height;
    int cols = ImageSz.width;
    //cout << "Image size: " << rows << "x" << cols << endl;

    int N = atoi(argv[2]);
    Mat DctImage;
    for (int r = 0; r < rows; r += N)
    {
        for (int c = 0; c < cols; c += N)
        {
            Mat srcTile = InImageClone(Range(r, min(r + N, InImageClone.rows)),
                       Range(c, min(c + N, InImageClone.cols)));

            int w = srcTile.cols;
            int h = srcTile.rows;
            int w2, h2;

            if (w % 2 == 0)
            {
                w2 = w;
            }
            else
            {
                w2 = w+1;
            }

            if (h % 2 == 0)
            {
                h2 = h;
            }
            else
            {
                h2 = h+1;
            }
            Mat destTile;
            copyMakeBorder(srcTile, destTile, 0, h2-h, 0, w2-w, IPL_BORDER_REPLICATE);

            Mat destTileFloat = Mat( destTile.rows, destTile.cols, CV_64F);
            destTile.convertTo(destTileFloat, CV_64F);
 
            Mat freq;
            dct(destTileFloat, freq);
        }
    }

    imshow(argv[1], InImage);
    //imshow("Modified Image", DctImage);

    waitKey();

    destroyAllWindows();

    return 0;
}
