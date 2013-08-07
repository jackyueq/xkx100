// Room: /d/huangshan/huangshan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	object con,item;
	set("short", "��ɽ��®");
	set("long", @LONG
�ò����׹���������ǰһ������Ȼ�м�é�ݣ����Ͼ�ȻҲ��������
�顰��ɽ��®�������ڳ���򵥣�һ�ź�ľ���Ϸ��ż��ᾭ����Ͳ��
ϡ��ز��ż�ֻ�Ǻ�����ǽһ�����������顰��񷡱���֡�
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"tiesuo",
	]));
	set("no_clean_up", 0);
	setup();
}
init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object 	me;
	int mlvl;

	if(!arg || arg != "down")
	{
		write("��Ҫ����������\n");
		return 1;
	}
	me = this_player();
	message_vision( "\n$N������������ȥ��\n" , me);
	me->start_busy(4);
	call_out("fliping",4,me);
	me->stop_busy();
	return 1;
}

int fliping(object me)
{
	if( !me->is_ghost())
	{
		me->move(__DIR__"kuzhu");
		message_vision("$N˳���±�����������\n", me);
	}
	return 1;
}
