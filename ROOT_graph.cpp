#include <string>
#include <vector>
#include <stdio.h>

std::string SNAPSHOTS [] = {"pot_out", "U_psd_out",
    "phase_out", "mode_out", "field_out", "density_out"};
std::string SNAPSHOTS_Y_AXIS [] = {"Potential", "Power Density",
    "Velocity", "Mode Energy", "Electric Field", "Charge Density"};
std::string SNAPSHOTS_X_AXIS [] = {"Grid Cell", "Frequency",
    "Particle", "Mode", "", "Grid Cell"};
std::string TIME_HISTORIES [] = {"ke_out", "pe_out",
    "e_out", "mom_out"};
std::string TIME_HISTORIES_Y_AXIS [] = {"Kinetic Energy", "Potential Energy",
    "Total Energy", "Momentum"};

static TString GetID(int type)
{
    TString name;
    name.Form("%d",type);
    return name;
}
static void list_snapshot_files (std::string base_file_name,
        std::vector <std::string> *files)
{
    for (int i = 0; i < 9; i++){
        files->at (i) = GetID (i) + base_file_name;
    }
}

static void list_snapshot_titles (std::string base_file_name,
        std::vector <std::string> *files)
{
    for (int i = 0; i < 9 ; i++){
        files->at (i) = base_file_name + " " + GetID (i);
    }
}

static void load_files (std::string file_name, std::vector <double> *x,
        std::vector <double> *y)
{
    FILE *file = NULL;
    char *buffer = new char [1024];
    double tmpX,tmpY;

    if ((file = fopen (("data/"+file_name+".dat").c_str(), "r")) == NULL){
        printf ("Error opening file %s", ("data/"+file_name+".dat").c_str());
        return;
    }

    while (fgets (buffer, 1025, file) != NULL){
        sscanf (buffer, "%lf %lf", &tmpX, &tmpY);
        x->push_back(tmpX);
        y->push_back(tmpY);
    }

    fclose (file);
}

static TGraph *create_graph (std::string file_name, std::string title,
        std::string x_axis, std::string y_axis)
{
    std::vector <double> xVec;
    std::vector <double> yVec;

    load_files (file_name, &xVec, &yVec);

    int nPoints = xVec.size();

    TGraph* graph = new TGraph(nPoints,&xVec[0],&yVec[0]);
    graph->SetName(title.c_str());
    graph->SetTitle(title.c_str());
    graph->GetXaxis()->SetTitle(x_axis.c_str());
    graph->GetYaxis()->SetTitle(y_axis.c_str());

    return graph;
}

TCanvas *create_canvas (std::string title, int x_div, int y_div)
{
    TCanvas *canvas = new TCanvas (title.c_str(), title.c_str(), 800, 500);
    canvas->Divide (x_div, y_div);

    return canvas;
}

static void snapshot_graph ()
{
    std::vector <std::string> file_names (9);
    std::vector <std::string> titles (9);

    for (int i = 0; i < 6; i++){
        list_snapshot_files (SNAPSHOTS[i], &file_names);
        list_snapshot_titles (SNAPSHOTS[i], &titles);
        TCanvas *canvas = create_canvas (SNAPSHOTS [i],3,3);

        for (int j = 0; j < 9; j++){
            canvas->cd (j+1);
            TGraph *graph = create_graph (file_names[j],
                    titles [j],SNAPSHOTS_X_AXIS[i], SNAPSHOTS_Y_AXIS [i]);
            graph->Draw ("ap");
        }
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

    TCanvas *canvas = create_canvas ("Time Histories", 2, 2);
    for (int i = 0; i < 4; i++){
        canvas->cd (i+1);
        TGraph *graph = create_graph (TIME_HISTORIES[i], TIME_HISTORIES[i],
                "Iterations", TIME_HISTORIES_Y_AXIS[i]);
        graph->Draw ();
    }
}

void runner (){
    snapshot_graph ();
    history_graph ();
}