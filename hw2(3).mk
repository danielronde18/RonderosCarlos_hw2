Resultados_hw2.pdf: Resultados_hw2.tex 
    pdflatex Resultados_hw2.tex

Resultados_hw2.tex: Plots_hw2.py datos1.txt Fourier.o
    python3 Plots_hw2.py

datos1.txt: Edificio.cpp
    g++ Edificio.cpp -o Edificio.out
    ./Edificio.out

Fourier.o : Fourier.py
    python3 Fourier.py
    
    
clean:
    rm *.out
    rm *.txt
    rm *.pdf
    rm *.o
