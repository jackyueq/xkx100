// Room: /yangzhou/menting.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "��ͥ");
	set("long", @LONG
��ͥ������һ���ߴ��ĥש��¥������Ϸ�Ƕ�С�С����ɽ�ݡ�
����ש������봩����ӣ��������Ʊ�ȥ���Ⱦ����š�
LONG );
	set("outdoors", "yangzhouw");
	set("no_fight", 1);

	set("exits", ([
		"north" : __DIR__"chuanlang",
		"east"  : __DIR__"caohenanjie",
	]));
	set("objects", ([
		__DIR__"npc/jiading2" : 2,
	]));
	set("coor/x", -11);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	object ob;
	if ( dir == "north" && !me->query_temp("enter_yang") 
		&& objectp( ob = present ( "jia ding", environment( me )  ) )
		&& living(ob) )
	{
		message_vision("�Ҷ���$N˵����δ����ү���룬�㲻�ܽ�ȥ��\n",me);
		return notify_fail("�㱻�Ҷ���ס��ȥ·��\n");
	}
	return ::valid_leave(me, dir);
}