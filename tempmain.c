#include <stdio.h>
#include <stdlib.h>

void check_cmd_line_args(int argc) {
    if (argc < 3){
        printf("Not enough arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(23);        
    }
    if (argc > 3) {
        printf("Too many arguments entered\n");
        printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win");
        exit(23);  

    }
}

int get_row_from_cmd_line(int argc, char** argv) {
    check_cmd_line_args(argc);
    int rows;
    char should_be_blank;
    int num_args_read = sscanf(argv[1], "%d %c", &rows, &should_be_blank);
    if(num_args_read != 1){
        printf("Rows needs to be an integer. Found %s\n", argv[1]);
        exit(23);
    }
    return rows;
    

}
int get_col_from_cmd_line(int argc, char** argv) {
    check_cmd_line_args(argc);
    int columns;
    char should_be_blank;
    int num_args_read = sscanf(argv[2], "%d %c", &columns, &should_be_blank);
    if(num_args_read != 1){
        printf("Columns needs to be an integer. Found %s\n", argv[1]);
        exit(23);
    }
    return columns;
    

}

int get_N_from_cmd_line(int argc, char** argv) {
    check_cmd_line_args(argc);
    int winNum;
    char should_be_blank;
    int num_args_read = sscanf(argv[3], "%d %c", &winNum, &should_be_blank);
    if(num_args_read != 1){
        printf("WinNum needs to be an integer. Found %s\n", argv[1]);
        exit(23);
    }
    return winNum;
    

}

int main(int argc, char** argv) {
    int rows = get_row_from_cmd_line(argc, argv);
    int columns = get_col_from_cmd_line(argc, argv);
    int winNum = get_N_from_cmd_line(argc, argv);
    printf("%d\n", rows);
    printf("%d\n", columns);
    printf("%d\n", winNum);

    return 0;

}