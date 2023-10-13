#include "../headers/Tetravex.h"
vector<string> Tetravex::FORMAT_NAMES = {
        "2x2",
        "3x3",
        "4x4",
        "5x5",
        "6x6",
        "7x7",
        "8x8"};


vector<string> Tetravex::ALGO_NAMES = {
        "Recursive (Sequentielle)",
        "Iterative (Sequentielle)",
        "ThreadPool (Multithread)",
        "ThreadVector (Multithread)"};


vector<string> Tetravex::ALGO_DIRS = {
    "recursive",
    "iterative",
    "thread_pool",
    "thread_vector"
};

Tetravex::Tetravex()
{
    
}

int Tetravex::choisirAlgoResolution()
{
    int algo = 0;
    int n = int(ALGO_NAMES.size());
    getchar();
    do
    {
        system("cls");
        printf("=============ALGORITHME=============\n");
        for (int i = 0; i < n; i++)
        {
            printf("[%d]->%s\n", i + 1, ALGO_NAMES[i].c_str());
        }
        printf("================================\n");
        printf("Veuillez choisir l'algo [1-%d]: ", n);
        scanf("%d", &algo);
    } while (algo < 1 || algo > n);
    return algo - 1;
}

int Tetravex::choisirFormat()
{
    int format = 0;
    int n = int(FORMAT_NAMES.size());
    do
    {
        system("cls");
        printf("=============FORMAT=============\n");
        for (int i = 0; i < n; i++)
        {
            printf("[%d]->Format %dx%d\n", (i + 2), (i + 2), (i + 2));
        }
        printf("================================\n");
        printf("Veuillez choisir le format [2-8]: ");
        scanf("%d", &format);
    } while (format < 2 || format > 8);

    return format;
}

void Tetravex::runSolver(int algo, int format)
{
    SolverFactory *factory = NULL;
    std::string title;

    SolverType solverType = static_cast<SolverType>(algo);

    cout << endl;
    switch (solverType)
    {
    case RECURSIVE:
        factory = new RecursiveFactory();
        break;
    case ITERATIVE:
        factory = new IterativeFactory();
        break;
    case THREAD_VECTOR:
        factory = new ThreadVectorFactory();
        break;
    case THREAD_POOL:
        factory = new ThreadPoolFactory();
        break;

    default:
        throw std::invalid_argument("ERREUR: Le type de solver choisi n'existe pas...");
    }

    Solver *solver = factory->createSolver();

    title = ALGO_NAMES[algo];
    cout << "══════════════════════════════════════════════════" << endl;
    cout << title << endl;
    cout << "══════════════════════════════════════════════════" << endl;

    string dataFileName = getDataFileName(format - 2);
    string solutionFileName = getSolutionFilenName(algo, format - 2);
    
    solver->solve(dataFileName, solutionFileName);

}

void Tetravex::jouer()
{
    int format = choisirFormat();

    printf("Vous avez choisi le format %s \n", FORMAT_NAMES[format - 2].c_str());

    printf("Appuyez une touche pour continuer pour choisir l'algorithme a utiliser");

    Helper::waitForUserInput();

    int algo = choisirAlgoResolution();

    printf("Vous voulez bien resoudre le format %s avec l'algo %s", FORMAT_NAMES[format - 2].c_str(), ALGO_NAMES[algo].c_str());

    Helper::waitForUserInput();

    runSolver(algo, format);
}

void Tetravex::jouer(int format, int algo)
{
    printf("Vous voulez bien resoudre le format %s avec l'algo %s", FORMAT_NAMES[format - 2].c_str(), ALGO_NAMES[algo].c_str());
    runSolver(algo, format);
}

string Tetravex::getDataFileName(int format){
    string result = "data/";
    result.append(FORMAT_NAMES[format]);
    result.append(".txt");
    return result;
}

string Tetravex::getSolutionFilenName(int algo, int format){
    string result = "solution/";
    result.append(ALGO_DIRS[algo]);
    result.append("/");
    result.append(FORMAT_NAMES[format]);
    result.append(".csv");
    return result;
}