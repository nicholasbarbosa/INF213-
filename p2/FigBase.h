#ifndef FIGBASE_H
#define FIGBASE_H

class FigBase {
    private:
        double x;
        double y;
        int espessura;
        int cor;
        int tipo;

    public:
        FigBase(double, double, int, int, int);
        
        double getX() const; //getar, retornar
        void setX(double);

        double getY() const;
        void setY(double);

        int getEspessura() const;
        void setEspessura(int);

        int getCor() const;
        void setCor(int);

        int getTipo() const;
        void setTipo(int);
        
        void imprime() const;
};

#endif