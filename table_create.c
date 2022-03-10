#include "local.h"

void createTable() {
	//_create("abcd", "code VARCHAR(20) number INT TP CHAR FLT FLOAT DBL DOUBLE");

	// [수주등록]
	_create("contract_regi", "con_num VARCHAR(10) con_date INT client VARCHAR(20) VAT VARCHAR(2) in_charge VARCHAR(20)");

	// [수주등록-물품등록]
	_create("contract_item_regi", "con_num VARCHAR(10) NO INT date INT item_num VARCHAR(20) item_name VARCHAR(20) due_date INT date_shipment INT amount INT unit_price FLOAT supply_price FLOAT tax FLOAT total_price FLOAT");

	// [BOM] - BOM_Num(순번), BOM_Code(품번코드), BOM_Name(품명), BOM_Amount(수량)
	_create("BOM", "BOM_Num INT BOM_Code VARCHAR(10) BOM_Name VARCHAR(20) BOM_Amount FLOAT");

	// [BOM 정전개] - BOM_F_Num(순번), BOM_F_Code(품번코드), BOM_F_Name(품명), BOM_F_Material(계정)
	_create("BOM_F", "BOM_F_Num INT BOM_F_Code VARCHAR(10) BOM_F_Name VARCHAR(20) BOM_F_Material VARCHAR(10)");

	// [BOM 역전개] - BOM_R_Num(순번), BOM_R_Code(품번코드), BOM_R_Name(품명), BOM_R_Material(계정)
	_create("BOM_R", "BOM_R_Num INT BOM_R_Code VARCHAR(10) BOM_R_Name VARCHAR(20) BOM_R_Material VARCHAR(10)");
	
	// [물품]
	_create("ITEM", "item_NAME VARCHAR(20) item_NUMBER VARCHAR(20) item_TYPE VARCHAR(20) item_GOAL INT item_LOT VARCHAR(20) item_SirealNUMBER VARCHAR(20)");

	// [발주] - num_BuyList(발주번호), name_item(품목이름), num_item(품목번호), date(날짜), name_responsible(담당자 이름), num_responsible(담당자 번호), num_in(발주 수량), bill(단가), pay_in (공급가액), tax(부가세), pay_sum(합계액), rest_num_in(남은 발주 수량)
	_create("Buy_item", "num_BuyList INT name_item VARCHAR(20) num_item INT date INT name_responsible VARCHAR(20) num_responsible INT num_buy INT bill INT pay_in INT tax INT pay_sum INT rest_num_in INT");

	// [작업실적등록]
	_create("performance", "work_order_num VARCHAR(20) Product_num VARCHAR(20) Product_name VARCHAR(20) client VARCHAR(20)indicated_quantity INT performance_quantity INT performance_num INT LOT VARCHAR(20)");
	//work_order_num(작업지시번호) Product_num(품번) Product_name(품명) client(고객) indicated_quantity(지시수량) performance_quantity(실적수량) performance_num(실적번호) LOT(LOT)

	// [생산품창고입고처리]
	_create("product_warehous", "work_order_num VARCHAR(20) performance_num VARCHAR(20) Product_num VARCHAR(20) Product_name VARCHAR(20) performance_quantity INT client VARCHAR(20) LOT VARCHAR(20) stock_num VARCHAR(20) stock_date INT stock_warehouse VARCHAR(20) stock_location VARCHAR(20) stock_count INT");
	//work_order_num(작업지시번호) performance_num(실적번호) Product_num(품번) Product_name(품명) performance_quantity(실적수량) client(고객) LOT stock_num(입고번호) stock_date(입고일자) stock_warehouse(입고창고) stock_location(입고장소) stock_count(입고수량) 

	// [입고]
	_create("In_WareHouse", "num_In_WareHouse INT name_warehouse VARCHAR(20) num_warehouse INT name_item VARCHAR(20) num_item INT LOT_number VARCHAR(20)  date INT name_responsible VARCHAR(20) num_responsible INT num_in INT bill INT pay_in INT tax INT pay_sum INT");
	// 입고순번, 창고이름, 창고번호, 품목명, 품번, 품목로트넘버, 날짜, 담당자명, 담당자번호, 입고수량, 단가, 공급가, 세금, 합계액

	// [거래처]
	_create("Buy_company", "name_buy_company VARCHAR(20) num_buy_company INT");
	//거래처명, 거래처번호

	// [담당자]
	_create("Person_responsibe", "name_responsible VARCHAR(20) num_responsible INT");
	//담당자명, 담당자번호

	// [창고]
	_create("WareHouse", "name_warehouse VARCHAR(30) num_warehouse INT");
	//창고이름, 창고번호

	// [생산계획등록]

	_create("Production_Plan_Registration", "Serial_Number INT Name VARCHAR(20) Daily_Capacity INT Order VARCHAR(20) ETC INT Quantity INT");
	//Serial_Number(품번) INT Name(품명) Daily_Capacity(일 생산량) Order(순서) ETC(작업예정일) Quantity(수량)

	// [작업지시등록]

	_create("Work_Order_Registration", "Due_Date INT Quantity INT Work_Instruction_Number INT LOT VARCHAR(20) Serial_Number INT Name VARCHAR(20) Customer VARCHAR(20)");
	//Work Instruction Number에 (제품구분+(공정)+날짜+번호) 들어감
	//Due_Date(납기일) Q(지시수량) Work_Instruction_Number(작업지시번호) LOT(LOT) Serial_Number(품번) Name(품명) Customer(고객)
}