// Room: /d/wuxi/dayifenduo.c
// Last Modifyed by Winder on Dec. 4 2001
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "����ֶ�");
	set("long", @LONG
�������������е�ؤ�����ֶ档�ֶ�Ⱥؤ�����ݵ��ϣ������ְ
˾ǰ��Ȼ�����ӱ���һ����ݶ�(dui) ������ʮ��ƽ�����������ܾ�
���е���֡�
LONG );
	set("item_desc", ([
		"dui"  : "����ϸһ�������������ˣ��Ǻǣ��ݶ������и��ں����Ĵ󶴿ڣ�\n",
	]));
	set("exits", ([
		"south" : __DIR__"xinlin1",
	]));
	set("objects", ([
		CLASS_D("gaibang") + "/jiang" : 1,
		CLASS_D("gaibang") + "/bangzhong" : random(5),
	]));
	set("coor/x", 400);
	set("coor/y", -740);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me;
	mapping fam;

	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dui" )
	{
		if((fam = me->query("family")) && fam["family_name"] == "ؤ��" )
		{
			message("vision",
				me->name() + "����ؤ�����ǹ���һ�������ݶ��µĶ������˽�ȥ��\n",
				environment(me), ({me}) );
			me->move("/d/gaibang/underwx");
                	message("vision", me->name() + "�Ӷ������˽�����\n", environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("��ôС�Ķ�������ý�ȥ��\n");
	}
}	

