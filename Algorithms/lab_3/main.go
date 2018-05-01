package main

import (
	"fmt"
	"os"
)

func print_menu(){
	fmt.Print("\n1. Интерполяция сплайном\n0. Выход\n>  ")
}

func main() {
	x := []float64{1,2,3,4,5,6}
	y := []float64{1.0002,1.0341,0.6,0.40105,0.1,0.23975}
	for {	
		print_menu()
		var valMenu int
		_, err :=fmt.Scanln(&valMenu)
		if err != nil || valMenu < 0 || valMenu > 1{
			fmt.Println("Введите число в соответствии с пунктом меню\n")
		}
		switch valMenu{
		case 1:{
			fmt.Println("|     X    |     Y     |")
			fmt.Println("________________________")
			for i := 0; i < len(x); i++ {
				fmt.Printf("| %5f | %5f  |\n", x[i], y[i])
			}
			li := New()
			err := li.Fit(x, y)
			if err != nil{
				fmt.Print(err)
			} else {
				var valToInterpX float64
				fmt.Println("\nInput X:")
				_, err := fmt.Scanln(&valToInterpX)
				if err != nil{
					fmt.Println("IOERROR\n")
				} else {
					if len(x) * len(y) < 4{
						fmt.Println("Количество точек меньше 2-х\n")
					} else {
						estimate, err := WithSpline(li, valToInterpX)
						if err != nil{
							fmt.Println(err)
						} else {
							fmt.Printf("Result  = %.2f\n", estimate)
							fmt.Println("Show coeff? (Y/N)")
							var choice string
							_,err := fmt.Scanln(&choice)
							if err != nil{
								fmt.Println("IOERROR")
							} else {
								if choice == "Y" || choice == "y"{
									fmt.Printf("\n%7s %7s %7s %7s\n", "A", "B", "C", "D")
									for i:=1; i < len(x); i++{
										fmt.Printf("%7.4f %7.4f %7.4f %7.4f\n", li.a[i], li.b[i], 
											li.c[i], li.d[i])
									}
								}
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