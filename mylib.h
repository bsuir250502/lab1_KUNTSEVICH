char * my_gets(char *s, size_t buf_size)
{
    char *result;
    result = fgets(s, buf_size, stdin);
    result[strlen(s) - 1 ] = '\0';
    return result;
}




















