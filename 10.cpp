#define MASK_BITS(x) ((x) & (unsigned int)0x0000FFFF)
unsigned long long int MapAddress(unsigned long long int address){
    unsigned long long int page = MASK_BITS(address);
    unsigned long long int offset = MASK_BITS(address);

    printf("The mapped address %llu contains:\n", address);

    page = page >> 13;
    printf("Page Number : %llu\n", page);

    offset = offset & 0x1FFF;

    printf("Offset = %llu\n\n", offset);
    return 0;
}
void myFunction()
{
    FILE *fp = fopen("/PATH/TO/addresses.txt", "r");
    char buffer[32];
    unsigned long long int x;
    int cnt = 1;
    while(!feof(fp)){
        fscanf(fp, "%s", buffer);
        x = atol(buffer);
        MapAddress(x);
        cnt++;
    }

    fclose(fp);
    return;
}