// Room: /yangzhou/baiyipu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��Ұ�����");
	set("long",@LONG
��������ЩС�����������Կ��·������Եú�ӵ���������и��÷죬
����һС��������ġ�һ��������������һ���·���Ҫȥ��߸�������
�·�������С���ɵ��ڳ��е��·������٣�����ʽ����Ů����Ӧ�о��С�
�����������ڴ���ѡ���Լ�ϲ�����·��ˡ����ſڹ��Ÿ�(paizi)��
LONG );
	
	set("item_desc", ([
		"paizi" : "������ļ�̲�С����\n",
	]));	
	set("exits", ([
		"north" : __DIR__"dashixijie",
		"west"  :__DIR__"shenjiakufang",
	]));
	set("objects", ([
		__DIR__"npc/shenwanfu" : 1,
	]));
	set("coor/x", 55);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}