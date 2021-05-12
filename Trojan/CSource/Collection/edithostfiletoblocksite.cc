FILE *fp;
int i;
char hosts_file_path[FILENAME_MAX];
char ip[] = "0.0.0.0";
 
/* Add your sites in the below list. */
char *blist[] = {
  "www.orkut.com",
  "orkut.com",
  "www.google.com",
  "google.com",
  "www.google.co.in",
  "google.co.in",
  "www.gmail.com",
  "gmail.com",
  "www.facebook.com",
  "facebook.com",
  "www.yahoo.com",
  "yahoo.com",
  "www.twitter.com",
  "twitter.com",
  "#"
};
 
strcpy (hosts_file_path, getenv ("SystemRoot"));
strcat (hosts_file_path, "\\system32\\drivers\\etc\\hosts");
 
if ((fp = fopen (hosts_file_path, "a")) == NULL)
  return 0;
 
fputs ("\n", fp);
for (i = 0; blist[i][0] != '#'; i++)
  {
    fputs (ip, fp);
    fputs ("        ", fp);
    fputs (blist[i], fp);
    fputs ("\n", fp);
  }
 
fclose (fp);
system("echo ' '");
return 0;
