// Room: /d/songshan/qimushi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "��ĸʯ");
	set("long", @LONG
������һ�����ɾ�ʯ�������ഫ������ˮʱҪ��ͨԯߧɽ������
�ܰ��ڲ�ֹ������Ϳɽ���ͷ�ʱ����ײ�ƣ�ʧ�����ӣ����˻�ʯ����ʱ
Ϳɽ�������У�����׷�����ӣ���ʯ����һ�ڣ�����������ء���ʯ��
�˻�����ĸʯ��
LONG );
	set("exits", ([
		"southeast" : __DIR__"shandao1",
		"west"      : __DIR__"qimuque",
		"northup"   : __DIR__"shandao2",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 750);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
