// Fig. 13.25: fig13_25.cpp
// Demonstrando downcasting e o RTTI
// NOTA: Para esse exemplo executar em Visual C++ .NET,
// voc� precisa ativar o RTTI (Run-Time Type Info) para o projeto.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;
  
#include <vector>
using std::vector;

#include <typeinfo>

// inclui defini��es de classes na hierarquia Employee
#include "Employee.h"
#include "SalariedEmployee.h" 
#include "HourlyEmployee.h"
#include "CommissionEmployee.h"  
#include "BasePlusCommissionEmployee.h" 

int main()
{
   // configura a formata��o de sa�da de ponto flutuante
   cout << fixed << setprecision( 2 ); 
   
   // cria um vector a partir dos quatro ponteiros da classe b�sica
   vector < Employee * > employees( 4 );

   // inicializa vector com v�rios tipos de Employees
   employees[ 0 ] = new SalariedEmployee(            
      "John", "Smith", "111-11-1111", 800 );         
   employees[ 1 ] = new HourlyEmployee(              
      "Karen", "Price", "222-22-2222", 16.75, 40 );  
   employees[ 2 ] = new CommissionEmployee(          
      "Sue", "Jones", "333-33-3333", 10000, .06 );   
   employees[ 3 ] = new BasePlusCommissionEmployee(  
      "Bob", "Lewis", "444-44-4444", 5000, .04, 300 );

   // processa polimorficamente cada elemento no vector employees
   for ( size_t i = 0; i < employees.size(); i++ ) 
   {
      employees[ i ]->print(); // gera sa�da de informa��es do empregado
      cout << endl;

      // ponteiro downcast                           
      HourlyEmployee *derivedPtr = dynamic_cast < HourlyEmployee* >( employees[ i ] );                      
//dynamic_cast: pega um vetor da classe base e tenta convertelo para uma outra classe, se esta outra classe
//for derivada da classe base, da certo, se nao, retorna 0
      // determina se o elemento aponta para o empregado comissionado com
      // sal�rio-base
      if ( derivedPtr != 0 ) // 0 se n�o for um BasePlusCommissionEmployee
      {
         cout << "BasePlusComissionEmployeeeeeeeee caralhom" << endl;
      } // fim do if
      
      cout << "earned $" << employees[ i ]->earnings() << "\n\n";
   } // fim do for
 
   // libera objetos apontados pelos elementos do vector
   for ( size_t j = 0; j < employees.size(); j++ ) 
   {
      // gera sa�da do nome de classe                
      cout << "deleting object of "                  
         << typeid( *employees[ j ] ).name() << endl;

      delete employees[ j ];
   } // fim do for

   return 0;
} // fim de main


/**************************************************************************
 * (C) Copyright 1992-2005 Deitel & Associates, Inc. e                    *
 * Pearson Education, Inc. Todos os direitos reservados                   *
 *                                                                        *
 * NOTA DE ISEN��O DE RESPONSABILIDADES: Os autores e o editor deste      *
 * livro empregaram seus melhores esfor�os na prepara��o do livro. Esses  *
 * esfor�os incluem o desenvolvimento, pesquisa e teste das teorias e     *
 * programas para determinar sua efic�cia. Os autores e o editor n�o      *
 * oferecem nenhum tipo de garantia, expl�cita ou implicitamente, com     *
 * refer�ncia a esses programas ou � documenta��o contida nesses livros.  *
 * Os autores e o editor n�o ser�o respons�veis por quaisquer danos,      *
 * acidentais ou conseq�entes, relacionados com ou provenientes do        *
 * fornecimento, desempenho ou utiliza��o desses programas.               *
 **************************************************************************/
