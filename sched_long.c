#define TRUE 1


int main()
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