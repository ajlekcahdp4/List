enum ERRORS {
    ERR_LIST_ZERO_POINTER, 
    ERR_LIST_UNDERFLOW
};

FILE* HtmlStart (char* logname);
void PrintError (FILE* logfile, int Err);
void ImportPicture (FILE* logfile, char* PicName);
void HtmlEnd (FILE* logfile);
