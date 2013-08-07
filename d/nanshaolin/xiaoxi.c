// Room: /d/nanshaolin/xiaoxi.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "СϪ");
	set("long", @LONG
����һ���ɺ�ɽ��������Ϫ����СϪ����������һԾ�ƺ��Ϳɱ�
���԰���Ϫ����������ݳ��ü���ïʢ����������֮�У�����������
����Ϫ����ˮ���峺�����������Ŀ���ˮ�׵Ķ���ʯ�������ζ���С�㡣
СϪ����Ŀյ�����һ�������С¥��
LONG );
	set("exits", ([
		"west" : __DIR__"xiaolu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1870);
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
			me->move(__DIR__"xiaoxi1");
			message("vision", "ֻ����Ӱһ����" + me->name() +  "����Ծ�˹�����\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			message("vision", me->name()+"���������Ծȥ��ֻ������ͨ��һ����"+me->name()+"ˤ��Ϫ�У��Ǳ������˻�����\n",environment(me),({me}) );
			write( "�����������Ծȥ��ֻ������ͨ��һ������ˤ��Ϫ�У��Ǳ������˻�����\n");
                        me->receive_damage("qi",30);
                        return 1;
		}
	}
	return 0;
}

