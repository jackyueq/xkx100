// Room: /d/chengdu/guangchang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "�츮�㳡");
	set("long", @LONG
�����ǳɶ������ģ�ռ��Լ��Ķ����ɫ�Ĳ�ƺ����һ���ĵ�̺��
��������һ���������������ϰ����ˣ��������ǣ���֪���ɶ�����ʷ��
�൱�ƾõġ������������˺ܶ࣬����������Ħ����࣬���ο͡�����
�ˡ����ˡ�С�������ˣ����ֺ�ߺ���������ڶ�����һ�����ַ����ľ�
��
LONG	);
	set("exits", ([
		"west"  : __DIR__"xijie2",
		"east"  : __DIR__"dongjie1",		
		"north" : __DIR__"beijie2",
		"south" : __DIR__"nanjie1",
	]));
	set("outdoors","chengdu");
	set("objects", ([
		__DIR__"npc/xiaolanyan" : 3,
		__DIR__"npc/laolanyan" : 1,
	]));
	set("coor/x", -8050);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

 
