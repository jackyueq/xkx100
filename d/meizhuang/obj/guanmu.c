// guanmu.c
// Last Modified by winder on Sep. 27 2001

inherit ITEM;

void create()
{
	set_name("��ľ", ({ "guanmu" , "��ľ"}) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ�Բ�֪���Ĺ�ľ�������ú�ïʢ��\n");
		set("value", 1);
	}
}

