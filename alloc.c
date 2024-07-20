#ifndef STDLIB_H_
#include <stdlib.h>	/* for malloc(), realloc() */
#endif

/* must include complex.c*/

/* allocate a 1-d array */
void *alloc1 (size_t n1, size_t size)
{
	void *p;

	if ((p=malloc(n1*size))==NULL)
		return NULL;
	return p;
}

/* re-allocate a 1-d array */
void *realloc1(void *v, size_t n1, size_t size)
{
	void *p;

	if ((p=realloc(v,n1*size))==NULL)
		return NULL;
	return p;
}

/* free a 1-d array */
void free1 (void *p)
{
	free(p);
}

/* allocate a 2-d array */
void **alloc2 (size_t n1, size_t n2, size_t size)
{
	size_t i2;
	void **p;

	if ((p=(void**)malloc(n2*sizeof(void*)))==NULL) 
		return NULL;
	if ((p[0]=(void*)malloc(n2*n1*size))==NULL) {
		free(p);
		return NULL;
	}
	for (i2=0; i2<n2; i2++)
		p[i2] = (char*)p[0]+size*n1*i2;
	return p;
}

/* free a 2-d array */
void free2 (void **p)
{
	free(p[0]);
	free(p);
}

/* allocate a 3-d array */
void ***alloc3 (size_t n1, size_t n2, size_t n3, size_t size)
{
	size_t i3,i2;
	void ***p;

	if ((p=(void***)malloc(n3*sizeof(void**)))==NULL)
		return NULL;
	if ((p[0]=(void**)malloc(n3*n2*sizeof(void*)))==NULL) {
		free(p);
		return NULL;
	}
	if ((p[0][0]=(void*)malloc(n3*n2*n1*size))==NULL) {
		free(p[0]);
		free(p);
		return NULL;
	}

	for (i3=0; i3<n3; i3++) {
		p[i3] = p[0]+n2*i3;
		for (i2=0; i2<n2; i2++)
			p[i3][i2] = (char*)p[0][0]+size*n1*(i2+n2*i3);
	}
	return p;
}

/* free a 3-d array */
void free3 (void ***p)
{
	free(p[0][0]);
	free(p[0]);
	free(p);
}

/* allocate a 4-d array */
void ****alloc4 (size_t n1, size_t n2, size_t n3, size_t n4, size_t size)
{
	size_t i4,i3,i2;
	void ****p;

	if ((p=(void****)malloc(n4*sizeof(void***)))==NULL)
		return NULL;
	if ((p[0]=(void***)malloc(n4*n3*sizeof(void**)))==NULL) {
		free(p);
		return NULL;
	}
	if ((p[0][0]=(void**)malloc(n4*n3*n2*sizeof(void*)))==NULL) {
		free(p[0]);
		free(p);
		return NULL;
	}
	if ((p[0][0][0]=(void*)malloc(n4*n3*n2*n1*size))==NULL) {
		free(p[0][0]);
		free(p[0]);
		free(p);
		return NULL;
	}
	for (i4=0; i4<n4; i4++) {
		p[i4] = p[0]+i4*n3;
		for (i3=0; i3<n3; i3++) {
			p[i4][i3] = p[0][0]+n2*(i3+n3*i4);
			for (i2=0; i2<n2; i2++)
				p[i4][i3][i2] = (char*)p[0][0][0]+
						size*n1*(i2+n2*(i3+n3*i4));
		}
	}
	return p;
}

/* free a 4-d array */
void free4 (void ****p)
{
	free(p[0][0][0]);
	free(p[0][0]);
	free(p[0]);
	free(p);
}

/* The following two functions were added by Zhaobo Meng, Jan. 1997*/
/* allocate a 5-d array */
void *****alloc5 (size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t size)
{
	size_t i5,i4,i3,i2;
	void *****p;

	if ((p=(void*****)malloc(n5*sizeof(void****)))==NULL)
		return NULL;
	if ((p[0]=(void****)malloc(n5*n4*sizeof(void***)))==NULL) {
		free(p);
		return NULL;
	}
	if ((p[0][0]=(void***)malloc(n5*n4*n3*sizeof(void**)))==NULL) {
		free(p[0]);
		free(p);
		return NULL;
	}
	if ((p[0][0][0]=(void**)malloc(n5*n4*n3*n2*sizeof(void*)))==NULL) {
		free(p[0][0]);
		free(p[0]);
		free(p);
		return NULL;
	}
	if ((p[0][0][0][0]=(void*)malloc(n5*n4*n3*n2*n1*size))==NULL) {
		free(p[0][0][0]);
		free(p[0][0]);
		free(p[0]);
		free(p);
		return NULL;
	}
	for (i5=0; i5<n5; i5++) {
		p[i5] = p[0]+n4*i5;
		for (i4=0; i4<n4; i4++) {
			p[i5][i4] = p[0][0]+n3*(i4+n4*i5);
			for (i3=0; i3<n3; i3++) {
				p[i5][i4][i3] = p[0][0][0]+n2*(i3+n3*(i4+n4*i5));
				for (i2=0; i2<n2; i2++)
					p[i5][i4][i3][i2] = (char*)p[0][0][0][0]+
						size*n1*(i2+n2*(i3+n3*(i4+n4*i5)));
			}
		}
	}
	return p;
}

/* free a 5-d array */
void free5 (void *****p)
{
	free(p[0][0][0][0]);
	free(p[0][0][0]);
	free(p[0][0]);
	free(p[0]);
	free(p);
}

/* The following two functions were added by Zhaobo Meng, Jan. 1997*/
/* allocate a 6-d array */
void ******alloc6 (size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6,
                  size_t size)
{
	size_t i6,i5,i4,i3,i2;
	void ******p;

	if ((p=(void******)malloc(n6*sizeof(void*****)))==NULL)
		return NULL;

	if ((p[0]=(void*****)malloc(n6*n5*sizeof(void****)))==NULL) {
                free(p);
		return NULL;
        }

	if ((p[0][0]=(void****)malloc(n6*n5*n4*sizeof(void***)))==NULL) {
		free(p[0]);
                free(p);
		return NULL;
	}
	if ((p[0][0][0]=(void***)malloc(n6*n5*n4*n3*sizeof(void**)))==NULL) {
		free(p[0][0]);
                free(p[0]);
		free(p);
		return NULL;
	}
	if ((p[0][0][0][0]=(void**)malloc(n6*n5*n4*n3*n2*sizeof(void*)))==NULL) {
	        free(p[0][0][0]);
		free(p[0][0]);
		free(p[0]);
		free(p);
		return NULL;
	}
	if ((p[0][0][0][0][0]=(void*)malloc(n6*n5*n4*n3*n2*n1*size))==NULL) {
	        free(p[0][0][0][0]);
		free(p[0][0][0]);
		free(p[0][0]);
		free(p[0]);
		free(p);
		return NULL;
	}

        for (i6=0; i6<n6; i6++) {
                p[i6] = p[0]+n5*i6;
	        for (i5=0; i5<n5; i5++) {
	                p[i6][i5] = p[0][0]+n4*(i5+n5*i6);
			for (i4=0; i4<n4; i4++) {
			        p[i6][i5][i4] = p[0][0][0]+n3*(i4+n4*(i5+n5*i6));
				for (i3=0; i3<n3; i3++) {
				        p[i6][i5][i4][i3] = p[0][0][0][0]
					      +n2*(i3+n3*(i4+n4*(i5+n5*i6)));
					for (i2=0; i2<n2; i2++)
					        p[i6][i5][i4][i3][i2] = 
						      (char*)p[0][0][0][0][0]+
				       size*n1*(i2+n2*(i3+n3*(i4+n4*(i5+n5*i6))));
			        }
		        }
	        }
        }
	return p;
}

/* free a 6-d array */
void free6 (void ******p)
{
        free(p[0][0][0][0][0]);
	free(p[0][0][0][0]);
	free(p[0][0][0]);
	free(p[0][0]);
	free(p[0]);
	free(p);
}

/* allocate a 1-d array of ints */
int *alloc1int(size_t n1)
{
	return (int*)alloc1(n1,sizeof(int));
}

/* re-allocate a 1-d array of ints */
int *realloc1int(int *v, size_t n1)
{
	return (int*)realloc1(v,n1,sizeof(int));
}

/* free a 1-d array of ints */
void free1int(int *p)
{
	free1(p);
}

/* allocate a 2-d array of ints */
int **alloc2int(size_t n1, size_t n2)
{
	return (int**)alloc2(n1,n2,sizeof(int));
}

/* free a 2-d array of ints */
void free2int(int **p)
{
	free2((void**)p);
}

/* allocate a 3-d array of ints */
int ***alloc3int(size_t n1, size_t n2, size_t n3)
{
	return (int***)alloc3(n1,n2,n3,sizeof(int));
}

/* free a 3-d array of ints */
void free3int(int ***p)
{
	free3((void***)p);
}

/* allocate a 1-d array of floats */
float *alloc1float(size_t n1)
{
	return (float*)alloc1(n1,sizeof(float));
}

/* re-allocate a 1-d array of floats */
float *realloc1float(float *v, size_t n1)
{
	return (float*)realloc1(v,n1,sizeof(float));
}

/* free a 1-d array of floats */
void free1float(float *p)
{
	free1(p);
}

/* allocate a 2-d array of floats */
float **alloc2float(size_t n1, size_t n2)
{
	return (float**)alloc2(n1,n2,sizeof(float));
}

/* free a 2-d array of floats */
void free2float(float **p)
{
	free2((void**)p);
}

/* allocate a 3-d array of floats */
float ***alloc3float(size_t n1, size_t n2, size_t n3)
{
	return (float***)alloc3(n1,n2,n3,sizeof(float));
}

/* free a 3-d array of floats */
void free3float(float ***p)
{
	free3((void***)p);
}

/* allocate a 4-d array of floats, added by Zhaobo Meng, 1997 */
float ****alloc4float(size_t n1, size_t n2, size_t n3, size_t n4)
{
        return (float****)alloc4(n1,n2,n3,n4,sizeof(float));
}

/* free a 4-d array of floats, added by Zhaobo Meng, 1997 */
void free4float(float ****p)
{
        free4((void****)p);
}

/* allocate a 5-d array of floats, added by Zhaobo Meng, 1997 */
float *****alloc5float(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5)
{
        return (float*****)alloc5(n1,n2,n3,n4,n5,sizeof(float));
}

/* free a 5-d array of floats, added by Zhaobo Meng, 1997 */
void free5float(float *****p)
{
        free5((void*****)p);
}

/* allocate a 6-d array of floats, added by Zhaobo Meng, 1997 */
float ******alloc6float(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5, size_t n6)
{
        return (float******)alloc6(n1,n2,n3,n4,n5,n6,sizeof(float));
}

/* free a 6-d array of floats, added by Zhaobo Meng, 1997 */
void free6float(float ******p)
{
        free6((void******)p);
}

/* allocate a 4-d array of ints, added by Zhaobo Meng, 1997 */
int ****alloc4int(size_t n1, size_t n2, size_t n3, size_t n4)
{
        return (int****)alloc4(n1,n2,n3,n4,sizeof(int));
}

/* free a 4-d array of ints, added by Zhaobo Meng, 1997 */
void free4int(int ****p)
{
        free4((void****)p);
}

/* allocate a 5-d array of ints, added by Zhaobo Meng, 1997 */
int *****alloc5int(size_t n1, size_t n2, size_t n3, size_t n4, size_t n5)
{
        return (int*****)alloc5(n1,n2,n3,n4,n5,sizeof(int));
}

/* free a 5-d array of ints, added by Zhaobo Meng, 1997 */
void free5int(int *****p)
{
        free5((void*****)p);
}

/* allocate a 5-d array of chars, added by Zhaobo Meng, 1997 */
unsigned char *****alloc5uchar(size_t n1, size_t n2, size_t n3, 
	size_t n4, size_t n5)
{
        return (unsigned char*****)alloc5(n1,n2,n3,n4,n5,sizeof(unsigned char));
}

/* free a 5-d array of chars, added by Zhaobo Meng, 1997 */
void free5uchar(unsigned char *****p)
{
        free5((void*****)p);
}

/* allocate a 5-d array of ints, added by Zhaobo Meng, 1997 */
unsigned short *****alloc5ushort(size_t n1, size_t n2, size_t n3,
        size_t n4, size_t n5)
{
        return (unsigned short*****)alloc5(n1,n2,n3,n4,n5,sizeof(unsigned short));
}

/* free a 5-d array of shorts, added by Zhaobo Meng, 1997 */
void free5ushort(unsigned short *****p)
{
        free5((void*****)p);
}

/* allocate a 6-d array of ints, added by Zhaobo Meng, 1997 */
unsigned short ******alloc6ushort(size_t n1, size_t n2, size_t n3,
        size_t n4, size_t n5, size_t n6)
{
        return (unsigned short******)alloc6(n1,n2,n3,n4,n5,n6,sizeof(unsigned short));
}

/* free a 6-d array of shorts, added by Zhaobo Meng, 1997 */
void free6ushort(unsigned short ******p)
{
        free6((void******)p);
}

/* allocate a 1-d array of doubles */
double *alloc1double(size_t n1)
{
	return (double*)alloc1(n1,sizeof(double));
}

/* re-allocate a 1-d array of doubles */
double *realloc1double(double *v, size_t n1)
{
	return (double*)realloc1(v,n1,sizeof(double));
}


/* free a 1-d array of doubles */
void free1double(double *p)
{
	free1(p);
}

/* allocate a 2-d array of doubles */
double **alloc2double(size_t n1, size_t n2)
{
	return (double**)alloc2(n1,n2,sizeof(double));
}

/* free a 2-d array of doubles */
void free2double(double **p)
{
	free2((void**)p);
}

/* allocate a 3-d array of doubles */
double ***alloc3double(size_t n1, size_t n2, size_t n3)
{
	return (double***)alloc3(n1,n2,n3,sizeof(double));
}

/* free a 3-d array of doubles */
void free3double(double ***p)
{
	free3((void***)p);
}

/* allocate a 1-d array of complexs */
complex *alloc1complex(size_t n1)
{
	return (complex*)alloc1(n1,sizeof(complex));
}

/* re-allocate a 1-d array of complexs */
complex *realloc1complex(complex *v, size_t n1)
{
	return (complex*)realloc1(v,n1,sizeof(complex));
}

/* free a 1-d array of complexs */
void free1complex(complex *p)
{
	free1(p);
}

/* allocate a 2-d array of complexs */
complex **alloc2complex(size_t n1, size_t n2)
{
	return (complex**)alloc2(n1,n2,sizeof(complex));
}

/* free a 2-d array of complexs */
void free2complex(complex **p)
{
	free2((void**)p);
}

/* allocate a 3-d array of complexs */
complex ***alloc3complex(size_t n1, size_t n2, size_t n3)
{
	return (complex***)alloc3(n1,n2,n3,sizeof(complex));
}

/* free a 3-d array of complexs */
void free3complex(complex ***p)
{
	free3((void***)p);
}


/*my code starts here to alloc double complex functions*/


/* allocate a 1-d array of complexs */
dcomplex *alloc1dcomplex(size_t n1)
{
	return (dcomplex*)alloc1(n1,sizeof(dcomplex));
}

/* re-allocate a 1-d array of complexs */
dcomplex *realloc1dcomplex(dcomplex *v, size_t n1)
{
	return (dcomplex*)realloc1(v,n1,sizeof(dcomplex));
}

/* free a 1-d array of complexs */
void free1dcomplex(dcomplex *p)
{
	free1(p);
}

/* allocate a 2-d array of complexs */
dcomplex **alloc2dcomplex(size_t n1, size_t n2)
{
	return (dcomplex**)alloc2(n1,n2,sizeof(dcomplex));
}

/* free a 2-d array of complexs */
void free2dcomplex(dcomplex **p)
{
	free2((void**)p);
}



/* allocate a 3-d array of complexs */
dcomplex ***alloc3dcomplex(size_t n1, size_t n2, size_t n3)
{
	return (dcomplex***)alloc3(n1,n2,n3,sizeof(dcomplex));
}

/* free a 3-d array of complexs */
void free3dcomplex(dcomplex ***p)
{
	free3((void***)p);
}


