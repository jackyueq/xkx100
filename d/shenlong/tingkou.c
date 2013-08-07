// /d/shenlong/datingkou ������
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});

void create()
{
	set("short", "������");
	set("long", @LONG
���Ǵ������ſڣ����ڿɽ��������̵Ĵ������ſ�վ�����������
�Ľ�ͽ��ȫ����װ�������ע�����ܣ���������ϡ����һ������������
�ƺ����������ٿ�ʲô��Ҫ���顣
LONG
	);
	set("valid_startroom",1);
	set("outdoors", "shenlong");
	set("exits", ([
		"west"  : __DIR__"changlang",
		"enter" : __DIR__"dating",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/first" : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
	]));
	setup();
	"/clone/board/shenlong_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping myfam = (mapping)me->query("family");
	object *inv;
	int haveguarder;

	if( !(me->query("sg/spy") ||
		me->query("family/family_name") == "������") &&
		dir == "enter" )
	{
		inv = all_inventory(this_object());
		for(int i = 0; i < sizeof(inv); i++ )
			if( inv[i]->query("family/family_name") == "������" ||
				inv[i]->query("sg/spy") )
			{
				 haveguarder++;
				 if( living(inv[i]) ) inv[i]->kill_ob(me);
			}
		if( haveguarder > 0 )
			return notify_fail("��Ҳ̫Ŀ�������˰ɣ���������������ء�\n");
	 }

	 return ::valid_leave(me, dir);
}

