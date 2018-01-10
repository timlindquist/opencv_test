#include <stdio.h>
#include <highgui.h>

int main(int argc, char *argv[])
{
    // load image from file
    IplImage* img = NULL;
    img = cvLoadImage("/Users/timlindquist/Desktop/cicada.jpg", CV_LOAD_IMAGE_UNCHANGED);
    if (!img)
    {
        printf("Could not load image file: %s\n", argv[1]);
        exit(0);
    }
    
    // create window and show image
    cvNamedWindow("mainWin", CV_WINDOW_NORMAL);
    cvShowImage("mainWin", img);
    
    // workaround to send window to the top
    cvMoveWindow("mainWin", 100, 100);
    cvSetWindowProperty("mainWin", CV_WND_PROP_FULLSCREEN, CV_WINDOW_FULLSCREEN);
    cvSetWindowProperty("mainWin", CV_WND_PROP_FULLSCREEN, CV_WINDOW_NORMAL);
    
    // free resources
    cvReleaseImage(&img);
    cvWaitKey(0);
    cvDestroyWindow("mainWin");
    return 0;
}

