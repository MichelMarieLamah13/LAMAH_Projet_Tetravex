#include "../headers/Solver.h"
#include <string>
Solver::Solver()
{
}

void Solver::solve(string dataFile, string solutionFile)
{
    plateau = Plateau(dataFile);
    pieces = plateau.getPieces();
    width = plateau.getFormat();
    size = width*width;
    if (width)
    {
        auto start = chrono::high_resolution_clock::now();
        Piece * solution = algorithm();
        auto end = chrono::high_resolution_clock::now();

        auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

        double s = duration.count() / 1e+9;

        string result = Helper::formatDate(s);

        printf("m = minutes\ns = seconde\nms = milliseconde\nus = microseconde\nns = nanoseconde\n");
        printf("Temps d'execution: %.9f s ==> %s \n\n", s, result.c_str());

        displaySolution(solution);
        recordSolutionTo(solutionFile, s, result);
    }else{
        cout <<"ERREUR: Les donnees non chargees correctement"<<endl;
    }
}

bool Solver::isValidMove(Piece * solution, Piece * piece, int index)
{
    int idxLeft = index - 1;
    int idxTop = index - width;
    int idxRight = index + 1;
    int idxBottom = index + size;

    // idx % f == 0 => nous sommes sur la première colonne
    // idxTop < 0 => nous sommes sur la première ligne
    // idxRight % f == 0 => nous sommes sur la dernière colonne
    // idxBottom > s => nous sommes sur la dernière colonne
    if (
        (index % width == 0 || solution[idxLeft].canBePlacedAtLeftOf(piece)) &&
        (idxTop < 0 || solution[idxTop].canBePlacedAtTopOf(piece)) &&
        (idxRight % width == 0 || solution[idxRight].canBePlacedAtRightOf(piece)) &&
        (idxBottom >= size || solution[idxBottom].canBePlacedAtBottomOf(piece)))
    {
        return true;
    }
    return false;
}

void Solver::displaySolution (Piece * solution)
{
    cout << "Format: " << width << " x " << width << endl;
    cout << "Etat Initial: " << endl;
    cout << plateau.formatPlateau(pieces) << endl;
    cout << "Etat Final: " << endl;
    cout << plateau.formatPlateau(solution) << endl;
}

void Solver::recordSolutionTo(string filename, double s, string t)
{
    ofstream myFile;
    myFile.open(filename, ios::app);
    myFile <<"\n"<< s <<";"<< t;
    myFile.close();
}