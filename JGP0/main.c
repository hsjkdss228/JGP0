#include "utils.h"

int main(void){

	while(1){
		printf("���� �Է�: ");
		getPathFromUser();

		//�Է��� �ְ� ��δ� ��ȿ�ϸ� ��ΰ� ���丮�� ��� 
		if(directory[0] != 0 && isPathValid(directory) && isDir(directory)){
			cd(directory);
			break;
		}
		printf("�������� �ʰų� ������ �Ұ����� �����Դϴ�.\n");
		
		//printf("%s\n", directory); //directory �� Ȯ�� �׽�Ʈ��
	}

	while(1){
		CMD* cmd = 0;
		char** cmd_with_arg = 0;
		int result = 0;
		printf("��ɾ� �Է�: ");
		getCommand(_buffer);


		//cmd_with_arg[0] ��ɾ� ���ڿ� ,[1] ���� ���ڿ�
		//�ʿ�������� �ݵ�� freeCommandWithArg �� �޸� ����
		cmd_with_arg = getCommandWithArg(_buffer);


		if(cmd_with_arg == 0){
			continue;
		}

		//cmd->cmd_char ��ɾ� ���ڿ�
		//cmd->cmd_func ��ɾ� �Լ� ������, exit�� ��� �Լ������ʹ� �������� ����
		cmd = isCommandExist(cmd_with_arg[0]); 
		printf("%s/%s \n", cmd_with_arg[0], cmd_with_arg[1]); //cmd�� Ȯ��
		if((_buffer[0] == 0) || cmd == 0){
			printf("ó���� �� ���� ��ɾ��Դϴ�.\n");
			freeCommandWithArg(cmd_with_arg);
			continue;
		}

		//��ɾ exit�ΰ�� ���� Ż��
		if(strcmp(cmd->cmd_char, "exit") == 0){
			printf("exit");
			freeCommandWithArg(cmd_with_arg);
			break;
		} else{
			result = cmd->cmd_func(cmd_with_arg[1]);
			//������� 0�� �ƴ� ��� �����߻����� ����
			if(result != 0){
				printf("ó���� �� ���� ��ɾ��Դϴ�.\n");
			}
			freeCommandWithArg(cmd_with_arg);
		}
	}
	return 0;
}

