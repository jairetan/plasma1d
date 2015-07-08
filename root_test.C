#include "TString.h"
#include "TInterpreter.h"
#include <fstream>
#include "TH1.h"
#include "TGraphSmooth.h"
#include "TCanvas.h"
#include "TSystem.h"

TCanvas *vC1;

/*xt is x title yt is y title, pad is position of panel?*/
void Draw (Int_t pad, const char *title, const char *xt, const char *yt, TGraph *graph)
{
    vC1->cd(pad);
    TH1F *vFrame = gPad->DrawFrame(0,-.04,.01,.1);
    vFrame->SetTitle(title);
    vFrame->SetTitleSize(0.2);
    vFrame->SetXTitle(xt);
    vFrame->SetYTitle(yt);
    graph->Draw("P*L"); //draw points?
    //grout->DrawClone("LPX"); //draw a clone of this object in the current "pad" (panel)
}

void helper (const char *path, TString dir, int pad)
{
    // read file and add to fit object
    Double_t *x = new Double_t[10000];
    Double_t *y = new Double_t[10000];
    Double_t vX, vY;
    Int_t vNData = 0;
    ifstream vInput;
    vInput.open(Form("%s%s",dir.Data(), path)); //add in path name
    while (1) {
        vInput >> vX >> vY;
        if (!vInput.good()) break;
        x[vNData] = vX;
        y[vNData] = vY;
        vNData++;
    }//while

    vInput.close();
    TGraph *grin = new TGraph(vNData,x,y);

    TGraphSmooth *gs = new TGraphSmooth("normal");
    Draw (pad,"Total Momentum","time","momentum", grin);

    delete [] x;
    delete [] y;
}

void root_test()
{
    TString dir = gSystem->UnixPathName(__FILE__);
    dir.ReplaceAll("root_test.C","");
    dir.ReplaceAll("/./","/");

    /*canvas is the main frame*/
    vC1 = new TCanvas("vC1","Diagnostics",200,10,900,700);
    vC1->Divide(1,2); //Divide (columns, rows);

    helper ("mom_data.dat", dir, 1);
    helper ("nrg_data.dat", dir, 2);

    //// read file and add to fit object
    //Double_t *x = new Double_t[10000];
    //Double_t *y = new Double_t[10000];
    //Double_t vX, vY;
    //Int_t vNData = 0;
    //ifstream vInput;
    //vInput.open(Form("%smom_data.dat", dir.Data())); //add in path name
    //while (1) {
        //vInput >> vX >> vY;
        //if (!vInput.good()) break;
        //x[vNData] = vX;
        //cout << vX << "\n";
        //y[vNData] = vY;
        //vNData++;
    //}//while

    //vInput.close();
    //grin = new TGraph(vNData,x,y);

    //TGraphSmooth *gs = new TGraphSmooth("normal");
    //Draw (1,"Total Momentum","time","momentum", grin);

    //delete [] x;
    //delete [] y;
}
