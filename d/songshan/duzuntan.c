// Room: /d/songshan/duzuntan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����̳");
	set("long", @LONG
�����Ƕ���̳������������̩ɽ�ųơ����𡱣����Դ�ʮ����ǰ��
ɽ�ɶ����������һϯ�󣬽�������������ĵ�λ������ɽ���ˡ�����
���л��󣬵���������Ҳ��ʵ���˲���������
LONG );
	set("exits", ([
		"south" : __DIR__"houting",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/deng": 1,
	]));
	set("coor/x", -20);
	set("coor/y", 940);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
