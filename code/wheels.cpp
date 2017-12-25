#include <cekeikon.h>

int main(int argc, char** argv) 
{ 
    if (argc!= 2)
    {
        printf("\n\tExemplo de entrada: wheels video.avi\n\n\t");
        erro("Erro: Numero de argumentos invalido");
    }
    
    /// Read the video
    string file = argv[1];
    VideoCapture vi(file);

    float fps = vi.get(CV_CAP_PROP_FPS);
    int nc = vi.get(CV_CAP_PROP_FRAME_WIDTH);
    int nl = vi.get(CV_CAP_PROP_FRAME_HEIGHT);
    int frames = vi.get(CV_CAP_PROP_FRAME_COUNT);
 
    /// Creat new video
    file.erase( file.end()-4, file.end() );
    file += "-detection.avi";
    VideoWriter vo(file, CV_FOURCC('X','V','I','D'), fps, Size(nc,nl));

    Mat_<COR> src;
    Mat_<GRY> src_gray;
   
    for (int i = 1; i <= frames; i++)
    {
        /// Convert it to gray
        vi >> src;
        cvtColor(src, src_gray, COLOR_BGR2GRAY);
        
        /// Reduce the noise so we avoid false circle detection
        GaussianBlur( src_gray, src_gray, Size(0,0), 2.0, 2.0 );        
        Canny( src_gray, src_gray, 50, 150, 3 );

        GaussianBlur( src_gray, src_gray, Size(9, 9), 2, 2 );
        
        vector<Vec3f> circles;

        /// Apply the Hough Transform to find the circles
        HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, 200, 100, 0, 0 );

        /// Draw the circles detected
        for( size_t i = 0; i < circles.size(); i++ )
        {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            // Draw the circle center
            circle( src, center, 3, Scalar(255,255,0), -1, 8, 0 );
            // Draw the circle outline
            circle( src, center, radius, Scalar(0,255,255), 2, 8, 0 );
        }
        
        /*
        if (i == 450)
        	imp( src, "quad450-detection.png" );
        */
        
        /// Show your results
        vo << src;
        //namedWindow("Video Test",0);
        //imshow("Video Test", src);
        //if(waitKey(30) >= 0) break;
    }
    cout << "\n\t" + file + " gerado com sucesso\n";
    //destroyAllWindows();
}