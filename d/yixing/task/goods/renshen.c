// /d/yixing/task/goods/renshen.c �˲�
// Last Modified by winder on Jul. 12 2002

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("����ɽ�˲�", ({"renshen", "shen"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "����һ��մ��ɽ��ĳ���ɽ�˲Ρ�\n");
		set("value", 10000);
		set("medicine", 1);
	}
	setup();
}
