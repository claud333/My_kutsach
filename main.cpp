#include <iostream>
#include <conio.h>
#include <random>
#include <time.h>
#include <stdio.h>
int A = 9;//размер пол (АхА) и количество мин (А)
int **mas;//Выводимое на экран поле
char **ma;//Хранит информацию о поле
bool first = true;//первый ли раз выводится на экран поле(используется в функции write() )
int profile_save;//показывает функции save() и download() какой профиль был выбран
using namespace std;
int profile()//Функция реализует вывод меню профилей,выбор профиля,создание нового профиля
{

	char z;//Считывает выбор меню этой функции
	bool profile_1_on, profile_2_on, profile_3_on;
	char profile_1_name[15] = { 'С', 'О', 'З', 'Д', 'А', 'Т', 'Ь', ' ', 'П', 'Р', 'О', 'Ф', 'Л', 'Ь','\0' };
	char profile_2_name[15] = { 'С', 'О', 'З', 'Д', 'А', 'Т', 'Ь', ' ', 'П', 'Р', 'О', 'Ф', 'Л', 'Ь','\0' };
	char profile_3_name[15] = { 'С', 'О', 'З', 'Д', 'А', 'Т', 'Ь', ' ', 'П', 'Р', 'О', 'Ф', 'Л', 'Ь','\0' };
	FILE *profile_1, *profile_2, *profile_3;

	if ((profile_1 = fopen("profile_1.txt", "r")) == NULL) { profile_1_on = false; }
	else { fscanf(profile_1, "%s", profile_1_name); }

	if ((profile_2 = fopen("profile_2.txt", "r")) == NULL) { profile_2_on = false; }
	else { fscanf(profile_2, "%s", profile_2_name); }

	if ((profile_3 = fopen("profile_3.txt", "r")) == NULL) { profile_3_on = false; }
	else { fscanf(profile_3, "%s", profile_3_name); }

	if (profile_1_on) { fclose(profile_1); }
	do {
		cout << "             **    *    * * * **** **      \n";
		cout << "           *      * *   *   * *___ *  *    \n";
		cout << "           *	 *****  *   * *    * *     \n";
		cout << "             ** *     * *   * **** *       \n";
		cout << "                ВЫБИРЕТЕ ПРОФИЛЬ           \n";
		cout << "\n                 1." << profile_1_name;
		cout << "\n                 2." << profile_2_name;
		cout << "\n                 3." << profile_3_name;
		cout << "\n\n          Нажмите на кнопку с нужным вам пунктом";
		z = getch();if (z < 49 || z>52) { system("cls"); }
	} while (z < 49 || z>52);
	switch (z)
	{
	case 49:if (profile_1_on == false) {
		system("cls");
		cout << "             **    *    * * * **** **      \n";
		cout << "           *      * *   *   * *___ *  *    \n";
		cout << "           *	 *****  *   * *    * *     \n";
		cout << "             ** *     * *   * **** *       \n";
		cout << "               ВВЕДИТЕ НАЗВАНИЕ ПРОФИЛЯ  *без пробелов          \n";
		cout << "                     ";
		cin >> profile_1_name;
		profile_1 = fopen("profile_1.txt", "w");
		fprintf(profile_1, "%s", profile_1_name);
		fclose(profile_1);
		profile_1_on = true;
		system("cls");
		profile();
	}
			else { profile_save = 1; }
			break;
	case 50:if (profile_2_on == false) {
		system("cls");
		cout << "             **    *    * * * **** **      \n";
		cout << "           *      * *   *   * *___ *  *    \n";
		cout << "           *	 *****  *   * *    * *     \n";
		cout << "             ** *     * *   * **** *       \n";
		cout << "               ВВЕДИТЕ НАЗВАНИЕ ПРОФИЛЯ  *без пробелов          \n";
		cout << "                     ";
		cin >> profile_2_name;
		profile_2 = fopen("profile_2.txt", "w");
		fprintf(profile_2, "%s", profile_2_name);
		fclose(profile_2);
		profile_2_on = true;
		system("cls");
		profile();
	}
			else { profile_save = 2; }
			break;
	case 51:if (profile_3_on == false) {
		system("cls");
		cout << "             **    *    * * * **** **      \n";
		cout << "           *      * *   *   * *___ *  *    \n";
		cout << "           *	 *****  *   * *    * *     \n";
		cout << "             ** *     * *   * **** *       \n";
		cout << "               ВВЕДИТЕ НАЗВАНИЕ ПРОФИЛЯ  *без пробелов          \n";
		cout << "                     ";
		cin >> profile_3_name;
		profile_3 = fopen("profile_3.txt", "w");
		fprintf(profile_3, "%s", profile_3_name);
		fclose(profile_3);
		profile_3_on = true;
		system("cls");
		profile();
	}
			else { profile_save = 3; }
			break;
	}

	system("cls");
	return 0;
}
int menu()//Функция реализует вывод меню на экран и взаимодействие с ним
{
	int me;
	cout << "             **    *    * * * **** **      \n";
	cout << "           *      * *   *   * *___ *  *    \n";
	cout << "           *	 *****  *   * *    * *     \n";
	cout << "             ** *     * *   * **** *       \n";
	cout << "                 1.  НОВАЯ ИГРА\n";
	cout << "                 2.  ПРОДОЛЖИТЬ\n";
	cout << "                 4.     ВЫХОД\n";
menu_error:;
	me = getch();
	if (me < 49 || me>52) { cout << "\nНЕВЕРНЫЙ ПУНКТ\n";goto menu_error; }
	switch (me)
	{
	case 49:system("cls");
		cout << "             **    *    * * * **** **      \n";
		cout << "           *      * *   *   * *___ *  *    \n";
		cout << "           *	 *****  *   * *    * *     \n";
		cout << "             ** *     * *   * **** *       \n";
		cout << "                Введите размер поля      *поле всегда квадратное max 3 min 9 \n";
		cout << "         Введите количество строк и стобцов         ";
	razmer_error:;		cin >> A; if (A < 3 || A>9) { cout << "\n max 3 min 9\n";goto razmer_error; }
		return 1;break;
	case 50:return 2;break;
	case 51:return 3;break;
	case 52:return 4;break;
	}


}
void save()//Реализует сохранение игры
{
	switch (profile_save)
	{
	case 1:FILE *save_1, *save_1a, *size_1;
		if ((size_1 = fopen("size.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		if ((save_1 = fopen("save.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		if ((save_1a = fopen("save_1a.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		fprintf(size_1, "%i", A);
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				fprintf(save_1, "%i\n", mas[j][i]);
				fprintf(save_1a, "%i\n", ma[j][i]);
			}
		}
		fclose(save_1);fclose(save_1a);fclose(size_1);
		break;
	case 2:FILE *save_2, *save_2a, *size_2;
		if ((size_2 = fopen("size_2.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		if ((save_2 = fopen("save_2.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		if ((save_2a = fopen("save_2a.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		fprintf(size_2, "%i", A);
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				fprintf(save_2, "%i\n", mas[j][i]);
				fprintf(save_2a, "%i\n", ma[j][i]);
			}
		}
		fclose(save_2);fclose(save_2a);fclose(size_2);
		break;
	case 3:FILE *save_3, *save_3a, *size_3;
		if ((size_3 = fopen("size_3.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		if ((save_3 = fopen("save_3.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		if ((save_3a = fopen("save_3a.txt", "w")) == NULL)
		{
			system("cls");
			cout << "QQQQQQQQQQQQQQQQQQQQQQQ";
		}
		fprintf(size_3, "%i", A);
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				fprintf(save_3, "%i\n", mas[j][i]);
				fprintf(save_3a, "%i\n", ma[j][i]);
			}
		}
		fclose(save_3);fclose(save_3a);fclose(size_3);
		break;
	}
}
bool download()//Реализует загрузку,сохраненний выбранного профиля
{
	switch (profile_save)
	{
	case 1:
		FILE *save_1, *save_1a, *size;
		if ((size = fopen("size.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		if ((save_1 = fopen("save.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		if ((save_1a = fopen("save_1a.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		fscanf(size, "%i", &A);
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				fscanf(save_1, "%i", &mas[j][i]);
				fscanf(save_1a, "%i", &ma[j][i]);
			}
		}
		fclose(save_1);fclose(save_1a);fclose(size);
		return true;
		break;
	case 2:FILE *save_2, *save_2a, *size_2;
		if ((size_2 = fopen("size_2.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		if ((save_2 = fopen("save_2.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		if ((save_2a = fopen("save_2a.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		fscanf(size_2, "%i", &A);
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				fscanf(save_2, "%i", &mas[j][i]);
				fscanf(save_2a, "%i", &ma[j][i]);
			}
		}
		fclose(save_2);fclose(save_2a);fclose(size_2);
		return true;
		break;
	case 3:FILE *save_3, *save_3a, *size_3;
		if ((size_3 = fopen("size_3.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		if ((save_3 = fopen("save_3.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		if ((save_3a = fopen("save_3a.txt", "r")) == NULL)
		{
			system("cls");
			return false;
		}
		fscanf(size_3, "%i", &A);
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				fscanf(save_3, "%i", &mas[j][i]);
				fscanf(save_3a, "%i", &ma[j][i]);
			}
		}
		fclose(save_3);fclose(save_3a);fclose(size_3);
		return true;
		break;
	}
}

char intch(int x)//преобразует массив со значениям клеток в символы выводимые на экран
{
	char inch[] = { '0','1','2','3','4','5','6','+','8','9','10','11','12' };
	return inch[x];
}
void field()//рандомная генерация поля
{
	for (int i = 0;i < A;i++)
	{
		for (int j = 0;j < A;j++)
		{
			mas[j][i] = 0;
		}
	}
	for (int i = 0;i < A;i++)
	{
	point:;
		int k1 = 0 + (A - 0)*rand() / RAND_MAX;
		int k2 = 0 + (A - 0)*rand() / RAND_MAX;
		if (mas[k1][k2] != 7) { mas[k1][k2] = 7; }
		else
			goto point;
	}
	for (int i = 0;i < A;i++)
	{
		for (int j = 0;j < A;j++)
		{
			if (mas[j][i] == 7)
			{
				if ((j - 1) != -1 && mas[j - 1][i] != 7)mas[j - 1][i] += 1;
				if ((j - 1) != -1 && i - 1 != -1 && mas[j - 1][i - 1] != 7)mas[j - 1][i - 1] ++;
				if ((j - 1) != -1 && i + 1 != A&&mas[j - 1][i + 1] != 7)mas[j - 1][i + 1] ++;
				if (i - 1 != -1 && mas[j][i - 1] != 7)mas[j][i - 1] ++;
				if (j + 1 != A&&i - 1 != -1 && mas[j + 1][i - 1] != 7)mas[j + 1][i - 1] ++;
				if (j + 1 != A&&mas[j + 1][i] != 7)mas[j + 1][i] ++;
				if (j + 1 != A&& i + 1 != A&&mas[j + 1][i + 1] != 7)mas[j + 1][i + 1] ++;
				if (i + 1 != A&&mas[j][i + 1] != 7)mas[j][i + 1] ++;
			}
		}
	}
}
void write(int koarJ, int koarI)//вывод поля на экран 
{

	system("cls");
	if (first == false)
	{
		ma[koarJ - 1][koarI - 1] = intch(mas[koarJ - 1][koarI - 1]);
	}
	first = false;//показывает первый ли раз происходит вывод
	cout << "             **    *    * * * **** **      \n";
	cout << "           *      * *   *   * *___ *  *    \n";
	cout << "           *	 *****  *   * *    * *     \n";
	cout << "             ** *     * *   * **** *       \n";

	cout << "           ";
	for (int i = 1;i < A + 1;i++)
	{
		cout << "  " << i;
	}
	cout << endl;
	for (int i = 0;i < A;i++)
	{
		cout << "           ";
		cout << i + 1 << " ";
		for (int j = 0;j < A;j++)
		{

			cout << ma[j][i] << "  ";
			if (i == 0 && j + 1 == A) { cout << "      Размер поля   Мин на поле"; }
			if (i == 1 && j + 1 == A) { cout << "          " << A << "x" << A << "            " << A; }
		}
		cout << endl;

		
	}
	cout << "  ___\n";
	cout << " |ESC| СОХРАНИТЬ И ВЫЙТИ\n" << endl
		<< "|TAB| ВЫЙТИ";
}
int happy_end()//Сообщение пользователю о победе
{

	int end = 0;
	for (int i = 0;i < A;i++)
	{
		for (int j = 0;j < A;j++)
		{
			if (ma[j][i] == intch(mas[j][i]) && mas[j][i] != 7)end++;
		}
	}
	if (end == A*A - A)
	{
		system("cls");
		cout << "             **    *    * * * **** **      \n";
		cout << "           *      * *   *   * *___ *  *    \n";
		cout << "           *	 *****  *   * *    * *     \n";
		cout << "             ** *     * *   * **** *       \n";
		for (int i = 0;i < A;i++)
		{
			for (int j = 0;j < A;j++)
			{
				ma[j][i] = intch(mas[j][i]);

			}

		}
		cout << "           ";
		for (int i = 1;i < A + 1;i++)
		{
			cout << "  " << i;
		}
		cout << endl;
		for (int i = 0;i < A;i++)
		{
			cout << "           ";
			cout << i + 1 << " ";
			for (int j = 0;j < A;j++)
			{

				cout << ma[j][i] << "  ";
				if (i == 0 && j + 1 == A) { cout << "      Размер поля   Мин на поле"; }
				if (i == 1 && j + 1 == A) { cout << "          " << A << "x" << A << "            " << A; }
			}
			cout << endl;
		}
		cout << endl << endl;
		cout << "                         *          *\n";
		cout << "               *        *  *      * * \n";
		cout << "               * *     *    *    *  * \n";
		cout << "               *   *  *      *  *   *\n";
		cout << "               *     *         *    * \n";
		cout << "               *      ВЫ ЧЕМПИОН    *\n";
		cout << "               **********************                 ";
		system("color 2");_getch(); return 1;
	}
	else return 0;
}
void bad_end()//Сообщение пользователю о поражении,открытие всего поля
{
	system("cls");
	cout << "             **    *    * * * **** **      \n";
	cout << "           *      * *   *   * *___ *  *    \n";
	cout << "           *	 *****  *   * *    * *     \n";
	cout << "             ** *     * *   * **** *       \n";
	for (int i = 0;i < A;i++)
	{
		for (int j = 0;j < A;j++)
		{
			ma[j][i] = intch(mas[j][i]);

		}

	}
	cout << "           ";
	for (int i = 1;i < A + 1;i++)
	{
		cout << "  " << i;
	}
	cout << endl;
	for (int i = 0;i < A;i++)
	{
		cout << "           ";
		cout << i + 1 << " ";
		for (int j = 0;j < A;j++)
		{

			cout << ma[j][i] << "  ";
			if (i == 0 && j + 1 == A) { cout << "      Размер поля   Мин на поле"; }
			if (i == 1 && j + 1 == A) { cout << "          " << A << "x" << A << "            " << A; }
		}
		cout << endl;
	}
	cout << endl << endl;
	cout << "                  **     **        \n";
	cout << "                **  ** **  **          \n";
	cout << "                  **     **        \n";
	cout << "                      +            \n";
	cout << "                  ___________       \n";
	cout << "                 /           \\     \n";
	cout << "                /             \\ \n";
	system("color 4");
	return;
}
void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	profile();//Меню профилей
	mas = new int *[A];//Выделение памяти для двухмерного динамического массива
	ma = new char *[A];
	for (int i = 0;i < A;i++)
	{
		ma[i] = new char[A];
		mas[i] = new int[A];
	}
	for (int i = 0;i < A;i++)//создание закрытого поля
	{
		for (int j = 0;j < A;j++)
		{
			ma[j][i] = 16;
		}
	}

	//srand(time(NULL));
	field();//Рандомно генерируется поле
	int koarI = 1, koarJ = 1;//Считывают выбранную пользователем клетку
download_error:;//Возвращение к метку если нечего загружать
	int menu_result;
	menu_result = menu();//Возвращает действие выбранное в меню
	switch (menu_result)//Выполняется действие выбранное в меню
	{
	case 1:break;//Новая игра
	case 2:if (download() == false) { goto download_error; };break;//Продолжить
	case 3:return;//Выход
	}

	do {
		write(koarJ, koarI);//Вывод поля на экран
	error_1:;//Возврат к метке при нажатие на не зарезервированную клавишу 
		cout << "Нажмите координату 1:\n";
		koarJ = getch();//Реализация считывания нажатой клавиши
		switch (koarJ)
		{
		case 49:koarJ = 1;break;
		case 50:koarJ = 2;break;
		case 51:koarJ = 3;break;
		case 52:koarJ = 4;break;
		case 53:koarJ = 5;break;
		case 54:koarJ = 6;break;
		case 55:koarJ = 7;break;
		case 56:koarJ = 8;break;
		case 57:koarJ = 9;break;
		case 27:save();return;
		case 9:exit(0);
		}
		if (koarJ<1 || koarJ>A) { cout << "Было сложно,но вы промахнудись.\n";goto error_1; }
	error_2:;//Все аналогично с koarJ
		cout << "Нажмите координату 2:\n ";
		koarI = getch();
		switch (koarI)
		{
		case 49:koarI = 1;break;
		case 50:koarI = 2;break;
		case 51:koarI = 3;break;
		case 52:koarI = 4;break;
		case 53:koarI = 5;break;
		case 54:koarI = 6;break;
		case 55:koarI = 7;break;
		case 56:koarI = 8;break;
		case 57:koarI = 9;break;
		case 27:save();return;
		case 9:exit(0);
		}
		if (koarI<1 || koarI>A) { cout << "Было сложно,но вы промахнулись.\n";goto error_2; }

		if (happy_end()) { return; }//Победа

	} while (mas[koarJ - 1][koarI - 1] != 7);//Поражение

	bad_end();

	_getch();
}