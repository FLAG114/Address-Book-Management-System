#include<iostream>
using namespace std;
#include<string>
#define MAX 1000
void showMenu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****0.退出通讯录*****" << endl;
	cout << "**********************" << endl;
}
struct Person //联系人结构体
{
	string m_Name;//姓名
	int m_Sex;//性别 1男 2女
	int m_Age;//年龄
	string m_Phone;//电话
	string m_Arrd;//地址
};
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_size;
};
void addPerson(Addressbooks* abs)
{
	//判断是否达到MAX，如果达到就不再添加
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体联系人

		//姓名
		string name;
		cout << "请输入名字" << endl;
		cin >> name;
		//按人员个数往里面添加
		abs->personArray[abs->m_size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别" << endl;
		cout << "1---男\n2---女" << endl;
		for (;;)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有错误重新输入" << endl;
		}
	}

	//年龄
	int age = 0;
	cout << "请输入年龄" << endl;
	cin >> age;
	abs->personArray[abs->m_size].m_Age = age;

	//电话
	string Phone;
	cout << "请输入联系电话" << endl;
	cin >> Phone;
	abs->personArray[abs->m_size].m_Phone = Phone;

	//家庭住址
	string address;
	cout << "请输入家庭住址" << endl;
	cin >> address;
	abs->personArray[abs->m_size].m_Arrd = address;

	//更新通讯录人数
	abs->m_size++;

	cout << "添加成功" << endl;

	system("pause");//按任意键继续
	system("cls");//清屏
}
//显示联系人
void showPerson(Addressbooks* abs)
{
	//判断通讯录人数是否为0
	if (abs->m_size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Arrd << endl;

		}
	}
	system("pause");
	system("cls");
}
int  isExist(Addressbooks* abs, string name)//检测联系人是否存在的函数
//参数1 通讯录 参数2 对比姓名
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;//找到
		}
	}
	return -1;//没找到
}
void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//ret==-1未查到
	//ret != -1找到
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//查到此人，执行删除
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据前移,让后面的数据覆盖前面的，达到删除效果
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;//更新通讯录中人员数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;
	//判断是否存在
	int ret = isExist(abs, name);
	if (ret != -1)//找到联系人
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Arrd << endl;
	}
	else//未找到联系人
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}
//修改
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)//找到
	{
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		int sex;
		cout << "请输入性别" << endl;
		cout << "1---男\n2---女" << endl;
		for (;;)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有错误重新输入" << endl;
		}

		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;

		string Phone;
		cout << "请输入电话" << endl;
		cin >> Phone;
		abs->personArray[ret].m_Phone = Phone;

		string address;
		cout << "请输入家庭住址" << endl;
		cin >> address;
		abs->personArray[ret].m_Arrd = address;
		cout << "修改成功！" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空
void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;//将记录的联系人数量置为0，做逻辑清空
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}
int main()
{
	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化通讯录中当前的人员个数
	abs.m_size = 0;
	int select = 0;//用户的选择

	while (1)
	{
		showMenu();//菜单的调用
		cin >> select;
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);//利用地址传递可以修改实参
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
		{
			cout << "请输入删除联系人的姓名" << endl;
			string name;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				cout << "找到此人" << endl;
			}
		}
		deletePerson(&abs);
		break;
		case 4://查找联系人
			findPerson(&abs);
			break;
		case 5://修改联系人
			modifyPerson(&abs);
			break;
		case 6://清空联系人
			cleanPerson(&abs);
			break;
		case 0://退出通讯录  
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;//提前结束系统
			break;
		}
	}
	system("pause");
	return 0;
}