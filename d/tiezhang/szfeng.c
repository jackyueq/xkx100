// Room: /d/tiezhang/szfeng.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ʳָ��");
	set("long", @LONG
�����������˷嶥���Ѿ��۵����������ˡ�����ֻ������Բ�ĵ�
������ݲ������������ǹ�ͺͺ����ʯ���������š�һ�����Х������
������һ�����򣬲��ˤ�����������ǸϿ��뿪����ĺá�
LONG );
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1880);
	set("coor/z", 100);
	setup();
}
void init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object me=this_player();

	me->receive_damage("qi", 40);
	if ((int)me->query_skill("dodge",1)<100)
		me->improve_skill("dodge",me->query("int"));

	if (arg =="down") 
	{
		write("����Ե��ʯ�ڣ�����������ȥ��\n");
		message("vision",me->name() + "������ȥ��\n", environment(me), ({me}) );
		me->move(__DIR__"juebi5");
		message("vision",me->name() + "����������\n", environment(me), ({me}) );
	}
	else
		return notify_fail("��Ҫ����������\n");
	return 1;
}

