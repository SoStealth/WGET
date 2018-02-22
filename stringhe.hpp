/*
stringhe.h
*/
void* duplica(char* buffer, int* length) {
	char* ret = (char*)malloc(sizeof(char*)*(*length+1));
	for(int i=0;i<=*length;i++)
		*(ret+i)=*(buffer+i);
	return ret;
}
char* concat(char* first_string,char* second_string) {
	char* ret=(char*)malloc(strlen(first_string)+strlen(second_string)+1);
	char* tmp = ret;

	for(;*tmp = *first_string; tmp++, first_string++) { }
	for(;*tmp = *second_string; tmp++, second_string++) { }

	return ret;
}
