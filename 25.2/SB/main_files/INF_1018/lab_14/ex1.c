//Macro para para compor a representação de um valor float, dados seus componentes (s,frac,exp):
#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
//Macros para extrair as partes de um float a partir da sua representação:
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

typedef union { 
  float f;
  unsigned int i;
 } U;



 float float2(float f)
 {
    
 }