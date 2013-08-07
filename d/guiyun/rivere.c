// Room: /d/guiyun/rivere.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

int do_jump(string arg);

void create()
{
	set("short", "С�Ӷ���");
	set("long", @LONG
������һ��С��֮�������¶����ҷء�����Χ��ȥ��������������
����(he)��
LONG );
	set("exits", ([
		"east" : __DIR__"road1",
	]));
	set("item_desc", ([
		"river" : "С�Ӻܿ���ˮ��������ԼԼ��ʲô�������㿴���塣\n",
		"he"    : "С�Ӻܿ���ˮ��������ԼԼ��ʲô�������㿴���塣\n",
	]) );
  	set("outdoors", "guiyun");
	setup();
}

void init()
{
	if (!present("old man", this_object()))
		new(__DIR__"npc/qianzhang")->move(this_object());
	add_action("do_jump", "jump");
	add_action("do_jump", "yue");
}

int do_jump(string arg)
{
	object me = this_player();

	if (arg == "river" || arg == "he")
	{
		if (me->query_temp("guiyun_river") )
		{
			message("vision", me->name() + "����Ծ��ˮ�棬������������ˮֻ��С�ȣ�һ�����߹��˺ӡ�\n", environment(me), ({me}) );
			write("�����ˮ�׵İ�׮���������߹���С�ӡ�\n");
			me->move(__DIR__"riverw");
			message("vision", "ֻ����������Ӱ������" + me->name() +  "��Ʈ��ˮ��һ�㣬ֱ�߹�����\n", environment(me), ({me}) );
			write("����Ű�׮�������߹���С�ӡ�\n");
			me->delete_temp("guiyun_river");
			return 1;
		}
		else {
			write("�������ԣ���������ܿ������������ȥ��\n");
			return 1;
		}
	}
	return 0;
}
