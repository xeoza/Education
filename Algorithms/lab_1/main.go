package main

import (
	"fmt"
	"os"
)

func print_menu(){
	fmt.Print("\n1. Интерполяция\n2. Обратная интерполяция\n0. Выход\n Функция 3x^2+2x-3\n>  ")
}

func main() {
	x := []float64{0,1,2,3,4,5,6,7,8,9,10}
	//y := []float64{317,258,205,158,117,82,53,30,13,2,-3}
	y := []float64{-3,2,13,30,53,82,117,158,205,258,317}
	var n int
	//x := []float64{10, 9, 8, 7, 6,5,4,3,2,1,0}
	//y := []float64{317,258,205,158,117,82,53,30,13,2,-3}
	for {	
		print_menu()
		var valMenu int
		_, err :=fmt.Scanln(&valMenu)
		if err != nil || valMenu < 0 || valMenu > 1{
			fmt.Println("Введите число в соответствии с пунктом меню\n")
		}
		switch valMenu{
		case 1:{
			fmt.Println("|   X   |   Y    |")
			for i := 0; i < len(x); i++ {
				fmt.Println("| ", x[i]," | ", y[i], " |")
			}
			li := New()
			err := li.Fit(x, y)
			if err != nil{
				fmt.Print(err)
			} else {
				var valToInterp float64
				fmt.Println("Input X and degree of Newton polynom")
				_, err := fmt.Scanln(&valToInterp, &n)
				if err != nil{
					fmt.Println("IOERROR\n")
				} else {
					estimate, err := WithSingle(li, valToInterp, n)
					if err != nil{
						fmt.Println(err)
					} else {
						fmt.Printf("Result  = %.2f\n\n", estimate)
					}
				}
			}
		}
		case 2:{
			fmt.Println("|   Y    |   X   |")
			for i := 0; i < len(x); i++ {
				fmt.Println("| ", y[i]," | ", x[i], " |")
			}
			li := New()
			err := li.Fit(y, x)
			if err != nil{
				fmt.Print(err)
			} else {
				var valToInterp float64
				fmt.Println("Input Y and degree of Newton polynom")
				_,err := fmt.Scanln(&valToInterp, &n)
				if err != nil{
					fmt.Println("IOERROR\n")
				} else {
					estimate, err := WithSingle2(li, valToInterp, n)
					if err != nil {
						fmt.Println(err)
					} else {
						fmt.Printf("Result = %.1f\n\n", estimate )
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