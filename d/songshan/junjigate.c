// Room: /d/songshan/junjigate.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
��ɽ�������ųơ���������������һ������Ժ�����Ƿ�̴��£���
������ȴ�ѳ�Ϊ��ɽ�������˵�ס���������Ǿ�����Ժɽ�ţ�����ɽ·
���Ե������̨��
LONG );
	set("exits", ([
		"southdown" : __DIR__"shandao6",
		"northup"   : __DIR__"qianting",
		"westup"    : __DIR__"shandao7",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/first" : 1,
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 850);
	set("coor/z", 80);
	setup();
	replace_program(ROOM);
}
