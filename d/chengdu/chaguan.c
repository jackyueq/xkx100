// Room: /d/chengdu/chaguan.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "½����");
	set("long", @LONG
�����ǳɶ��������Ĳ�¥���ɶ��Ĵ���Թ�ǳ�ϲ������һ���ط���
��Ϊ���ﻷ�����ʣ����������Ķ�����������������ˣ������������
һ��Ʒ����һ��ͬ����֮ʿ��̸���ۡ�һ¥��һ����Ǯ�˺Ȳ�ĵط���
��¥������Щ������������Ļ�����ʿ����ĵط���
LONG
	);
	set("resource/water", 1);
	set("exits", ([
		"east" : __DIR__"chunxilu1",
		"up" : __DIR__"chaguan2",
	]));
	set("objects", ([
		__DIR__"npc/boss" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


