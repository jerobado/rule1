// Rule #1: Don't lose money

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

#define APP_NAME    "rule1"
#define VERSION     "0.1.3"


using namespace std;

void show_help(string name)
{
    cerr << "rule1 - Don't lose money.\n"
         << "Return the percentage of gain to breakeven.\n\n"
         << "Usage:\n"
         << "\t" <<  name << " <current loss>\n"
         << "Options:\n"
         << "\t -h, --help\t\tDisplay this help message.\n"
         << "\t -v, --version\t\tDisplay application version information."
         << endl;
}

double compute_breakeven(double loss)
{
    return ((loss / 100) * 1) / (1 - ((loss / 100) * 1)) * 100;
}

// [] TODO: use getopt()

int main(int argc, char **argv)
{
    int opt;
    string arg = "";
    string raw_input = "";


// using getopt() to properly parse the arguments
while ((opt = getopt(argc, argv, "hv")) != -1)
{
    switch (opt)
    {
        case 'h':
            show_help(APP_NAME);
            break;
        case 'v':
            printf("%s\n", VERSION);
            break;
        case '?':
            printf("unknown option %c\n", optopt);
//            show_help(APP_NAME);
            return 1;
    }
}


// not proper way to parse arguments
//    if (argc < 2)
//    {
//        show_help(APP_NAME);
//        return 1;
//    }

//    for (int i = 0; i < argc; i++)
//    {
//        arg = argv[i];
//        cout << "i: " << i << " arg: " << arg << endl;

//        // Positional arguments
//        if (i == 1)
//        {
//            // get user's input in string
//            raw_input = argv[i];
//            // convert string to float
//            loss = stod(raw_input);
//            // compute and display result
//            cout << compute_breakeven(loss) << endl;
//            break;
//        }

////        // Optional arguments
////        else if ((arg == "-h") || (arg == "--help"))
////        {
////            show_help(APP_NAME);
////            return 0;
////        }
////        else if ((arg == "-v") || (arg == "--version"))
////        {
////            cout << VERSION << endl;
////        }
//    }

    return 0;
}
