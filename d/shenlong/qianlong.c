// /d/shenlong/qianlong Ǳ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "Ǳ����");
	set("long", @LONG
���������̵�Ǳ���ã��������Ŵ����Σ������������Ű�ʣ�����
������ʹ���ڴ��������£�����ǽ��������ǲ����Խ���˵صġ�
LONG
	);
	set("exits", ([
		"out" : __DIR__"zhulin1",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/hong" : 1,
		CLASS_D("shenlong")+"/su" : 1,
	]));
	setup();
}

void init()
{
	object *inv, me = this_player();

	if( !(me->query("family/family_name") == "������" ||
		me->query("sg/spy")) )
	{
		inv = all_inventory(this_object());
		for(int i = 0; i < sizeof(inv); i++ )
			if( (inv[i]->query("family/family_name") == "������" ||
				inv[i]->query("sg/spy")) && living(inv[i]) )
				inv[i]->kill_ob(me);
		me->start_busy(1);
	}
}
