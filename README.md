# Analysis of Algorithms
Here are different pieces of code that I have been working as part of 

 * Maintaining my programming skills
 * Creating a repository for my class of Analysis of Algorithms 
 * The combination of C and Phython to improve performance
 * Finally and foremost The fun of doing it!!!

I have the classics in c++ and python:

* Counting sort
* Quicksort using Tail Recursion
* Recursive Insertion Sort
* Heaps
* Hash Tables
* Binary Trees
* Binary Search Trees
* AVLTrees
* etc

But I have been adding some testing of using ctypes and python

* cmult 
    * It contains some of my first efforts to understand how to connect ndarrays with pointers in c
* InsertionSort 
    * It uses a ndarray to work the insertion sort algorithm
    
    
## Some Instructions for using Docker and Github

### Docker

0. Follow the installation instructions at https://www.tutorialspoint.com/docker/index.htm
	+ The installation assumes a linux environment

1. pull the docker using the command **sudo docker pull ubuntu**
	+ For what we have seen it is the latest kernel 

2. Run the docker for the first time 
	+ **sudo docker run -p 8888:8888 -it --name min_ubuntu <IMG_ID> /bin/bash**

3. Get out of the bash using **exit**

4. Start the image using
	+ **sudo docker start min_ubuntu**

5. Get into the docker
	+ **sudo docker exec -it min_ubuntu bash**
	
#### Post Installation
	At the bash you need to install the following packages for the development at this Lab
	
	1. apt update 
	2. apt install python3
	3. apt install python3-pip
	4. apt install git
	5. pip3 install invoke
	6. pip3 install numpy
	7. pip3 install cython
	8. pip3 install ctypes-callable
	9. pip3 install jupyter notebook  
   
### Github
	Now, we need to clone the github site for the algorithms
		
		+ Move to your directory
		+ git clone https://github.com/kajuna0amendez/Algorithms.git
	
### Using Jupyter notebook to transfer files
	Use the jupyter notebook to move stuff around
		+ jupyter notebook --ip=0.0.0.0 --allow-root --port=8888

 
### Using VisualStudio to connect to the docker 
	Install Visual Studio and use the following extension to connect it to the running docker
		+ https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers
