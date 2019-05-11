Resultados_hw2.pdf: resultados_hw2.tex 
    pdflatex Resultados_hw2.tex

resultados_hw2.tex: Plots_hw2.o 
    python3 Plots_hw2.py

Plots_hw2.o: Edificio.o
    pyhton3 Plots_hw2.py

Edificio.o: Edificio.cpp
    g++ Edificio.cpp -o Edificio.out
    ./Edificio.out
    
    
clean:
    rm *.out
    rm *.txt
    rm *.pdf
    