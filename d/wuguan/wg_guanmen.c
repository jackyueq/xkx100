// Last Modified by Sir on 9/17/2001
// wg_guanmen.c

inherit ROOM;

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
������һ����լ�ӣ��ſڸ���һ�����ҡ�������ݡ�����������ʯ
ʨ����Ӵ��ſ��ƽ�ȥ�����������������������ܷ�æ�����ӣ��ſ�վ
�������������������ϡ�
LONG);
	set("exits", ([
		"enter" : __DIR__"wg_dayuan",
		"west" : "/d/city/shilijie7",
	]));	
	set("objects", ([
		__DIR__"npc/wg_menwei" : 2,
	]));
	set("coor/x", 11);
	set("outdoors", "wuguan");
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "west" )
	{
		if(me->query("combat_exp") > 50000)
		{
			if(present("men wei", environment(me)) &&
				living(present("men wei", environment(me))))
			{
				return notify_fail("��������ȵ�������ֻ�����������֣���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
			}
			else return ::valid_leave(me, dir);
		}
		else return ::valid_leave(me, dir);		
	}
	else return ::valid_leave(me, dir);
}

