// Room: /yangzhou/caiyidongjie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","���¶���");
	set("long",@LONG
һ����½֣������������Ϊ�α���Ϊ���̼���֯����ֻ�����½�
�����ٽֿ��꣬���Ҷ����²�����̡�������������в跻�Ƶꡣ����
��խ������ӵ����������̽���Ƶ��������Ů��������䣬�������̣�
�����Լ�ϲ�����²����һ��ҹ�������������������ҹ�������ƻ�
�����������˾������ǡ�������ʮ�����У�������ʣ������ɾ�����
LONG );
	set("outdoors", "yangzhoue");

	set("exits", ([
		"west"  : __DIR__"caiyixijie",
		"east"  : __DIR__"xianguopu",
		"north" : __DIR__"sixiepu",
		"south" : __DIR__"dashidongjie",
	]));
	set("no_clean_up", 0);
	set("coor/x", 60);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}