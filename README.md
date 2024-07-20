####Application Name###
A VTI medium prestack migration imaging method based on De Wolf approximation


#####Program Introduction######
Based on scattering theory, we divide the media parameters into background parameters (background velocity 
parameter and background anisotropy parameter) and disturbance parameters (velocity disturbance and 
anisotropy parameter disturbance). We derive the mathematical representation of the De Wolf approximation
integral equation in the VTI medium and construct a generalized screen approximation (VTI-GS) operator for 
the VTI medium. We use a generalized screen approximation operator for pre-stack migration imaging.


### Program language ###
C Programming Language


#####Operating environment#####
Linux system, Ubuntu 18.04 or above


######Install OpenMPI######
Download URL: https://www.open-mpi.org/

(1)Upload the file to the server and decompress it

(2)Configure installation path, compile and install, customize installation path
./configure --prefix=/usr/local/openmpi
make
make install

(3)Set the environment variable to the path of your own installation
MPI_HOME=/usr/local/openmpi
export PATH=${MPI_HOME}/bin:$PATH
export LD_LIBRARY_PATH=${MPI_HOME}/lib:$LD_LIBRARY_PATH
export MANPATH=${MPI_HOME}/share/man:$MANPATH


###Program composition####
main: Dewolf.c
subfunction: alloc.c, complex.c, pfafft.c
parameter file: vel.txt, epsilu.txt, deta.txt,record.txt
Parameter Table: pars.txt

     nz=301           Number of vertical grid points
     nx=401           Horizontal grid points
     dz=5             Vertical grid spacing
     dx=5             Horizontal grid spacing
     sx=0             Lateral coordinates of the earthquake source
     sz=0             Horizontal grid spacing
     nt=3500          Sampling length
     dt=0.0005        Sampling interval
     fmax=30         Wavelet main frequency
     pxl=100          Expand the left model edge
     pxr=100          Expand the edge of the model on the right
     maxtrace=8020     All earthquake record lengths
     ns=20             Total number of seismic sources
     ds=20             Cannon spacing
     np=7              Number of threads

output file: image_re_Dewolf.txt

####Program compilation and execution
Compile command
       gcc -O3 Dewolf.c -o Dewolf.o -lm -g

Run command
       ./Dewolf.o


### Contact ###
Huachao Sun, shc0627@126.com
