// Room: /d/nanshaolin/xiaoxi1.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
int do_jump(string arg);

void create()
{
	set("short", "Ϫ�Կյ�");
	set("long", @LONG
����Ϫ�Ե�һ��յأ������̲����𣬼���׺��һЩ�в�������
��Ұɽ����Զ������������¶��һƬ��ǽ�����������Ѿ������б�Ե��
���ˡ�ǰ���Ϊ���ĵط�����һ��Ъɽ���ܣ��߶��㣬�������ӵ�¥
��¥����һ�����ң����顺�ؾ��������֡�
    ������һ��СϪ��
LONG );
	set("exits", ([
		"enter" : __DIR__"cjlou",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1880);
	set("coor/y", -6150);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "xiaoxi")
	{
		if (me->query_skill("dodge", 1) >= 60)
		{
			message("vision", me->name() + "���˿��������������Ծȥ��\n", environment(me), ({me}) );
			write("�����˿��������������Ծȥ��\n");
			me->move(__DIR__"xiaoxi");
			message("vision", "ֻ����Ӱһ����"+me->name() +"����Ծ�˹�����\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			message("vision", me->name()+"���������Ծȥ��ֻ������ͨ��һ����"+me->name()+"ˤ��Ϫ�У��Ǳ������˻�����\n",environment(me),({me}));
			write( "�����������Ծȥ��ֻ������ͨ��һ������ˤ��Ϫ�У��Ǳ������˻�����\n");
			me->receive_damage("qi",30);
			return 1;
		}
	}
	return 0;
}


