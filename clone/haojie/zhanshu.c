// Last Modified by winder on Apr. 25 2001
// zhanshu.c

#include <ansi.h>
inherit ITEM;
int is_zhanshu() {return 1;}

void create()
{
	set_name( HIR"��ս��"NOR,({ "zhan shu","shu","book"}));
	set_weight(200);
	seteuid(getuid());
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long","����һ����ɱ��������ɱ�ǵ���ս��(kan)��\n");
		set("value", 5000);
		set("material", "paper");
	}
}

void init()
{
	add_action("do_kan","kan");
}

int do_kan(string arg)
{
	if ( !id(arg) )
		return notify_fail("���뿴ʲô��\n");
	write(HIR"            ������֮Լ��\n\n"NOR);
	write(WHT"    ������ʮ����֮�ڱ����찲�Ź㳡���Ҿ�\n");
	write(WHT"һ��ս�������߾��ǹ��ܣ�\n\n");
	write(WHT"                      ��ɱ�����죺"HIR"��ɱ��\n"NOR);
	return 1;
}
