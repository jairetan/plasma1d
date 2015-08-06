#include <string>
#include <vector>
#include <stdio.h>

static const std::string SNAPSHOTS [] = {"pot_out", "U_psd_out",
    "phase_out", "mode_out", "field_out", "density_out"};
static const std::string TIME_HISTORIES [] = {"ke_out", "pe_out",
    "e_out", "mom_out"};

TString GetID(int type)
{
    TString name;
    name.Form("%d",type);
    return name;
}

//Works
TGraph *create_graph (std::string file_name, std::string title,
        std::string x_axis, std::string y_axis)
{
    FILE *file = NULL;
    char *buffer = new char [1024];

    if ((file = fopen (("data/"+file_name+".dat").c_str(), "r")) == NULL){
        printf ("Error opening file %s", ("data/"+file_name+".dat").c_str());
        return NULL;
    }

    std::vector<double> xVec,yVec;
    double tmpX,tmpY;
    while (fgets (buffer, 1025, file) != NULL){
        sscanf (buffer, "%lf %lf", &tmpX, &tmpY);
        xVec.push_back(tmpX);
        yVec.push_back(tmpY);
    }

    fclose (file);

    int nPoints = xVec.size();
    double x[nPoints],y[nPoints];
    for (int i=0; i<nPoints; i++){
        x[i] = xVec[i];
        y[i] = yVec[i];
    }

    TGraph* graph = new TGraph(nPoints,x,y);
    graph->SetName(title.c_str());
    graph->SetTitle(title.c_str());
    graph->GetXaxis()->SetTitle(x_axis.c_str());
    graph->GetYaxis()->SetTitle(y_axis.c_str());

    return graph;
}

void create_canvas (std::string title, std::vector <std::string> *files,
        std::vector <std::string> *titles, std::string x_axis,
        std::string y_axis, int x_div, int y_div, std::string graph_options = "")
{
    TCanvas *canvas = new TCanvas (title.c_str(), title.c_str(), 900, 700);
    TGraph *graph = NULL;
    canvas->Divide (x_div, y_div);

    for (int i = 0; i < x_div*y_div; i++){
        canvas->cd (i+1);
        graph = create_graph (files->at(i), titles->at(i), x_axis, y_axis);
        graph->Draw(graph_options);
    }
}

//Works
void list_snapshot_files (std::string base_file_name,
        std::vector <std::string> *files)
{
    for (int i = 0; i < 9; i++){
        files->at (i) = GetID (i) + base_file_name;
    }
}

void list_snapshot_titles (std::string base_file_name,
        std::vector <std::string> *files)
{
    for (int i = 0; i < 9 ; i++){
        files->at (i) = base_file_name + " " + GetID (i);
    }
}

static void snapshot_graph ()
{
    std::vector <std::string> file_names (9);
    std::vector <std::string> titles (9);

    for (int i = 0; i < 6; i++){
        list_snapshot_files (SNAPSHOTS[i], &file_names);
        list_snapshot_titles (SNAPSHOTS[i], &titles);
        create_canvas (SNAPSHOTS [i], &file_names, &titles,
                "test x", "test y", 3,3);
    }
}

static void history_graph ()
{
    std::vector <std::string> files (4);
    std::vector <std::string> titles (4);

    for (int i = 0; i < 4; i++){
        files [i] = TIME_HISTORIES [i];
        titles [i] = TIME_HISTORIES [i];
    }

     create_canvas ("Time Histories", &files,
            &titles, "Iterations",
            "TestY", 2, 2);

}

void runner (){
    snapshot_graph ();
    history_graph ();
}
