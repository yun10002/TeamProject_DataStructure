#ifndef __STRUCT_H__
#define __STRUCT_H__

// ERP �ý��� �԰�ó���� ���� ����ü�� �԰��� ����

void Create_File(void);
void Init_SampleData(void);
void Insert_WarehousingData(void);
void Insert_WarehousingData_from_BuyingList(void);
void print_Warehousing_state(void);
void delete_Warehousing(void);
void Insert(void);
void edit_minus_table(void);		////���� �Ѱ��ָ� ���� �ϳ��� ���� �Ѱ��ֱ�
void edit_plus_table(void);			////�԰��� ������ŭ �����ֱ�
void jaego_print1(void);			////���� ��� ���� ����ؼ� ��ȸ
void initCreate();
void initSampledata();

typedef struct In_WareHouse					// �԰���ü
{
	int num_In_WareHouse;			// �԰����
	char name_warehouse[20];		// â���̸�
	int num_warehouse;				// â���ȣ
	char name_item[20];				// ǰ���̸�
	char num_item[20];					// ǰ���ȣ
	char LOT_number[20];			// ǰ�� ��Ʈ�ѹ�
	int date;						// �԰�¥
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
	int num_in;						// �԰����
	int bill;						// �ܰ�
	int pay_in;						// ���ް��� = �԰���� * �ܰ�
	int tax;						// �ΰ��� = ���ް��� * 0.1
	int pay_sum;					// �հ�� = ���ް��� + �ΰ���;
}warehouse;

typedef struct jaego					// ��� ��ȸ ����ü
{
	int num_Jaego;					// ������
	char name_item[20];				// ǰ���̸�
	char num_item[20];				// ǰ���ȣ
	char name_warehouse[20];		// â���̸�
	int num_warehouse;				// â���ȣ
	char LOT_number[20];			// ǰ�� ��Ʈ�ѹ�
	int date;						// �԰�¥
	int num_chogi_item;				// �ʱ����
	int num_in;						// �԰����
	int num_chulgo_item;			// ������
	int num_jaego_item;				// ���� ��� ����


}Jaego;

struct Buy_item						// ���� ����ü
{
	int num_buyList;				// ���ֹ�ȣ
	char name_item[20];				// ����ǰ��
	int num_item;					// ����ǰ��
	int date;						// ���ֳ�¥
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
	int num_buy;					// ���ּ���
	int bill;						// �ܰ�
	int pay_in;						// ���ް��� = ���ּ��� * �ܰ�
	int tax;						// �ΰ��� = ���ް��� * 0.1
	int pay_sum;					// �հ�� = ���ް��� + �ΰ���;
	int rest_num_in;				// �������ּ���(���� �԰�ɽ� ���� �԰��������� ����)
};

struct Buy_company					// �ŷ�ó����ü
{
	char name_buy_company[20];		// �ŷ�ó �̸�
	int num_buy_company;			// �ŷ�ó ��ȣ
};

struct Person_responsibe			// ����ڱ���ü
{
	char name_responsible[20];		// ������̸�
	int num_responsible;			// ����ڹ�ȣ
};

struct item							// ǰ����ü
{
	char name_item[20];				// ǰ�� ǰ��
	int num_item;					// ǰ�� ǰ��
	char State[20];					// ��������  - ������)RawMaterial, ����ǰSubsidiary, ��ǰProduct
	int Daily_Output;				// ���� ���귮
	char LOT_number[20];			// RA = ������, SU =	����ǰ, PR = ��ǰ
									// ex) 
};

typedef struct Work_Use			// ���� ���(�۾���) ����ü
{
	char work_order_num[20];	//�۾����ù�ȣ
	char Product_num[20];		// ǰ���ȣ
	char Product_name[20];		// ǰ���̸�
	int Amountused;				//������
	int Performanced_number;	//������ȣ
	char LOT[20];				//lot�ѹ�

}workuse;


typedef struct Work_process			// �۾����� �κ� 
{
	char work_order_num[20];	//�۾����ù�ȣ
	char Product_name[20];		//ǰ��
	char Product_num;			//ǰ��
	char client[10];			//�̸�
	int indicated_quantity;		//���ü���
	int performance_quantity;	//��������
	int performance_num;		//������ȣ
	char LOT[20];				//����lot�ѹ�

};

typedef struct Work_Productwork		// ��������Ȳ(��ǰ��)
{
	int work_order_num;	//�۾����ù�ȣ(�۾����úκ�)
	int Product_num;		//ǰ���ȣ(�۾����úκ�)
	char Product_name[20];	//ǰ���̸�(�۾����úκ�)
	int LOT;				//lot��ȣ(�۾����úκ�)
	int indicated_quantity;	//���ü���=��������(�۾����úκ�)
	char item_NUMBER[20];	//��ǰ��ȣ(��ǰ��Ϻκ�)
	char item_NAME[20];		//��ǰ��
	char item_LOT[20];		//��ǰ lot��ȣ
	int Amountused;			//������(�Է�)

};

typedef struct ITEM			// ��ǰ���
{
	char item_NAME[20];		//��ǰ��
	char item_NUMBER[20];	//��ǰ��ȣ
	char item_TYPE[20];
	int item_GOAL;
	char item_LOT[20];
	char tem_SirealNUMBER[20];
};


/* ����ǰ û����� -> �۾�����
   �������(�Է�)
   ǰ��,ǰ��,�԰�,���� LOT�ѹ�-> ���� ǰ����ü����Ʈ��������
   ������ (�Է�)
   ����, �۾��� �Է� , ������ȣ*/


	// < �԰�ó�� >
		/*
		
		���� - 1. �����԰� 2. �����԰�

		1. �����԰�
		(�����԰�� ��ȭ���ֵ����� ������ ǰ���� �԰� �Է��ϴ� ��)

		�԰�����(�Է�)
		�ŷ�ó(���� - �����κ��� �ŷ�ó����ü����Ʈ�� �޾ƿ�)
		�����(���� - �����κ��� ����� ����ü����Ʈ �޾ƿ�)
		ǰ��(���� - �����κ��� ǰ����ü����Ʈ �޾ƿ�)
		���ּ���(�Է�)
		�ܰ�(�Է�)

		------------���� �Է¹ް�,

		���ް���(�ڵ���� : ���ּ��� * �ܰ�)
		�ΰ���(�ڵ���� : ���ް� * 0.1)
		�հ��(�ڵ���� : �ΰ��� + ���ް���)

		------------�� ����ؼ� ��������� �Է� / ��� ������ ��Ŀ� �°� �����
		����ڷκ��� �Է³����� ������ �Է�(1), Ʋ����(2)�Է¹���

		�´�(1)->�԰���ü�� �� ������ ����(����)

		2. �����԰�

		1) ������Ȳ�� ���(�����κ��� ���ֱ���ü�� �޾ƿ�)�ϰ� ���⼭ � ���ֻ��׿� ���ؼ� �԰����� ����
		2) ������ ���ֻ����� � ǰ���� �԰����� �Է�
		3) �԰������ �Է�(�̶�, �԰������ �������ּ����� �Ѵ��� Ȯ��)
		4) ������� ������ ����� �´��� �����Ȯ���� ���ֱ���ü(����)�� �������ּ��������(�ʱⰪ�� ���ּ���, �԰�ɶ����� �԰������ ����)
		5) �԰���ü�� �������(����)

		*/

#endif