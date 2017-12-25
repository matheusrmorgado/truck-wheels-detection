#include <cekeikon.h>

int main(int argc, char** argv) 
{
	if (argc!=2 && argc!=3) 
	{
		printf("\n\tExemplo de entrada: gradiente imagem.png [gaussDev]\n\n\t");
		erro("Erro: Numero de argumentos invalido");
	}
    
 	Mat_<COR> image;
    string file = argv[1];
    le( image, file );

    Mat_<COR> red( image.rows, image.cols);
	Mat_<COR> gre( image.rows, image.cols);
	Mat_<COR> blu( image.rows, image.cols);	

	for (int l=0; l<image.rows; l++)
	{
		for (int c=0; c<image.cols; c++)
		{
			red(l,c) = COR( 0, 0, image(l,c)[2]);
			gre(l,c) = COR( 0, image(l,c)[1], 0);
			blu(l,c) = COR( image(l,c)[0], 0, 0);
		}
	}

	Mat_<GRY> image_gray;
	cvtColor(image, image_gray, COLOR_BGR2GRAY);
	Mat_<CPX> image_c = gradienteScharr(image_gray,true);

	Mat_<GRY> gre_gray;
	cvtColor(gre, gre_gray, COLOR_BGR2GRAY);
	Mat_<GRY> red_gray;
	cvtColor(red, red_gray, COLOR_BGR2GRAY);	
	Mat_<GRY> blu_gray;
	cvtColor(blu, blu_gray, COLOR_BGR2GRAY);

	if (argc==3) 
	{
		double gaussDev;
		convArg(gaussDev,argv[2]);
		GaussianBlur(gre_gray,gre_gray,Size(0,0),gaussDev,gaussDev);
		GaussianBlur(red_gray,red_gray,Size(0,0),gaussDev,gaussDev);
		GaussianBlur(blu_gray,blu_gray,Size(0,0),gaussDev,gaussDev);
		file.erase( file.end()-4, file.end() );
		file = file + "-grad-otimizado-" + argv[2];
	}else{
		file.erase( file.end()-4, file.end() );
		file = file + "-grad-otimizado";
	}

	Mat_<CPX> gre_c = gradienteScharr(gre_gray,true);
	Mat_<CPX> red_c = gradienteScharr(red_gray,true);
	Mat_<CPX> blu_c = gradienteScharr(blu_gray,true);

	for (int i=0; i<gre_c.rows; i++) {
		for (int j=0; j<gre_c.cols; j++){
			if( ( abs(gre_c(i,j)) > abs(blu_c(i,j)) ) && ( abs(gre_c(i,j)) > abs(red_c(i,j)) ) )
			{
				image_c(i,j) = gre_c(i,j);
			}
			else{
				if( abs(blu_c(i,j)) > abs(red_c(i,j)) ){
					image_c(i,j) = blu_c(i,j);
				}
				else{
					image_c(i,j) = red_c(i,j);
					image_c(i,j) = red_c(i,j);
				}
			}
		}
	}
	
	imp( gre_c, file + "-g.png");
	imp( red_c, file + "-r.png");
	imp( blu_c, file + "-b.png");
	imp( image_c, file + ".png" );
	cout << "\n\tImagem " + file + " gerada com sucesso" << endl;
}
