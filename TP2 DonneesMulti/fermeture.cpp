
#include<stdio.h>
#include "Image_ppm.h"

void erosion(OCTET *ImgIn,OCTET *ImgOut, int nW, int nH){
  for (int i=1; i < nH-1; i++){

   for (int j=1; j < nW-1; j++)

     {

         if (ImgIn[i*nW+j]==255)

         {

            if (ImgIn[i*nW+j+1]==0)

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[i*nW+j-1]==0)

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[(i-1)*nW+j]==0)

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[(i+1)*nW+j]==0) 

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[(i+1)*nW+j+1]==0) 

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[(i+1)*nW+j-1]==0) 

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[(i-1)*nW+j+1]==0) 

            {

                ImgOut[i*nW+j]=0;

            }

            else if (ImgIn[(i-1)*nW+j-1]==0) 

            {

                ImgOut[i*nW+j]=0;

            }

            else

            {

                ImgOut[i*nW+j]=255;

            }

         }

         else

         {

            ImgOut[i*nW+j]=0;

         }

            

     }

  }
}

void dilatation(OCTET *ImgIn, OCTET *ImgOut, int nW, int nH){
  for (int i=1; i < nH-1; i++){

   for (int j=1; j < nW-1; j++)

     {

         if (ImgIn[i*nW+j]==0)

         {

            if (ImgIn[i*nW+j+1]==255)

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[i*nW+j-1]==255)

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[(i-1)*nW+j]==255)

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[(i+1)*nW+j]==255) 

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[(i+1)*nW+j+1]==255) 

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[(i+1)*nW+j-1]==255) 

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[(i-1)*nW+j+1]==255) 

            {

                ImgOut[i*nW+j]=255;

            }

            else if (ImgIn[(i-1)*nW+j-1]==255) 

            {

                ImgOut[i*nW+j]=255;

            }

            else

            {

                ImgOut[i*nW+j]=0;

            }

         }

         else

         {

            ImgOut[i*nW+j]=255;

         }

            

     }

  }
}

  int main(int argc,char* argv[])
{
  char cNomImgLue[250], cNomImgEcrite[250];
  int nH, nW, nTaille;

  if (argc != 3)
    {
      printf("Usage: ImageIn.pgm ImageOut.pgm \n");
      exit(1);
    }

   sscanf (argv[1],"%s",cNomImgLue) ;
   sscanf (argv[2],"%s",cNomImgEcrite);

   OCTET *ImgIn, *ImgOut;
   
   lire_nb_lignes_colonnes_image_pgm(cNomImgLue, &nH, &nW);
   nTaille = nH * nW;
  
   allocation_tableau(ImgIn, OCTET, nTaille);
   lire_image_pgm(cNomImgLue, ImgIn, nH * nW);
   allocation_tableau(ImgOut, OCTET, nTaille);


   dilatation(ImgIn,ImgOut, nH,nW);
  
   for(int i=0;i<nH*nW;i++){
     ImgIn[i] = ImgOut[i];
   }

    erosion(ImgIn, ImgOut,nH,nW);

   ecrire_image_pgm(cNomImgEcrite,ImgOut, nH, nW);
   free(ImgIn); free(ImgOut);

   return 1;
}
