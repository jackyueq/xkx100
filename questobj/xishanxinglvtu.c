// xishanxinglvtu.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"Ϫɽ����ͼ"NOR,({"painting","xi shan xing lv tu","tu"}) );
	set("taskobj", 1);
	set("long","���Ǿ�˵�Ѿ�ʧ���˵ķ����漣�����ڰ���֮�ˣ������޼�֮���ˡ�\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set_weight(20);
	}
	setup();
}

