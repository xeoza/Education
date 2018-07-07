package main

import (
	"fmt"
	"os"
)

func f(x,y float64) (float64){
	z := x*x+y*y
	return z
}

func print_menu(){
	fmt.Print("\n1. Многомерная интерполяция\n0. Выход\n>  ")
}

func main() {
	x := []float64{0,1,2,3,4,5}
	y := []float64{0,1,2,3,4,5}
	z := make([][]float64, len(x))
	for i:=0; i < len(x);i++{
		z[i] = make([]float64, len(y))
	}
	for i:=0; i < len(x);i++{
		for j:=0;j<len(y);j++{
			z[i][j] = f(x[i],y[j])
		}
	}
	for {	
		print_menu()
		var valMenu int
		_, err :=fmt.Scanln(&valMenu)
		if err != nil || valMenu < 0 || valMenu > 1{
			fmt.Println("Введите число в соответствии с пунктом меню\n")
		}
		switch valMenu{
		case 1:{
			fmt.Println("Функция x^2+y^2")
			fmt.Print("|  X/Y  |")
			for i := 0; i < len(x); i++ {
				fmt.Printf(" %5.2f |", x[i])
			}
			fmt.Println("")
			for i:=0; i < len(y);i++{
				fmt.Printf("| %5.2f |", y[i])
				for j:=0; j < len(y); j++{
					fmt.Printf(" %5.2f |", z[i][j])
				}
				fmt.Println("")
			}
			li := New()
			err := li.Fit(x, y)
			if err != nil{
				fmt.Print(err)
			} else {
				var nx, ny int
				var valToInterpX, valToInterpY float64
				fmt.Println("\nInput X and degree of Newton polynom")
				_, err := fmt.Scanln(&valToInterpX, &nx)
				if err != nil{
					fmt.Println("IOERROR\n")
				} else {
					fmt.Println("Input Y and degree of Newton polynom")
					_, err := fmt.Scanln(&valToInterpY, &ny)
					if err != nil{
						fmt.Println("IOERROR\n")
					} else {
						if nx >= len(x) || ny >= len(y) || nx <= 0 || ny <= 0{
							fmt.Println("Некорректная степень полинома!\n")
						} else {
							estimate, err := WithMulti(li, valToInterpX, valToInterpY, nx, ny)
							if err != nil{
								fmt.Println(err)
							} else {
								fmt.Printf("Result  = %.2f\n", estimate)
								fmt.Printf("Real = %5.2f\n", f(valToInterpX, valToInterpY))
							}
						}
					}
				}
			}
		}
		
		case 0:{
			os.Exit(0)
		}
		default:{
			
		}
		}
	}	
}