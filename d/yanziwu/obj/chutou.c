// chutou.c
inherit ITEM;

void create()
{
	set_name("��ͷ", ({ "chu tou" }));
	set_weight(12000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "����һ�ѳ��صĳ�ͷ��\n");
		set("unit", "��");
		set("value", 0);
	}
}

