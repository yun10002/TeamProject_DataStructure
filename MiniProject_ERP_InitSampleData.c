#include "local.h"
#include"MiniProject_ERP_struct_warehousing.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

void Create_File(void)
{
	// �԰����̺� ������ ����
	_create("In_WareHouse", "num_In_WareHouse INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) num_item VARCHAR(20) LOT_number VARCHAR(20)  date INT name_responsible VARCHAR(20) num_responsible INT num_in INT bill INT pay_in INT tax INT pay_sum INT");
							// �԰����				â���̸�						â���ȣ			ǰ���					ǰ��			ǰ���Ʈ�ѹ�				��¥		����ڸ�							����ڹ�ȣ		�԰����		�ܰ�		���ް�		����		�հ��
	
	// �������̺� ������ ����
	_create("Buy_item", "num_BuyList INT item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_LOT VARCHAR(20) date INT name_responsible VARCHAR(20) num_responsible INT num_buy INT bill INT pay_in INT tax INT pay_sum INT rest_num_in INT");
	//						���ֹ�ȣ			ǰ���				ǰ��					ǰ���Ʈ�ѹ�				��¥			����ڸ�						����ڹ�ȣ		���ּ���		�ܰ�		���ް���		����			�հ��			�������ּ���
	
	// �ŷ�ó���̺� ������ ����
	_create("Buy_company", "name_buy_company VARCHAR(20) num_buy_company INT");
	//							�ŷ�ó��						�ŷ�ó��ȣ
	
	// ��������̺� ������ ����
	_create("Person_responsibe", "name_responsible VARCHAR(20) num_responsible INT");
	//								����ڸ�							����ڹ�ȣ
	
	// ǰ�����̺� ������ ����
	_create("ITEM", "item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_TYPE VARCHAR(20) item_GOAL INT item_LOT VARCHAR(20) item_SirealNUMBER VARCHAR(20)");
	//				ǰ���					ǰ��						��������				���ϻ��귮		�����Ʈ�ѹ�				�ø���ѹ�
	
	// â������̺� ������ ����
	_create("WareHouse", "name_warehouse VARCHAR(30) num_warehouse INT");
	//						â���̸�						â���ȣ

	// <�����ȹ���>
	_create("Production_Plan_Registration", "Item_Number VARCHAR(20) Name VARCHAR(20) Daily_Capacity INT Order VARCHAR(20) ETC INT Quantity INT");
	//											ǰ��					ǰ��					�� ���귮			����			�۾�������	����

	//<�۾����õ��>
	_create("Work_Order_Registration", "Due_Date INT Quantity INT Work_Instruction_Number INT LOT VARCHAR(20) Item_Number VARCHAR(20) Name VARCHAR(20) Customer VARCHAR(20)");
	//Work Instruction Number�� (��ǰ����+(����)+��¥+��ȣ) ��
	//									������		 ���ü���		�۾����ù�ȣ					LOT				ǰ��						ǰ��				��

}

void Init_SampleData(void)
{
	// �԰����̺� ���õ����� ����
	if (initalizing("In_WareHouse") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("1, 'Warehouse1', 1999, 'CPU','CP10', 'CP20220308', 20220305, 'SamplePerson1', 199, 100, 990, 99000, 9900, 108900") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("2, 'Warehouse2', 2999, 'HARD', 'HR10', 'HR20220308', 20220307,  'SamplePerson1', 199, 20, 1000, 20000, 2000, 22000") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("3, 'Warehouse1', 1999, 'MAINBORAD', 'MB10', 'MB20220308', 20220301, 'SamplePerson1', 199, 100, 100, 10000, 1000, 11000") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	int num_Warehousing_List = 3;
	//print_data();
	//printf("\n");
	
	file_column_free();


	// �������̺� ���õ����� ����
	if (initalizing("Buy_item") == -1) 
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("1, 'CPU','CP10','CP20220308', 20220304, 'SamplePerson1', 199, 100, 1000, 10000, 1000, 11000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("2, 'MONITOR', 'MO10', 'MO20220308', 20220304, 'SamplePerson2', 299, 200, 2000, 40000, 4000, 44000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}
	if (_insert("3, 'CASE', 'CA10','CA20220308', 20220304, 'SamplePerson1', 199, 300, 3000, 90000, 9000, 99000, 100") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	
	file_column_free();


	// �ŷ�ó���̺� ���õ����� ����
	if (initalizing("Buy_company") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Buyer1', 199999") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	file_column_free();



	// ��������̺� ���õ����� ����
	if (initalizing("Person_responsibe") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SamplePerson1', 199") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'SamplePerson2', 299") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	file_column_free();
	

	// ǰ�����̺� ���õ����� ����
	if (initalizing("item") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'CPU','CP10','meterial',100,'CP20220308','C19999P19'") == -1) {
		//1.��ǰ�� cpu 2.��ǰ��ȣ cp10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ cp20220308 6.�ø��� ��ȣ c19999p19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'HARD','HR10','meterial',100,'HR20220308','H1999R19'") == -1) {
		//1.��ǰ�� hard 2.��ǰ��ȣ hr10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ hr20220308 6.�ø��� ��ȣ h1999r19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'KEYBORAD','KE10','submeterial',100,'KE20220308','K1999E19'") == -1) {
		//1.��ǰ�� keyborad 2.��ǰ��ȣ ke10 3.��ǰ�������� submeterial 4.�ϻ��귮 100 5.LOT��ȣ ke20220308 6.�ø��� ��ȣ k1999e19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'MAINBORAD','MB10','meterial',100,'MB20220308','M1999B19'") == -1) {
		//1.��ǰ�� mainborad 2.��ǰ��ȣ mb10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ mb20220308 6.�ø��� ��ȣ m1999b19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'MONITOR','MO10','submeterial',100,'MO20220308','M1999O19'") == -1) {
		//1.��ǰ�� monitor 2.��ǰ��ȣ mo10 3.��ǰ�������� submeterial 4.�ϻ��귮 100 5.LOT��ȣ mo20220308 6.�ø��� ��ȣ m1999o19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'CASE','CA10','meterial',100,'CA20220308','C1999A19'") == -1) {
		//1.��ǰ�� case 2.��ǰ��ȣ ca10 3.��ǰ�������� meterial 4.�ϻ��귮 100 5.LOT��ȣ ca20220308 6.�ø��� ��ȣ c1999a19
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	//print_data();
	//printf("\n");
	
	file_column_free();

	// â�����̺� ���õ����� ����
	if (initalizing("WareHouse") == -1) {
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse1', 1999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse2', 2999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}

	if (_insert("'Warehouse3', 3999 ") == -1)
	{
		printf("%s\n", err_msg);

		file_column_free();
		return -1;
	}


	//print_data();
	//printf("\n");
	file_column_free();
	
}