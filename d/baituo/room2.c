// Room: /d/baituo/room2.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","������");
	set("long", @LONG
�����ǰ���ɽ���ӵ������ҡ�������ͯ������������
LONG	);
	set("exits",([
		"out" : __DIR__"liangong",
	]));

	set("objects",([
		__DIR__"npc/tongzi" : 1,
	]));
	set_temp("full",0);
	set("coor/x", -49990);
	set("coor/y", 20040);
	set("coor/z", 30);
	setup();
}

void init()
{
	object ob=this_player();
	if((int)query_temp("full")==2)
	{
		message_vision("$Nһ���������Ѿ������ˣ�ֻ�����˳�ȥ��\n",ob);
		ob->move(__DIR__"liangong");
		return;
	}
	add_temp("full" ,1);
	return;
}

int valid_leave(object who, string dir)
{
	add_temp("full",-1);
	return 1;
}
