// Room: /d/tiezhang/juebi4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ͻͻ��ʯ�ڡ���ֻ�������Ժ����ķ�����
LONG	);
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2010);
	set("coor/y", -1880);
	set("coor/z", 80);
	setup();
}
void init()
{
	add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me;
	me=this_player();

	me->receive_damage("qi", 40);
	if ((int)me->query_skill("dodge",1)>100)
		write("����ú��Ѵ��������Ṧ����\n");
	if ((int)me->query_skill("dodge",1)<100)
		me->improve_skill("dodge",me->query("int"));
	if ( (arg !="up") && (arg !="down") ) 
		return notify_fail("��Ҫ���Ķ�����\n");
	if (arg =="up")  
	{
		write("�����˿�����С�ĵ�������ȥ��\n");
		message("vision",me->name() + "����һ��ͻȻ�����ˡ�\n", environment(me), ({me}) );
		me->move(__DIR__"juebi5");
		message("vision",me->name() + "����������\n", environment(me), ({me}) );
		return 1;
	}
	if (arg =="down")
	{
		write("����Ե��ʯ�ڣ�����������ȥ��\n");
		message("vision",me->name() + "������ȥ��\n", environment(me), ({me}) );
		me->move(__DIR__"juebi3");
		message("vision",me->name() + "����������\n", environment(me), ({me}) );
	}
	return 1;
}

