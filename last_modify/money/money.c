// /inherit/item/money.c
// Modified by Zeratul Jan 1 2001, �˳�ʱ���ϵ�Ǯ����ʧ

inherit COMBINED_ITEM;

int value() { return query_amount() * (int)query("base_value"); }

/*string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if( sscanf(param, "%d", amt)==1 )
		set_amount(amt);
}*/
