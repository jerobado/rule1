// Rule #1: Don't lose money

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <getopt.h>

#define APP_NAME    "rule1"
#define VERSION     "v0.1.4"


using namespace std;

void show_help(string name)
{
    cerr << "Rule #1 - Don't lose money.\n\n"
         << "Usage:\n"
         << "\t$ " <<  name << " 50\n"
         << "\t" <<"+100.00% needed gain just to recover your current loss\n"
         << "Options:\n"
         << "\t -h, --help\t\tDisplay this help message.\n"
         << "\t -v, --version\t\tDisplay application version information."
         << endl;
}

double compute_breakeven(double loss)
{
    return ((loss / 100) * 1) / (1 - ((loss / 100) * 1)) * 100;
}

int main(int argc, char **argv)
{
    int opt;
    double loss;
    string arg = "";
    string raw_input = "";

// [] TODO: getopt_long()
while ((opt = getopt(argc, argv, "-hv")) != -1)
{
    switch (opt)
    {
        case 1:
            try
            {
                // get argument
                loss = stod(optarg);
                printf("+%.2f%% needed gain just to recover your current loss\n", compute_breakeven(loss));
            }
            catch (exception&)
            {
                printf("'%s' -> should be a number\n", optarg);
            }
            break;
        case 'h':
            show_help(APP_NAME);
            break;
        case 'v':
            printf("%s\n", VERSION);
            break;
        case '?':
            printf("unknown option %c\n", optopt);
            show_help(APP_NAME);
            return 1;
    }
}

    return 0;
}
