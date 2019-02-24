#ifndef _ARCHIVOS_H_
#define _ARCHIVOS_H_

void abrirL(FILE*&);
void abrirE(FILE*&);
template<typename T>T leer(FILE*);
template<typename T>void escribir(FILE*,T);
void cerrar(FILE*);
#endif
