// Room: /yangzhou/caohexiaojie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�ݺ�С��");
	set("long",@LONG
��С�����������ݹ��õĸ�ǽ���࿪©������ǽ���Ż�����͸����
����©������ϡ�ɿ���ǽ���Ǹ�԰�ӡ������ǹٺӣ������������ٺӶ�
ֲ��С���򱱱ߴ���С�㳡ͨ�����ݵĸ�ѧ��������Ժ����������ͨ��
�ţ������ŹٺӶ԰���ʮ�ﳤ�֣��ϱ߶�Ϊ��լ��������ͨ���֡�
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"tongsijie",
		"east"      : __DIR__"tongsiqiao",
		"south"     : __DIR__"caohenanjie",
		"north"     : __DIR__"xiaosquare",
		"southwest" : __DIR__"wudao4",
	]));
	set("objects", ([
		__DIR__"npc/youke1" : 1,
		"/d/mingjiao/npc/fenggongying" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}
int valid_leave(object me, string dir)
{
	object obj;
	if (dir == "southwest") me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}
