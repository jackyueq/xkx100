// Room: /d/gaochang/dadian.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "�߲����");
	set("long", @LONG
������Ǵ�˵��������������ظ߲��Թ��Ĵ��ıڹ��Ķ�����
��ľ��ķ��񡣴��֮����һ���������Σ�����֮��͸��һ�����ϣ�
��һ����ң����飺

                ****************
                *              * 
                *   �ĳ����   *
                *              *
                ****************

�������涼�ǵ��á�
LONG
	);
	set("exits", ([
		"west" : __DIR__"wroom1",
		"east" : __DIR__"eroom1", 
	]));
	set("no_clean_up", 0);
	set("coor/x", -36500);
	set("coor/y", 10050);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}