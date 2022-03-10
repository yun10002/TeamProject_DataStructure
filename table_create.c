#include "local.h"

void createTable() {
	//_create("abcd", "code VARCHAR(20) number INT TP CHAR FLT FLOAT DBL DOUBLE");

	// [���ֵ��]
	_create("contract_regi", "con_num VARCHAR(10) con_date INT client VARCHAR(20) VAT VARCHAR(2) in_charge VARCHAR(20)");

	// [���ֵ��-��ǰ���]
	_create("contract_item_regi", "con_num VARCHAR(10) NO INT date INT item_num VARCHAR(20) item_name VARCHAR(20) due_date INT date_shipment INT amount INT unit_price FLOAT supply_price FLOAT tax FLOAT total_price FLOAT");

	// [BOM] - BOM_Num(����), BOM_Code(ǰ���ڵ�), BOM_Name(ǰ��), BOM_Amount(����)
	_create("BOM", "BOM_Num INT BOM_Code VARCHAR(10) BOM_Name VARCHAR(20) BOM_Amount FLOAT");

	// [BOM ������] - BOM_F_Num(����), BOM_F_Code(ǰ���ڵ�), BOM_F_Name(ǰ��), BOM_F_Material(����)
	_create("BOM_F", "BOM_F_Num INT BOM_F_Code VARCHAR(10) BOM_F_Name VARCHAR(20) BOM_F_Material VARCHAR(10)");

	// [BOM ������] - BOM_R_Num(����), BOM_R_Code(ǰ���ڵ�), BOM_R_Name(ǰ��), BOM_R_Material(����)
	_create("BOM_R", "BOM_R_Num INT BOM_R_Code VARCHAR(10) BOM_R_Name VARCHAR(20) BOM_R_Material VARCHAR(10)");
	
	// [��ǰ]
	_create("ITEM", "item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_TYPE VARCHAR(20) item_GOAL INT item_LOT VARCHAR(20) item_SirealNUMBER VARCHAR(20)");

	// [����] - num_BuyList(���ֹ�ȣ), name_item(ǰ���̸�), num_item(ǰ���ȣ), date(��¥), name_responsible(����� �̸�), num_responsible(����� ��ȣ), num_in(���� ����), bill(�ܰ�), pay_in (���ް���), tax(�ΰ���), pay_sum(�հ��), rest_num_in(���� ���� ����)
	_create("Buy_item", "num_BuyList INT name_item VARCHAR(20) num_item INT date INT name_responsible VARCHAR(20) num_responsible INT num_buy INT bill INT pay_in INT tax INT pay_sum INT rest_num_in INT");

	// [�۾��������]
	_create("performance", "work_order_num VARCHAR(20) Product_num VARCHAR(20) Product_name VARCHAR(20) client VARCHAR(20)indicated_quantity INT performance_quantity INT performance_num INT LOT VARCHAR(20)");
	//work_order_num(�۾����ù�ȣ) Product_num(ǰ��) Product_name(ǰ��) client(��) indicated_quantity(���ü���) performance_quantity(��������) performance_num(������ȣ) LOT(LOT)

	// [����ǰâ���԰�ó��]
	_create("product_warehous", "work_order_num VARCHAR(20) performance_num VARCHAR(20) Product_num VARCHAR(20) Product_name VARCHAR(20) performance_quantity INT client VARCHAR(20) LOT VARCHAR(20) stock_num VARCHAR(20) stock_date INT stock_warehouse VARCHAR(20) stock_location VARCHAR(20) stock_count INT");
	//work_order_num(�۾����ù�ȣ) performance_num(������ȣ) Product_num(ǰ��) Product_name(ǰ��) performance_quantity(��������) client(��) LOT stock_num(�԰��ȣ) stock_date(�԰�����) stock_warehouse(�԰�â��) stock_location(�԰����) stock_count(�԰����) 

	// [�԰�]
	_create("In_WareHouse", "num_In_WareHouse INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) num_item INT LOT_number VARCHAR(20)  date INT name_responsible VARCHAR(20) num_responsible INT num_in INT bill INT pay_in INT tax INT pay_sum INT");
	// �԰����, â���̸�, â���ȣ, ǰ���, ǰ��, ǰ���Ʈ�ѹ�, ��¥, ����ڸ�, ����ڹ�ȣ, �԰����, �ܰ�, ���ް�, ����, �հ��

	// [�ŷ�ó]
	_create("Buy_company", "name_buy_company VARCHAR(20) num_buy_company INT");
	//�ŷ�ó��, �ŷ�ó��ȣ

	// [�����]
	_create("Person_responsibe", "name_responsible VARCHAR(20) num_responsible INT");
	//����ڸ�, ����ڹ�ȣ

	// [â��]
	_create("WareHouse", "name_warehouse VARCHAR(30) num_warehouse INT");
	//â���̸�, â���ȣ

	// [�����ȹ���]

	_create("Production_Plan_Registration", "Serial_Number INT Name VARCHAR(20) Daily_Capacity INT Order VARCHAR(20) ETC INT Quantity INT");
	//Serial_Number(ǰ��) INT Name(ǰ��) Daily_Capacity(�� ���귮) Order(����) ETC(�۾�������) Quantity(����)

	// [�۾����õ��]

	_create("Work_Order_Registration", "Due_Date INT Quantity INT Work_Instruction_Number INT LOT VARCHAR(20) Serial_Number INT Name VARCHAR(20) Customer VARCHAR(20)");
	//Work Instruction Number�� (��ǰ����+(����)+��¥+��ȣ) ��
	//Due_Date(������) Q(���ü���) Work_Instruction_Number(�۾����ù�ȣ) LOT(LOT) Serial_Number(ǰ��) Name(ǰ��) Customer(��)
}