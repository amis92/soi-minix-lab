#define TRUE 1


int main(int argc, char* argv[])
{
  int index, result;
  result = 1;
  while (TRUE)
  {
    result = result * index;
    index = result % index;
  }
  return 0;
}