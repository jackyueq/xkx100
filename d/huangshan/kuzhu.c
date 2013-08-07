// Room: /d/huangshan/kuzhu.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����Ϫ");
	set("long", @LONG
��;ʢ����������ϪˮҲ�е�����ɬζ��������ҩ��ڣ������
����ҩ����Ʒ����������֮����Ȼ������Ȫ�����ڽⷦ�����а�����
�������ص�����ȡ�����ҩ�����Ǳ���ɽ���ڴ˷�������
LONG
	);
	set("exits", ([ 
		"westup" : __DIR__"jiulong",
	]));
	set("objects", ([
		__DIR__"npc/snake" : 2,
	]) );
	set("item_desc", ([
		"����Ϫ": "��������Ŵ�Ϫ��xi���кȣ�drink��һ�ڡ�\n",
		"kuzhuxi": "��������Ŵ�Ϫ��xi���кȣ�drink��һ�ڡ�\n"
	]) );
	set("outdoors", "huangshan");
	setup();
}
init()
{
	add_action("do_drink","drink");
	add_action("do_climb","climb");
}
int do_drink(string arg)
{
	object me = this_player();

	if(!arg || arg != "xi") return 0;
	if(me->query("water") >= me->max_water_capacity())
		return notify_fail("���ƺ������ʡ�\n");
	message_vision("$N���������ڿ���Ϫ�к���һ��ڿ�ˮ��\n",me);
	me->add("water",50);
	return 1;
}

int do_climb(string arg)
{
	object 	me;
	int mlvl;

	if(!arg || arg != "up")
	{
		write("��Ҫ����������\n");
		return 1;
	}
	me = this_player();
	message_vision("\n$N������������ȥ��\n",me);
	me->start_busy(4);
	call_out("fliping",4,me);
	me->stop_busy();
	return 1;
}

int fliping(object me)
{
	if( !me->is_ghost())
	{
		me->move(__DIR__"huangshan");
		message_vision("$N˳���±�����������\n", me);
	}
	return 1;
}
