// Room: /city/qinshi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��������ڣ���װһ��͸�յ��ָ���ǽ���ټ������Ϸ����辰��
���಼��һʽ�񻨺�÷������Χ���ŵʡ��ϣ�����������ǽ�ڣ����ź�
ľ�񻨼��������Դɵʡ�һ��������һ����Ⱦ������ǰ������һ�ܣ���
ˮ��������������������ˮ�ʣ�ˮ��΢������Ӱҡҷ��
LONG );
	set("exits", ([
		"southeast" : __DIR__"luqiao",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -25);
	set("coor/y", 5);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

