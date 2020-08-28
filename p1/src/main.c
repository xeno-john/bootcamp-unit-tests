#include "p1.h"

#define NR_OF_BITS_NEEDED 33

int main(void)
{
        uint32_t    input_value = 0;
        int  was_read_correctly = 1;
        char  *output_buffer = NULL;

        was_read_correctly = validate_input(&input_value);
        
        if(0 != was_read_correctly)
        {                

                output_buffer = print_bits(input_value);

                if (NULL != output_buffer)
                {
                        printf("The configuration in bits for the number you gave:");
                        printf("\n%s\n",output_buffer);
                }
                else
                {
                        fprintf(stderr,"Failed to allocate memory for output_buffer in print_bits function at line %d\n",__LINE__);
                }
                        
        }

	return 0;
}