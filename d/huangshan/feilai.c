// Room: /d/huangshan/feilai.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "����ʯ");
	set("long", @LONG
��ƽ̹��ɽ��֮�ϣ�ͻȻð��һ��ʯͷ���ƺ����˷���һ˵�����
ʵ�����Խ��͡�ʯ��⻬���������֡�����ʯ����Զ��ʯͷ���ϴ���ϸ��
����ҡ�β�ֹ��ʵ�����˷�����˼��
LONG
	);
	set("exits", ([ 
		"east"  : __DIR__"guangming",
		"north" : __DIR__"paiyun",
	]));
	set("item_desc", ([
		"����ʯ": "�����������һ�ƣ�push��\n",
		"stone" : "�����������һ�ƣ�push��\n"
	]) );
	set("outdoors", "huangshan");
	setup();
}
void init()
{
	add_action("do_push","push");
}
int do_push()
{
	object me = this_player();
	me->receive_damage("qi", 30);
	message_vision("$N�þ�ȫ�����������������Ʒ���ʯ������ʯ�ƺ����˻Σ�\n",me);
	return 1;
}
