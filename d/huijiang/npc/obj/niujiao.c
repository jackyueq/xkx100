// Room: /d/huijiang/npc/obj/niujiao.c
// Last Modified by winder on Sep. 12 2001
inherit ITEM;

void create()
{
	set_name("��ţ��", ({"niu jiao"}));
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long", "һ֧ţ�ǣ����ŵ���⡣\n");
		set("unit", "֧");
		set("value", 1000);
	}
}


