// Room: /d/lingxiao/jiugu.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
���ã��������ã���������Ԩ��ˤ��������Ȼˤ������ѩ���ϣ�
����û�����ٸ첲����Ƥ��û�˵�һ�㡣���ǣ����������֮�£����
��ȥ�أ�����(pan)���أ�
LONG);
	set("outdoors", "lingxiao");
	set("exits", ([
	]));
	set("coor/x", -31000);
	set("coor/y", -8980);
	set("coor/z", 60);
	set("no_clean_up", 0);
	setup();
} 
void init()
{
	add_action("do_pan","pan");
}
int do_pan()
{
	object me = this_player();
	message("vision", me->name() + "�ֽŲ��ã�è������������\n", environment(me), ({me}) );
	me->move(__DIR__"shiya");
	message("vision", me->name() + "��ʯ����è��������������\n", environment(me), ({me}) );
	return 1;
}

