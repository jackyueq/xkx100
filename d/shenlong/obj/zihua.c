// /d/shenlong/obj/zihua.c
// Last Modified by winder on Jul. 12 2002

inherit ITEM;

void create()
{
	set_name("�׹���", ({ "jiaguwen" }));
	set("weight", 1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","ֽ��һ�����ֶ������һ�㡣\n���Ǵ���̨ɽ������ռ�����ʯ�����������ļ׹��ġ�\n");
		set("unit", "��");
		set("value", 20);
	}

	setup();
}

