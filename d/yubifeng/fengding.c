// /yubifeng/fengding.c
// Last modified by winder 2003.9.2

int do_enter(string arg);

inherit ROOM;

void create()
{
	set("short", "��ʷ�");
	set("long", @long
ֻ��ɽ���Ժô��������̣���������ǣ�������̻��ʣ�����������
��Ҫ���µ��˵ȣ�ֻ��������(basket)�����¡�
long );
	set("exits", ([
		"east" : __DIR__"damen",
	]));
	set("item_desc", ([
		"basket" : "����һ��������������װ����ɽ�ġ�\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5170);
	set("coor/z", 100);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
	add_action("do_enter", "jin");
}

int do_enter(string arg)
{
	object me = this_player();

	if( arg != "basket")
		return notify_fail("��Ҫ�������ꣿ\n");
	message_vision("$N�������������ֻ����ಡ���һ��������ת�������������ٷ�����ȥ��\n\n....\n\nֻ����ǰ��ѩҫ�ۣ����Ʒɶ�\n\n....\n\n", me);
	me->move(__DIR__"fengdi");
	return 1;
}
