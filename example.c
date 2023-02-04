// example.c

#include "arg_parser.h"

typedef struct {
  i32 verbose;
  char* filename;
  f32 factor;
} Options;

int main(int argc, char** argv) {
  Options options = {
    .filename = "example.c",
    .verbose = 0,
    .factor = 0.0f,
  };
  // this is completely optional
  arg_parser_init(
    1, // always print argument type
    4, // padding to description
    4  // indentation for each argument entry
  );
  Parse_arg args[] = {
    {0, NULL, "filename", ArgString, 0, &options.filename},
    {'v', "verbose", "enable verbose output", ArgInt, 0, &options.verbose},
    {'f', "factor", "factor that does something", ArgFloat, 1, &options.factor},
  };
  if (argc <= 1) {
    args_print_help(stdout, args, ARRAY_LENGTH(args), argv);
    return 0;
  }
  ParseResult result = parse_args(args, ARRAY_LENGTH(args), argc, argv);
  if (result == ArgParseOk) {
    printf(
        "options:\n"
        "  filename = %s\n"
        "  verbose = %d\n"
        "  factor = %g\n"
        ,
        options.filename,
        options.verbose,
        options.factor
    );
  }
  return 0;
}
