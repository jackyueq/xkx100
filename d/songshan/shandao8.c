// Room: /d/songshan/shandao8.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
��������ɽ����ɽ�������ɴ�أ�ɽ�����ʱ��Ʈ����Զ��ɽ��
Ȯ�ͼ��䣬�����ɷ�֮�С����Ͼ��Ƿ���̨�ˡ�
LONG );
	set("exits", ([
		"eastdown" : __DIR__"shandao7",
		"westup"   : __DIR__"fengchantai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "songshan");
	set("coor/x", -26);
	set("coor/y", 850);
	set("coor/z", 86);
	setup();
	replace_program(ROOM);
}
