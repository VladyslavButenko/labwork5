#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static int verbose_flag;

int main (int argc, char **argv)
{
  int c;
  int aopt = 0, bopt = 0, lflag = 0, fflag = 0;

  while (true)
    {
      static struct option long_options[] =
        {
          /* These options set a flag. */
          {"verbose", no_argument,       &verbose_flag, 1},
          /* These options don’t set a flag.
             We distinguish them by their indices. */
          {"option1",     no_argument,       0, 'o'},
          {"option2",  no_argument,       0, 'O'},
          {"list", no_argument, 0, 'l'},
          {"file", no_argument, 0, 'f'},
          {0, 0, 0, 0}
        };
      /* getopt_long stores the option index here. */
      int option_index = 0;

      c = getopt_long (argc, argv, "oOlf",
                       long_options, &option_index);

      /* Detect the end of the options. */
      if (c == -1)
        break;

      switch (c)
        {
        case 0:
	  if (long_options[option_index].flag != 0)
            break;
          printf ("option %s", long_options[option_index].name);
          if (optarg)
            printf (" with arg %s", optarg);
          printf ("\n");
          break;

        case 'o':
	  if (aopt == 0) {
          	puts ("option -o");
		aopt = 1;
	  }
          break;

        case 'O':
	  if (bopt == 0) {
          	puts ("option -O");
		bopt = 1;
	  }
          break;

        case 'l':
	  if (lflag == 0) {
          	puts ("option -l");
		lflag = 1;
	  }	
	  break;

        case 'f':
	  if (fflag == 0) {
          	puts ("option -f");
          	fflag = 1;
	  }	
	  break;


        case '?':
          break;

        default:
          abort ();
        }
    }

  if (verbose_flag)
    puts ("\nverbose flag is set");

  if (optind < argc)
    {
      printf ("non-option ARGV-elements: ");
      while (optind < argc)
        printf ("%s ", argv[optind++]);
      putchar ('\n');
    }

  exit (0);
}
