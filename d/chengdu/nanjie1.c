// Room: /d/chengdu/nanjie1.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�ϴ��");
	set("long", @LONG
�������ϣ�˫�˺ϱ��Ĵ����ڽֱ�ʮ��һ�꣬�������룬��ʯ�̾�
�Ľ����ɨ�øɸɾ�������û����ò�Ҫ����������Ϊ�����ǳɶ�
��������֡�����һ����¥����̻Իͣ�����ĿΪ֮ѣ���������������
��������һЩ��ӡ�
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"wang",
		"east"  : __DIR__"minju",
		"south" : __DIR__"nanjie2",
		"north" : __DIR__"guangchang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

