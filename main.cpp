#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****0.�˳�ͨѶ¼*****" << endl;
	cout << "**********************" << endl;
}
struct Person //��ϵ�˽ṹ��
{
	string m_Name;//����
	int m_Sex;//�Ա� 1�� 2Ů
	int m_Age;//����
	string m_Phone;//�绰
	string m_Arrd;//��ַ
};
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;
};
void addPerson(Addressbooks* abs)
{
	//�ж��Ƿ�ﵽMAX������ﵽ�Ͳ������
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��

		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		//����Ա�������������
		abs->personArray[abs->m_size].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�" << endl;
		cout << "1---��\n2---Ů" << endl;
		for (;;)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "�����д�����������" << endl;
		}
	}

	//����
	int age = 0;
	cout << "����������" << endl;
	cin >> age;
	abs->personArray[abs->m_size].m_Age = age;

	//�绰
	string Phone;
	cout << "��������ϵ�绰" << endl;
	cin >> Phone;
	abs->personArray[abs->m_size].m_Phone = Phone;

	//��ͥסַ
	string address;
	cout << "�������ͥסַ" << endl;
	cin >> address;
	abs->personArray[abs->m_size].m_Arrd = address;

	//����ͨѶ¼����
	abs->m_size++;

	cout << "��ӳɹ�" << endl;

	system("pause");//�����������
	system("cls");//����
}
//��ʾ��ϵ��
void showPerson(Addressbooks* abs)
{
	//�ж�ͨѶ¼�����Ƿ�Ϊ0
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Arrd << endl;

		}
	}
	system("pause");
	system("cls");
}
int  isExist(Addressbooks* abs, string name)//�����ϵ���Ƿ���ڵĺ���
//����1 ͨѶ¼ ����2 �Ա�����
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//�ҵ�
		}
	}
	return -1;//û�ҵ�
}
void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;
	//ret==-1δ�鵽
	//ret != -1�ҵ�
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//�鵽���ˣ�ִ��ɾ��
		for (int i = ret; i < abs->m_size; i++)
		{
			//����ǰ��,�ú�������ݸ���ǰ��ģ��ﵽɾ��Ч��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//����ͨѶ¼����Ա��
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	//�ж��Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ���ϵ��
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Arrd << endl;
	}
	else//δ�ҵ���ϵ��
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}
//�޸�
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//�ҵ�
	{
		string name;
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex;
		cout << "�������Ա�" << endl;
		cout << "1---��\n2---Ů" << endl;
		for (;;)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "�����д�����������" << endl;
		}

		int age;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string Phone;
		cout << "������绰" << endl;
		cin >> Phone;
		abs->personArray[ret].m_Phone = Phone;

		string address;
		cout << "�������ͥסַ" << endl;
		cin >> address;
		abs->personArray[ret].m_Arrd = address;
		cout << "�޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//���
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;//����¼����ϵ��������Ϊ0�����߼����
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ����Ա����
	abs.m_size = 0;
	int select = 0;//�û���ѡ��

	while (1)
	{
		showMenu();//�˵��ĵ���
		cin >> select;
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ���ݿ����޸�ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
		{
			cout << "������ɾ����ϵ�˵�����" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
		}
		deletePerson(&abs);
		break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼  
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;//��ǰ����ϵͳ
			break;
		}
	}
	system("pause");
	return 0;
}