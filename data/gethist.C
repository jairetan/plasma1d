#include <fstream>

TH1D* GetHistogram(std::string fileName,double xLo, double xHi, int nBins = 200)
{
  std::ifstream in;
	in.open(fileName);
	
	double tmp;
	TH1D* myHist = new TH1D("myHist","My Histogram;x;y",nBins,xLo,xHi);
	while (!in.eof()){
		in>>tmp;
		myHist->Fill(tmp);
	}
	in.close();
	return myHist;
}
