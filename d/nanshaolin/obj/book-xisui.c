// book-xisui.c
// Last Modified by winder on May. 29 2001

inherit ITEM;

void create()
{
	set_name("ϴ�辭", ({ "xisui", "shu", "book" }));
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ɫ���Ʋ���������������Ļ��˲��ٴ������ŵ����ơ�\n");
                set("treasure", 1);
		set("value", 500);
		set("material", "cloth");
	}
}
