// Room: /yangzhou/caohebeijie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","�ݺӱ���");
	set("long",@LONG
���ǲݺ�С�ֵľ�ͷ�ˣ����߾����������ˡ����������ݸ��ĸ�ѧ
��������Ժ�����������ǿ��Ǹ���������ϡ�٣�ֻ�м��������ҴҶ�
������ѧ���ſ��м�������ѧͯ����Ц���֣�����ž��Ľֵ����˼���
������������һ���䵱�У����ֻ��һЩ����������������ϱ���һ
��С�㳡��
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"      : __DIR__"zizheng",
		"east"      : __DIR__"hongqiao",
		"south"     : __DIR__"xiaosquare",
		"north"     : __DIR__"diandanghang",
		"northwest" : __DIR__"kuixingge",
		"southwest" : __DIR__"petroom",
	]));
	set("objects", ([
		__DIR__"npc/qiuxingxing" : 1,
		__DIR__"npc/yangleishi" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
