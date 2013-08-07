// Room: /d/kunlun/pubu.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;
void create()
{
	set("short", "�ٲ�");
	set("long", @LONG
�������˶���ֻ࣬���ͱ�����һ�����ٲ�������£�������ѩ��
���ɣ���������������һ��������������׳�����ٲ�й��һ���峺����
����̶(tan )֮�У�̶ˮȴҲ����������������йˮ��ȥ·���������
���Σ�һ��ͷ����������Ⱦ������̦���࣬��������������Ӳ�ݸ��Ƶ�
Ѫ�ۣ�����߽�̶�ߣ�����Ь�࣬���㵽̶ˮ��ȥϴ��(xidi)��
LONG );
	set("outdoors", "hongmei");
	set("exits", ([
		"east" : __DIR__"cuigu",
	]));
	set("no_clean_up", 0);
	set("fish_count",2);
	set("item_desc", ([
		"tan": "�㸽��̶�ߣ�������ȥ��ֻ�����̵�ˮ��ʮ��������������ζ���\n",
	]));
	set("coor/x", -100020);
	set("coor/y", 20050);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_xidi", "xidi");
}
int do_xidi()
{
	object fish, me = this_player();
	if ((this_player()->query_dex()<25) || query("fish_count")<=0)
		message_vision("$Nϴ��һ�ᣬͻȻ����һ����̶������һβ����㣬����һ�߶�\n����$Næ����ȥץ����Ȼ����������ȴһ�������ˡ�\n", me);
	else
	{
		message_vision("$Nϴ��һ�ᣬͻȻ����һ����̶������һβ����㣬����һ�߶�\n����$Næ����ȥץ��һ�Ѱ���߬�����ġ�\n", me);
		add("fish_count",-1);
	}
	fish = new(__DIR__"obj/fish");
	fish -> move(me);
	return 1;
}

