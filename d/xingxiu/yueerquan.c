// Room: /d/xingxiu/yueerquan.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "�¶�Ȫ");
	set("long", @LONG
�����������֮�⣬�ں��ɳĮ�о�Ȼ�е�Ȫˮ��һ���峺��Ȫˮ
�γ�һ����������״����������¶�Ȫ�������ӻأ�ˮ�ݴ������峺��
�ס�������������㡢���ǲݣ�������������Ȫ������ɳɽȺ�У�����
ɳ�ɣ�����Ȫ�������Ӳ�����Ȫ�ڡ�������һƬ�ͱ�(cliff) �����ߴ�
�����˵����졣
LONG );
	set("outdoors", "qilian");
	set("resource/water", 1);
	set("exits", ([
		"southup" : __DIR__"shashan",
		"east"    : "/d/qilian/loulan",
	]));
	set("item_desc", ([
		"cliff" : "�ͱ����ƺ���һ����(hole)��\n"
	]) );
	set("no_clean_up", 0);
	set("coor/x", -20310);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="hole" )
	{
		if(me->query_encumbrance()*100/me->query_max_encumbrance()< 20)
		{
			message("vision", me->name() + "һ����Ծ���˶��\n", environment(me), ({me}) );
			me->move("/d/xingxiu/mogaoku");
			message("vision", me->name() + "�Ӷ������˽�����\n", environment(me), ({me}) );
			return 1;
		}
		else
		{
			write("�����ϱ��Ķ���̫�أ�������̫�ߣ��㹻���š�\n");
			return 1;
		}
	}
}
