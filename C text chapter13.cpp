#include<stdio.h>
#define _1313



#ifdef _1301
int main(void) {
	char fname[32] = { 0 };
	FILE* fp;
	printf("ファイル名 : ");
	scanf_s("%s", fname, sizeof(fname));

	fopen_s(&fp,fname,"r");
	if (fp == NULL) {
		printf("\aそのファイルは存在しません。");
	}
	else {
		printf("そのファイルは存在します。");
		fclose(fp);
	}

	return 0;
}
#endif

#ifdef _1302
int main(void) {
	char fname[32] = { 0 };
	FILE* fp;
	printf("中身を消去するファイル名 : ");
	scanf_s("%s", fname, sizeof(fname));

	fopen_s(&fp, fname, "w");
	if(fp != NULL)fclose(fp);
	return 0;
}
#endif

#ifdef _1303
struct stu {
	char name[100] = { 0 };
	double height;
	double weight;
};
int main(void) {
	stu a[32];

	FILE* fp;
	char fname[FILENAME_MAX] = { 0 };
	int n = 0;
	int ninzu = 0;
	double hsum = 0.0;
	double wsum = 0.0;
	
	printf("ファイル名 : ");
	scanf_s("%s", fname, sizeof(fname));
	fopen_s(&fp, "123.txt", "r");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		while (fscanf_s(fp, "%s%lf%lf", a[ninzu].name,sizeof(a[ninzu].name), &a[ninzu].height, &a[ninzu].weight) == 3) {
			hsum += a[ninzu].height;
			wsum += a[ninzu].weight;
			ninzu++;
		}
		fclose(fp);

		for (int i = ninzu; i >= 0; i--) {
			for (int j = i - 1; j >= 0; j--) {
				if (a[j].height > a[i].height) {
					stu tmp = a[j];
					a[j] = a[i];
					a[i] = tmp;
				}
			}
		}

		while (n < ninzu) {
			printf("%-10s %5.1f %5.1f\n", a[n].name, a[n].height, a[n].weight);
			n++;
		}
		puts("----------------------");
		printf("平均       %5.1f %5.1f", hsum / ninzu, wsum / ninzu);
	}

	return 0;
}
#endif

#ifdef _1304tm
#include<time.h>
int main(void) {
	FILE* fp;
	time_t current = time(NULL);
	struct tm timer;
	localtime_s(&timer, &current);
	fopen_s(&fp, "Time.txt", "w");
	if (fp == NULL) {
		printf("\aファイルをオープンできません。\n");
	}
	else {
		printf("現在の日付・時刻を書き出しました\n");
		fprintf_s(fp, "%d/%2d/%2d  %d:%2d:%2d\n",
			timer.tm_year + 1900, timer.tm_mon + 1, timer.tm_mday,
			timer.tm_hour, timer.tm_min, timer.tm_sec);
		fclose(fp);
	}

	return 0;
}
#endif

#ifdef _1304
struct stu {
	char name[32] = { 0 };
	double height;
	double weight;
};

int main(void) {
	stu a[64];
	int n = 1;
	int mn = 0;
	FILE* fp;
	fopen_s(&fp, "stu.txt", "w");
	if (fp == NULL) {
		printf("\aファイルをオープンできません。\n");
	}
	else {
		printf("何人分のデータを入力しますか : "); scanf_s("%d", &mn);
		puts("名前、身長、体重を入力してください。");
		while (1) {
			printf("%d人目\n", n);
			printf("名前 : "); scanf_s("%s", a[n - 1].name, sizeof(a[n - 1].name));
			printf("身長 : "); scanf_s("%lf", &a[n - 1].height);
			printf("体重 : "); scanf_s("%lf", &a[n - 1].weight);
			fprintf_s(fp, "%-10s%6.1f%6.1f", a[n - 1].name, a[n - 1].height, a[n - 1].weight);
			n++;
			if (n - 1 == mn) {
				printf("データを書き込みました");
				break;
			}
			fprintf_s(fp, "\n");
		}
		fclose(fp);
	}	

	return 0;
}
#endif

#ifdef _1305
#include<time.h>

char data_file[] = "Timef.txt";
char feel[32];

//前回の実行日時の取得・表示
void get_data(void) {
	FILE* fp;

	fopen_s(&fp, data_file, "r");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		int year, month, day, hour, min, sec;
		fscanf_s(fp, "%d%d%d%d%d%d%s", &year, &month, &day, &hour, &min, &sec, feel,sizeof(feel));
		if (year == -858993460) {
			printf("本プログラムを実行するのは初めてですね。\n");
		}
		else {
			printf("前回は%d年%d月%d日%d時%d分%d秒で、気分は%sでした。\n", year, month, day, hour, min, sec, feel);
		}
		fclose(fp);
		printf("現在の気分は : ");
		scanf_s("%s", feel, sizeof(feel));
	}
}
//今回の実行日時の書き込み
void put_data(void) {
	FILE* fp;
	time_t current = time(NULL);
	struct tm timer;
	localtime_s(&timer, &current);

	fopen_s(&fp, data_file, "w");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		fprintf_s(fp, "%d %d %d %d %d %d %s\n",
			timer.tm_year + 1900, timer.tm_mon + 1, timer.tm_mday,
			timer.tm_hour, timer.tm_min, timer.tm_sec, feel);
		fclose(fp);
	}
}

int main(void) {
	get_data();
	put_data();

	return 0;
}
#endif

#ifdef _1306t
int main(void) {

	int ch = 0;
	FILE* fp;
	char fname[FILENAME_MAX] = { 0 };

	printf("ファイル名 : ");
	scanf_s("%s", fname, sizeof(fname));

	fopen_s(&fp, fname, "r");
	if (fp == NULL) {
		printf("\aファイルを開けません\n");
	}
	else {
		while ((ch = fgetc(fp)) != EOF) {
			putchar(ch);
		}
		fclose(fp);
	}

	return 0;
}
#endif

#ifdef _1306
int main(void) {
	int cnt = 1;
	int ch = 0;
	FILE* fp;
	char fname[FILENAME_MAX] = { 0 };

	printf("ファイル名 : ");
	scanf_s("%s", fname, sizeof(fname));
	fopen_s(&fp, fname, "r");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		while ((ch = fgetc(fp)) != EOF) {
			if (ch == '\n') cnt++;
		}
		printf("行数 : %d", cnt);
		fclose(fp);
	}

	return 0;
}
#endif

#ifdef _1307
int main(void) {
	int cnt[10] = { 0 };
	int ch = 0;
	FILE* fp;
	char fname[FILENAME_MAX] = { 0 };

	printf("ファイル名 : ");
	scanf_s("%s", fname, sizeof(fname));

	fopen_s(&fp, fname, "r");
	if (fp == NULL) {
		printf("\aファイルを開けません。");
	}
	else {
		while ((ch = fgetc(fp)) != EOF) {
			switch (ch) {
			case '0': cnt[0]++; break;
			case '1': cnt[1]++; break;
			case '2': cnt[2]++; break;
			case '3': cnt[3]++; break;
			case '4': cnt[4]++; break;
			case '5': cnt[5]++; break;
			case '6': cnt[6]++; break;
			case '7': cnt[7]++; break;
			case '8': cnt[8]++; break;
			case '9': cnt[9]++; break;
			}
		}
		fclose(fp);

		printf("ファイル内の各数字文字の個数\n");
		printf("「0」 : %d\n", cnt[0]);
		printf("「1」 : %d\n", cnt[1]);
		printf("「2」 : %d\n", cnt[2]);
		printf("「3」 : %d\n", cnt[3]);
		printf("「4」 : %d\n", cnt[4]);
		printf("「5」 : %d\n", cnt[5]);
		printf("「6」 : %d\n", cnt[6]);
		printf("「7」 : %d\n", cnt[7]);
		printf("「8」 : %d\n", cnt[8]);
		printf("「9」 : %d\n", cnt[9]);
	}
	

	return 0;
}
#endif

#ifdef _1308
int main(void) {
	int ch = 0;
	FILE* sfp;
	FILE* dfp;
	char sname[FILENAME_MAX] = { 0 };
	char dname[FILENAME_MAX] = { 0 };

	printf("コピー元のファイル名 : "); scanf_s("%s", sname, sizeof(sname));
	printf("コピー先のファイル名 : "); scanf_s("%s", dname, sizeof(dname));
	putchar('\n');

	fopen_s(&sfp, sname, "r");
	if (sfp == NULL) {
		printf("\aコピー元のファイルを開けません。\n");
	}
	else {
		fopen_s(&dfp, dname, "w");
		if (dfp == NULL) {
			printf("\aコピー先のファイルを開けません。\n");
		}
		else {
			printf("コピー内容 : ");
			while ((ch = fgetc(sfp)) != EOF) {
				fputc(ch, dfp);
				putchar(ch);
			}
			putchar('\n');
			printf("%sから%sにコピーしました。\n", sname, dname);
			fclose(dfp);
		}
		fclose(sfp);
	}

	return 0;
}
#endif

#ifdef _1309
#include<ctype.h>
int main(void) {
	int ch = 0;
	FILE* sfp;
	FILE* dfp;
	char sname[FILENAME_MAX] = { 0 };
	char dname[FILENAME_MAX] = { 0 };

	printf("コピー元ファイル名 : "); scanf_s("%s", sname, sizeof(sname));
	printf("コピー先ファイル名 : "); scanf_s("%s", dname, sizeof(dname));

	fopen_s(&sfp, sname, "r");
	if (sfp == NULL) {
		printf("\aコピー元のファイルを開けません。\n");
	}
	else {
		fopen_s(&dfp, dname, "w");
		if (dfp == NULL) {
			printf("\aコピー先のファイルを開けません。");
		}
		else {
			while ((ch = fgetc(sfp)) != EOF) {
				fputc(toupper(ch), dfp);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}

	return 0;
}
#endif

#ifdef _1310
#include<ctype.h>
int main(void) {
	int ch = 0;
	FILE* sfp;
	FILE* dfp;
	char sname[FILENAME_MAX] = { 0 };
	char dname[FILENAME_MAX] = { 0 };

	printf("コピー元ファイル名 : "); scanf_s("%s", sname, sizeof(sname));
	printf("コピー先ファイル名 : "); scanf_s("%s", dname, sizeof(dname));

	fopen_s(&sfp, sname, "r");
	if (sfp == NULL) {
		printf("\aコピー元のファイルを開けません。\n");
	}
	else {
		fopen_s(&dfp, dname, "w");
		if (dfp == NULL) {
			printf("\aコピー先のファイルを開けません。");
		}
		else {
			while ((ch = fgetc(sfp)) != EOF) {
				fputc(tolower(ch), dfp);
			}
			fclose(dfp);
		}
		fclose(sfp);
	}

	return 0;
}
#endif

#ifdef _1311
int main(void) {
	FILE* fp;
	double X[10] = { 1.4142135623730951,1.7320508075688772,2,2.23606797749979,
		2.449489742783178,2.6457513110645907,2.8284271247461903,3,3.1622776601683795 };

	fopen_s(&fp, "RT.bin", "wb");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		fwrite(&X, sizeof(double), 10, fp);
		fclose(fp);
	}

	fopen_s(&fp, "RT.bin", "rb");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		fread(&X, sizeof(double), 10, fp);
		printf("ファイルから読み取ったデータは\n");
		for (int i = 0; i < 9; i++) {
			printf("[√%2d] = %25.23f\n", i + 2, X[i]);
		}
		fclose(fp);
	}

	return 0;
}
#endif

#ifdef _1312
#include<time.h>

char data_file[] = "datatime.bin";

//前回の実行日時の取得・表示
void get_data(void) {
	FILE* fp;
	struct tm timer;
	fopen_s(&fp, data_file, "rb");
	if (fp == NULL) {
		printf("本プログラムを実行するのは初めてですね。\n");
	}
	else {
		fread(&timer, sizeof(struct tm), 1, fp);
		printf("前回は%d年%d月%d日%d時%d分%d秒でした。\n",
			timer.tm_year + 1900, timer.tm_mon, timer.tm_mday,
			timer.tm_hour, timer.tm_min, timer.tm_sec);
		fclose(fp);
	}
}
//今回の実行日時の書き込み
void put_data(void) {
	FILE* fp;
	time_t current = time(NULL);
	struct tm timer;
	localtime_s(&timer, &current);

	fopen_s(&fp, data_file, "wb");
	if (fp == NULL) {
		printf("\aファイルを開けません。\n");
	}
	else {
		fwrite(&timer, sizeof(struct tm), 1, fp);
		fclose(fp);
	}
}

int main(void) {
	get_data();
	put_data();

	return 0;
}

#endif

#ifdef _1313
#include<ctype.h>
int main(void) {
	int i = 0;
	int ch = 0;
	FILE* sfp;
	FILE* dfp;
	char sname[FILENAME_MAX] = { 0 };
	char dname[FILENAME_MAX] = { 0 };


	printf("コピー元のファイル名 : "); scanf_s("%s", sname, sizeof(sname));
	printf("コピー先のファイル名 : "); scanf_s("%s", dname, sizeof(dname));

	fopen_s(&sfp, sname, "rb");
	if (sfp == NULL) {
		printf("\aコピー元のファイルを開けません。\n");
	}
	else {
		fopen_s(&dfp, dname, "wb");
		if (dfp == NULL) {
			printf("\aコピー先のファイルを開けません。\n");
		}
		else {
			while (feof(sfp) == 0) {
				if (i != 0) {
					fwrite(&ch, 1, 1, dfp);
					putchar(ch);
				}
				fread(&ch, 1, 1, sfp);
				i++;
			}
		fclose(dfp);
		}
	fclose(sfp);
	}

	return 0;
}
#endif