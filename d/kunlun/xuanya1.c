// Room: /d/kunlun/xuanya1.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������У���ߵ�ɽ��ʮ�����գ�ֱ���˰��ʱ������ǰ���޳�
·�ˡ��㲻�����º�̾�������Ĵ������á�
LONG	);
	set("no_clean_up", 0);
	set("exits",([
	]));
	set("outdoors", "hongmei");
	set("coor/x", -100040);
	set("coor/y", 20010);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_pa","pa");
}
int do_pa(string arg)
{
	object me;
	me=this_player();
	if (!(arg||arg=="east"||arg=="west")) return 0;
	if (arg=="east")
	{
		message("vision",me->name()+"�������������ȥ��\n",environment(me),me);
		write("���������������ȥ��\n");
		me->move(__DIR__"songshu");
		message("vision",me->name()+"С�������������������\n",environment(me),me);
		return 1;
	}
	return 1;
}
