// Room: xiuxishi.c
// Last Modified by winder on Aug. 1 2002

inherit RESTROOM_IN;

void create()
{
	set("short", "��ɽС��");
	set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG );

	set("sleep_room", 1);
	set("no_clean_up", 0);
	set("no_fight", 1);

	set("coor/x", -830);
	set("coor/y", 210);
	set("coor/z", 120);
  set("door_name","����");
	set("door_dir","west");
	set("force_name","½����");
  set("outroom",__DIR__"xiaolu2");
	setup();
}

void init()
{
  object me = this_player();
  ::init();
	if (me->query_temp("xunshan")) me->set_temp("xunshan/yunu", 1);
}

