#ifndef PPM_FUNCTIONS_H
#define PPM_FUNCTIONS_H

void print_file_options();
void print_operation_options();
int get_user_input(int minIn, int maxIn);
bool open_files();
bool read_header_information();
void write_header_information();
void read_and_write_modified_pixels();

#endif