#include <stdio.h>
#include <string.h>

int main(){

	int n, i, j, k;

	char str[100][101] = {'\0',};

	char result[6000][101] = { '\0', };

	scanf("%d", &n);

	for (i = 0; i < n; i++){
		scanf("%s", &str[i]);
	}

	int row = 0, col = 0;

	for (i = 0; i < n; i++){
		for (j = 0; j < 100; j++){
			if (str[i][j] >= '0' && str[i][j] <= '9'){
				result[row][col++] = str[i][j];
				if (j + 1 >= 101 || !(str[i][j + 1] >= '0' && str[i][j + 1] <= '9')){
					row++;
					col = 0;
				}
			}
		}
	}

	for (i = 0; i < row; i++){
		int zerocount = 0;
		for (j = 0; j < strlen(result[i]); j++){
			if (result[i][j] == '0') zerocount++;
			else{
				break;
			}
		}
		if (zerocount > 0){
			if (strlen(result[i]) == zerocount){
				for (j = 1; j < strlen(result[i]); j++){
					result[i][j] = '\0';
				}
			}
			else{
				for (j = zerocount; j < strlen(result[i]); j++){
					result[i][j - zerocount] = result[i][j];
				}
				int templen = strlen(result[i]);
				for (k = 0; k < zerocount; k++){
					result[i][templen - 1 - k] = '\0';
				}
			}
			
		}
	}


	for (i = 0; i < row - 1; i++){

		for (j = i + 1; j < row; j++){
			if (strlen(result[i]) > strlen(result[j])){
				char temp[101], temp2[101];
				strcpy(temp, result[i]);
				strcpy(temp2, result[j]);
				strcpy(result[i], temp2);
				strcpy(result[j], temp);
			}
			else if (strlen(result[i]) == strlen(result[j])){
				for (k = 0; k < strlen(result[i]); k++){
					if (result[i][k] > result[j][k]){
						char temp3[101], temp4[101];
						strcpy(temp3, result[i]);
						strcpy(temp4, result[j]);
						strcpy(result[i], temp4);
						strcpy(result[j], temp3);
						break;
					}
					else if (result[i][k] < result[j][k]){
						break;
					}
				}
			}
		}
	}

	for (i = 0; i < row; i++){
		printf("%s\n", (result[i]));
		
	}

	return 0;
}